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

void MainWindow::receiveKeyword(QString keyword)
{
    initVariable();
    findAllKeyword(keyword);

}

void MainWindow::receiveNextButtonSignal(QString keyword)
{
    findKeywordSequence(keyword);
}

void MainWindow::receiveDialogEndSignal()
{

    ui->textEdit->clear();

    QTextCharFormat fmt;
    fmt.setBackground(QBrush(Qt::white));

    ui->textEdit->mergeCurrentCharFormat(fmt);

    printHexFileInTableWidget();
    printFileInformationInLabel();

    printFileHeaderInTextEdit();
    printCommonHeaderInTextEdit();
    printBlockHeaderInTextEdit();
}

void MainWindow::on_openButton_clicked()
{
    // ASCII : value name / Hex : value name.toHex()
    // Print File information.

    initVariable();

    if(Obj.readPatFile()){
    ui->textEdit->clear();
    printHexFileInTableWidget();
    printFileInformationInLabel();

    printFileHeaderInTextEdit();
    printCommonHeaderInTextEdit();
    printBlockHeaderInTextEdit();
   }
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

    ui->informationLabel->setText("");

}

void MainWindow::on_modifyFindButton_clicked()
{

    FindDialog *dialog =new FindDialog(this);

    dialog->show();

    dialog->raise();

    dialog->activateWindow();

}

