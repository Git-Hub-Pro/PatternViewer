#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    // ASCII : value name / Hex : value name.toHex()
    // Print File information.
    Obj.readPatFile();

    initVariable();

    printHexFileInTableWidget();
    printFileInformationInLabel();

    printFileHeaderInTextEdit();
    printCommonHeaderInTextEdit();

}

void MainWindow::initVariable()
{
    _found = false;
}

void MainWindow::on_clearButton_clicked()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    ui->textEdit->clear();
}

void MainWindow::on_findButton_clicked()
{
    initVariable();
    findAllKeyword();
}

void MainWindow::on_nextButton_clicked()
{
    findKeywordSequence();
}
