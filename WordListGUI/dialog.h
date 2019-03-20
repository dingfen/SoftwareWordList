#ifndef DIALOG_H
#define DIALOG_H

#include "WordGraph.h"
#include "QMessageBox"
#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(WordGraph *wordGraph, QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void load();

private:
    Ui::Dialog *ui;
    WordGraph *wordGraph;
};

#endif // DIALOG_H
