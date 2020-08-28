#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::printHexFileInTableWidget()
{
    QByteArray fileData = Obj.readAll();

    int column = 10;

    int row = fileData.size()/column;

     ui->tableWidget->setRowCount(row);
     ui->tableWidget->setColumnCount(column);

    int cnt = 0;

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
           QTableWidgetItem *item = ui->tableWidget->item(i,j);
           if(!item){
               item = new QTableWidgetItem();
               ui->tableWidget->setItem(i,j,item);
           }

           QByteArray hexDataOne;
           hexDataOne.append(fileData.at(i*column+j));
           item->setText(hexDataOne.toHex());
           cnt++;

           if(cnt==fileData.size()){
               break;
           }

        }
    }
}

void MainWindow::printFileHeaderInTextEdit()
{
    ui->textEdit->setPlainText("1. FileHeaderDiscemmentCode : ");
    ui->textEdit->append(Obj.readFileHeaderDiscemmentCode().toHex());
    ui->textEdit->append("2. FileHeaderSourceFileName : ");
    ui->textEdit->append(Obj.readFileHeaderSourceFileName());
    ui->textEdit->append("3. FileHeaderCompileDate : ");
    ui->textEdit->append(Obj.readFileHeaderCompileDate());
    ui->textEdit->append("4. FileHeaderCompileTime : ");
    ui->textEdit->append(Obj.readFileHeaderCompileTime());
    ui->textEdit->append("5. FileHeaderCompilerVersion : ");
    ui->textEdit->append(Obj.readFileHeaderCompilerVersion());
    ui->textEdit->append("6. FileHeaderFlagCommonModuleExist : ");
    ui->textEdit->append(Obj.readFileHeaderFlagCommonModuleExist().toHex());
    ui->textEdit->append("7. FileHeaderCountOfBlock : ");
    ui->textEdit->append(Obj.readFileHeaderCountOfBlock().toHex());
    ui->textEdit->append("8. FileHeaderOffsetsOfCommon : ");
    ui->textEdit->append(Obj.readFileHeaderCountOfBlock().toHex());
    ui->textEdit->append("9. FileHeaderOffsetsOfBlocks : ");
    ui->textEdit->append(Obj. readFileHeaderOffsetsOfBlocks().toHex());
    ui->textEdit->append("10. FileHeaderStartAddressArray: ");
    ui->textEdit->append(Obj. readFileHeaderStartAddressArray().toHex());
    ui->textEdit->append("11. FileHeaderRemark : ");
    ui->textEdit->append(Obj. readFileHeaderRemark());
    ui->textEdit->append("12. FileHeaderDataOfIlMode : ");
    ui->textEdit->append(Obj. readFileHeaderDataOfIlMode().toHex());
    ui->textEdit->append("13. FileHeaderReserved : ");
    ui->textEdit->append(Obj. readFileHeaderReserved().toHex());
}

void MainWindow::printCommonHeaderInTextEdit()
{
    ui->textEdit->append("14. readCommonHeaderOpcodeNDataSet32_r : ");
    ui->textEdit->append(Obj.readCommonHeaderOpcodeNDataSet32_r().toHex());
    ui->textEdit->append("15. readCommonHeaderOpcodeNDataSet64_s : ");
    ui->textEdit->append(Obj.readCommonHeaderOpcodeNDataSet64_s().toHex());
    ui->textEdit->append("16. readCommonHeaderReserved : ");
    ui->textEdit->append(Obj.readCommonHeaderReserved().toHex());
}

void MainWindow::printBlockHeaderInTextEdit()
{
    ui->textEdit->append("17. readBlock1StartAddress : ");
    ui->textEdit->append(Obj.readBlock1StartAddress().toHex());
    ui->textEdit->append("18. readBlock1HeaderOpcodeNDataSet32_r : ");
    ui->textEdit->append(Obj.readBlock1HeaderOpcodeNDataSet32_r().toHex());
    ui->textEdit->append("19. readBlock1HeaderOpcodeNDataSet64_s : ");
    ui->textEdit->append(Obj.readBlock1HeaderOpcodeNDataSet64_s().toHex());
    ui->textEdit->append("20. readBlock1HeaderMicroPatternCount : ");
    ui->textEdit->append(Obj.readBlock1HeaderMicroPatternCount().toHex());
    ui->textEdit->append("21. readBlock1HeaderReaserverd : ");
    ui->textEdit->append(Obj.readBlock1HeaderReaserverd().toHex());

}

