#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "file.h"
#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QLabel>
#include <QStandardItem>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCursor>
#include <QTextCharFormat>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();
    void on_clearButton_clicked();
    void on_findButton_clicked();


    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;

public:
    void printFileInformationInLabel();
    void printHexFileInTableWidget();

    void printFileHeaderInTextEdit();
    void printCommonHeaderInTextEdit();

    void initVariable();

    void findAllKeyword();
    void findKeywordSequence();

private:
    File Obj;
    bool found;
    bool isFirstTime;
    int count;

};

#endif // MAINWINDOW_H
