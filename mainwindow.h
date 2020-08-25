#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "file.h"
#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QLabel>
#include <QStandardItem>


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

private:
    Ui::MainWindow *ui;

public:
    void printFileInformationInLabel();

private:
    File Obj;

};

#endif // MAINWINDOW_H
