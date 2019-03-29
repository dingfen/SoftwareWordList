#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //menu bar
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

    //button
    QButtonGroup *buttons[2];buttons[0] = new QButtonGroup(this);
    buttons[1] = new QButtonGroup(this);
    buttons[1]->setExclusive(false);
    buttons[0]->addButton(ui->checkBox_w);
    buttons[0]->addButton(ui->checkBox_c);
    buttons[1]->addButton(ui->checkBox_h);
    buttons[1]->addButton(ui->checkBox_t);
    buttons[1]->addButton(ui->checkBox_n);

    QObject::connect(ui->storeButton, SIGNAL(clicked()), this, SLOT(store()));
    QObject::connect(ui->startButton, SIGNAL(clicked()), this, SLOT(start()));

    //text edit
    ui->plainTextEdit_h->hide();
    ui->plainTextEdit_n->hide();
    ui->plainTextEdit_t->hide();
    QObject::connect(buttons[1], SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(hideTextEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//从文件导入
void MainWindow::loadFromFile()
{
    if (!wordGraph->isNull())
    {
        QMessageBox::critical(this, "导入错误", "不允许重复导入!");
        return;
    }

    QString fileName = QFileDialog::getOpenFileName(this, "导入", "/", "*");
    if (fileName == "")
        return;

    wordGraph->create(fileName.toStdString());
    if (wordGraph->isNull())
    {
        QMessageBox::critical(this, "导入错误", "文件中不含单词!");
    }
    else
    {
        QMessageBox::information(this, "导入成功", "文件导入成功！");
    }
}

//手动输入
void MainWindow::loadFromKB()
{
    Dialog *dialog = new Dialog(wordGraph, this);
    dialog->show();
}

//结果导出到文件
void MainWindow::store()
{
    QString text = ui->plainTextEdit->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this, "导出", "/home", "*.*");
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(text.toUtf8());
    file.close();
    QMessageBox::information(this, "导出成功", "结果导出成功！");
}

//开始处理
void MainWindow::start()
{
    if (wordGraph->isNull())
    {
        QMessageBox::critical(this, "导入错误", "未导入或导入出错!");
        return;
    }

    //指定首尾字母
    char head = '\0', tail = '\0';
    if (ui->checkBox_h->isChecked())
    {
        head = ui->plainTextEdit_h->toPlainText().toLower().toStdString()[0];
        if (!isalpha(head))
        {
            QMessageBox::critical(this, "参数错误", "h的参数必须为字母!");
            return;
        }
    }
    if (ui->checkBox_t->isChecked())
    {
        tail = ui->plainTextEdit_t->toPlainText().toStdString()[0];
        if (!isalpha(tail))
        {
            QMessageBox::critical(this, "参数错误", "t的参数必须为字母!");
            return;
        }
    }

    //指定单词数
    int num = -1;
    if (ui->checkBox_n->isChecked())
    {
        num = ui->plainTextEdit_n->toPlainText().toInt();
        if (num <= 0)
        {
            QMessageBox::critical(this, "参数错误", "n的参数必须为正数!");
            return;
        }
    }

    //搜索
    std::vector<std::string> ret;
    if (ui->checkBox_w->isChecked())
        ret = wordGraph->wordDFS(head, tail, num);
    else if (ui->checkBox_c->isChecked())
        ret = wordGraph->alphaDFS(head, tail, num);
    else
    {
        QMessageBox::critical(this, "选项错误", "必须选择一种模式!");
        return;
    }

    //输出
    ui->plainTextEdit->clear();
    if (num == -1)//无 -n
    {
        for(auto str : ret)
            ui->plainTextEdit->appendPlainText(QString::fromStdString(str));
    }
    else
    {
        for (auto vec : wordGraph->getList())
        {
            for (auto str : vec)
                ui->plainTextEdit->appendPlainText(QString::fromStdString(str));
            ui->plainTextEdit->appendPlainText(QString("\n"));
        }
    }
}

void MainWindow::hideTextEdit()
{
    if (ui->checkBox_h->isChecked())
        ui->plainTextEdit_h->show();
    else
    {
        ui->plainTextEdit_h->clear();
        ui->plainTextEdit_h->hide();
    }

    if (ui->checkBox_n->isChecked())
        ui->plainTextEdit_n->show();
    else
    {
        ui->plainTextEdit_n->clear();
        ui->plainTextEdit_n->hide();
    }

    if (ui->checkBox_t->isChecked())
        ui->plainTextEdit_t->show();
    else
    {
        ui->plainTextEdit_t->clear();
        ui->plainTextEdit_t->hide();
    }
}
