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
    printFileHeaderDiscemmentCode();
    printFileHeaderSourceFileName();
    printFileHeaderCompileDate();
    printFileHeaderCompileTime();
    printFileHeaderCompilerVersion();

    printFileHeaderFlagCommonModuleExist();
    printFileHeaderCountOfBlock();
    printFileHeaderOffsetsOfCommon();
    printFileHeaderOffsetsOfBlocks();
    printFileHeaderRemark();
    printFileHeaderDataOfIlMode();
    printFileHeaderReserved();

}

void MainWindow::printCommonHeaderInTextEdit()
{
    printCommonHeaderOpcodeNDataSet32_r();
    printCommonHeaderOpcodeNDataSet64_s();
    printCommonHeaderReserved();
}

void MainWindow::printBlockHeaderInTextEdit()
{
    printBlock1StartAddress();
    printBlock1HeaderOpcodeNDataSet32_r();
    printBlock1HeaderOpcodeNDataSet64_s();
    printBlock1HeaderMicroPatternCount();
    printBlock1HeaderReaserverd();
}

void MainWindow::printFileHeaderDiscemmentCode()
{
    ui->textEdit->insertPlainText("1. FileHeaderDiscemmentCode : ");

    QByteArray data = Obj.readFileHeaderDiscemmentCode().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderSourceFileName()
{
    ui->textEdit->insertPlainText("\n2. FileHeaderSourceFileName : \n");
    ui->textEdit->insertPlainText(Obj.readFileHeaderSourceFileName());
}

void MainWindow::printFileHeaderCompileDate()
{
    ui->textEdit->insertPlainText("\n3. FileHeaderCompileDate : \n");
    ui->textEdit->insertPlainText(Obj.readFileHeaderCompileDate());
}

void MainWindow::printFileHeaderCompileTime()
{
    ui->textEdit->insertPlainText("\n4. FileHeaderCompileTime : \n");
    ui->textEdit->insertPlainText(Obj.readFileHeaderCompileTime());
}

void MainWindow::printFileHeaderCompilerVersion()
{
    ui->textEdit->insertPlainText("\n5. FileHeaderCompilerVersion : \n");
    ui->textEdit->insertPlainText(Obj.readFileHeaderCompilerVersion());
}

void MainWindow::printFileHeaderFlagCommonModuleExist()
{
    ui->textEdit->insertPlainText("\n6. FileHeaderFlagCommonModuleExist : ");

    QByteArray data = Obj.readFileHeaderFlagCommonModuleExist().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderCountOfBlock()
{
    ui->textEdit->insertPlainText("\n7. FileHeaderCountOfBlock :");

    QByteArray data = Obj.readFileHeaderCountOfBlock().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderOffsetsOfCommon()
{
    ui->textEdit->insertPlainText("\n8. FileHeaderOffsetsOfCommon :");

    QByteArray data = Obj.readFileHeaderCountOfBlock().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderOffsetsOfBlocks()
{
    ui->textEdit->insertPlainText("\n9. FileHeaderOffsetsOfBlocks :");

    QByteArray data = Obj. readFileHeaderOffsetsOfBlocks().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%100==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderStartAddressArray()
{
    ui->textEdit->insertPlainText("\n10. FileHeaderStartAddressArray:");

    QByteArray data = Obj. readFileHeaderStartAddressArray().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%64==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderRemark()
{
    ui->textEdit->append("11. FileHeaderRemark : ");
    ui->textEdit->append(Obj. readFileHeaderRemark());
}

void MainWindow::printFileHeaderDataOfIlMode()
{
    ui->textEdit->insertPlainText("\n12. FileHeaderDataOfIlMode : ");

    QByteArray data = Obj. readFileHeaderDataOfIlMode().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printFileHeaderReserved()
{
    ui->textEdit->insertPlainText("\n13. FileHeaderReserved : ");

    QByteArray data = Obj. readFileHeaderReserved().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printCommonHeaderOpcodeNDataSet32_r()
{
    ui->textEdit->insertPlainText("\n14. CommonHeaderOpcodeNDataSet32_r : ");

    QByteArray data = Obj. readCommonHeaderOpcodeNDataSet32_r().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printCommonHeaderOpcodeNDataSet64_s()
{
    ui->textEdit->insertPlainText("\n15. CommonHeaderOpcodeNDataSet64_s : ");

    QByteArray data = Obj. readCommonHeaderOpcodeNDataSet64_s().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printCommonHeaderReserved()
{
    ui->textEdit->insertPlainText("\n16. CommonHeaderReserved : ");

    QByteArray data = Obj. readCommonHeaderReserved().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printBlock1StartAddress()
{
    ui->textEdit->insertPlainText("\n17. Block1StartAddress : ");

    QByteArray data = Obj. readBlock1StartAddress().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printBlock1HeaderOpcodeNDataSet32_r()
{
    ui->textEdit->insertPlainText("\n18. Block1HeaderOpcodeNDataSet32_r : ");

    QByteArray data = Obj. readBlock1HeaderOpcodeNDataSet32_r().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printBlock1HeaderOpcodeNDataSet64_s()
{
    ui->textEdit->insertPlainText("\n19. Block1HeaderOpcodeNDataSet64_s : ");

    QByteArray data = Obj. readBlock1HeaderOpcodeNDataSet64_s().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printBlock1HeaderMicroPatternCount()
{
    ui->textEdit->insertPlainText("\n20. Block1HeaderMicroPatternCount : ");

    QByteArray data = Obj. readBlock1HeaderMicroPatternCount().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}

void MainWindow::printBlock1HeaderReaserverd()
{
    ui->textEdit->insertPlainText("\n21. Block1HeaderReaserverd : ");

    QByteArray data = Obj. readBlock1HeaderReaserverd().toHex();
    QByteArray dataTwo;


    for(int i=0;i<data.length();i++){
       dataTwo.append(data.at(i));

       if(i%16==0)
       ui->textEdit->append("");

       if(i!=0&&i%2==1){
          ui->textEdit->insertPlainText(dataTwo);
          ui->textEdit->insertPlainText(" ");
          dataTwo.clear();
       }
    }
}
