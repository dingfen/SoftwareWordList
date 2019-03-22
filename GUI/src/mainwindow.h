#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "WordGraph.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QButtonGroup>
#include <QFile>
#include <QCheckBox>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadFromFile();
    void loadFromKB();
    void store();
    void start();
    void hideTextEdit();

private:
    Ui::MainWindow *ui;
    WordGraph *wordGraph = new WordGraph;
};

#endif // MAINWINDOW_H
