#include "mainwindow.h"
#include "ui_mainwindow.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "导入", ".", "*.*");
    qDebug() << fileName;
}

void MainWindow::loadFromKB()
{
    QPlainTextEdit *text = new QPlainTextEdit();
    text->show();
}
