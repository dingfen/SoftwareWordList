#include "dialog.h"
#include "ui_dialog.h"
#include <QPlainTextEdit>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::accept()
{
    QPlainTextEdit *textEdit = ui->plainTextEdit;
    qDebug() << textEdit->toPlainText();
    close();
}
