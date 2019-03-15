#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar *menuBar = ui->menuBar;
    QMenu *loadMenu = new QMenu("导入");
    QAction *loadAct[2];

    loadAct[0] = new QAction("来自文件");
    loadAct[1] = new QAction("手动输入");

    loadMenu->addAction(loadAct[0]);
    loadMenu->addAction(loadAct[1]);
    menuBar->addMenu(loadMenu);

    QObject::connect(loadAct[0], SIGNAL(triggered(bool)), this, SLOT(loadFromFile()));
    QObject::connect(loadAct[1], SIGNAL(triggered(bool)), this, SLOT(loadFromKB()));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(store()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "导入", "/", "*.txt");
    qDebug() << fileName;
}

void MainWindow::loadFromKB()
{
    Dialog *dialog = new Dialog(this);
    dialog->show();
}

void MainWindow::store()
{
    QString text = ui->plainTextEdit->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this, "导出", "/home", "*.*");
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(text.toUtf8());
    file.close();
}
