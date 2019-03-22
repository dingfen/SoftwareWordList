#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(WordGraph *wordGraph, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->wordGraph = wordGraph;
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(load()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::load()
{
    wordGraph->create(ui->plainTextEdit->toPlainText());
    if (wordGraph->isNull())
    {
        QMessageBox::critical(this, "导入错误", "文件中不含单词!");
    }
    else
    {
        QMessageBox::information(this, "导入成功", "文件导入成功！");
    }
    close();
}
