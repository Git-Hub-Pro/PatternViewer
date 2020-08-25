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

    QByteArray fileData = Obj.readAll();


    int row = fileData.size()/10;
    int column = 10;

     ui->originTableWidget->setRowCount(row);
     ui->originTableWidget->setColumnCount(column);

    int cnt = 0;

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
           QTableWidgetItem *item = ui->originTableWidget->item(i,j);
           if(!item){
               item = new QTableWidgetItem();
               ui->originTableWidget->setItem(i,j,item);
           }

           QByteArray hexDataOne;
           hexDataOne.append(fileData.at(i+j));
           item->setText(hexDataOne.toHex());
           cnt++;

           if(cnt==fileData.size()){
               break;
           }

        }
    }

    printFileInformationInLabel();
}

void MainWindow::printFileInformationInLabel()
{
    QString informationFile;

    QByteArray fileData = Obj.readAll();

    informationFile.append("File Name : ");
    informationFile.append(Obj.readFileHeaderSourceFileName());
    informationFile.append("  File size : ");
    informationFile.append(QString::number(fileData.size()));
    informationFile.append("Byte");

    ui->informationLabel->setText(informationFile);
}


void MainWindow::on_clearButton_clicked()
{
    ui->originTableWidget->setRowCount(0);
    ui->originTableWidget->setColumnCount(0);
}
