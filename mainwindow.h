#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "file.h"
#include "finddialog.h"
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

    void receiveKeyword(QString keyword);
    void receiveNextButtonSignal(QString keyword);
    void receiveDialogEndSignal();

    void on_openButton_clicked();
    void on_clearButton_clicked();
    void on_modifyFindButton_clicked();

private:
    Ui::MainWindow *ui;

public:
    void printFileInformationInLabel();
    void printHexFileInTableWidget();

    void printFileHeaderInTextEdit();
    void printCommonHeaderInTextEdit();
    void printBlockHeaderInTextEdit();

    void initVariable();

    void findAllKeyword(QString keyword);
    void findKeywordSequence(QString keyword);

    void setCursorNum(int cursorNum){_cursorNum = cursorNum;}
    int  getCursorNum(){return _cursorNum;}

    void setCursorPosition(int cursorPosition){_cursorPosition = cursorPosition;}
    int  getCursorPosition(){return _cursorPosition;}


private:
    File Obj;
    bool _found;
    int _cursorNum;
    int _cursorPosition;
    int _count =0;

};

#endif // MAINWINDOW_H
