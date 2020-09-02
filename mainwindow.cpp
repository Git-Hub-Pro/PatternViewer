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


void MainWindow::receiveFileHeaderSize(FileHeaderSize fileHeader)
{
   qDebug()<<"FH:"<<fileHeader.getDiscemmentCodeSize()<<'\n';

}


void MainWindow::receiveCommonHeaderSize(CommonHeaderSize commonHeader)
{
    qDebug()<<"CH:"<<commonHeader.getDataSetRsize()<<'\n';

}


void MainWindow::receiveBlockHeaderSize(BlockHeaderSize blockHeader)
{
  qDebug()<<"BH:"<<blockHeader.getStartAddressSize()<<'\n';
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

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    if(index.isValid()){
        int row = index.row();
        int column = index.column();
        int isNum = row*10 + column + 1;

        QString informationFile;

        QByteArray fileData = Obj.readAll();

        informationFile.append("File Name : ");
        informationFile.append(Obj.readFileHeaderSourceFileName());
        informationFile.append("  File size : ");
        informationFile.append(QString::number(fileData.size()));
        informationFile.append("Byte ");

        informationFile.append("Position : ");
        informationFile.append(QString::number(isNum));
        informationFile.append("/");
        informationFile.append(QString::number(fileData.size()));

        ui->informationLabel->setText(informationFile);
    }

}

void MainWindow::on_settingButton_clicked()
{
    SettingDialog *dialog =new SettingDialog(this);
    dialog->exec();
}
