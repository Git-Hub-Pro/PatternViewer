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

    if(fileData.size() % column > 0)
        row += 1;


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
    ui->textEdit->insertPlainText("1. FileHeaderDiscemmentCode : \n");

    QByteArray data = Obj.readFileHeaderDiscemmentCode().toHex();
    QString str = (QString) data;
    QString line;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    line.clear();

}

void MainWindow::printFileHeaderSourceFileName()
{
    ui->textEdit->insertPlainText("\n2. FileHeaderSourceFileName : \n");
    ui->textEdit->insertPlainText((QString)Obj.readFileHeaderSourceFileName());
}

void MainWindow::printFileHeaderCompileDate()
{
    ui->textEdit->insertPlainText("\n3. FileHeaderCompileDate : \n");
    ui->textEdit->insertPlainText((QString)Obj.readFileHeaderCompileDate());
}

void MainWindow::printFileHeaderCompileTime()
{
    ui->textEdit->insertPlainText("\n4. FileHeaderCompileTime : \n");
    ui->textEdit->insertPlainText((QString)Obj.readFileHeaderCompileTime());
}

void MainWindow::printFileHeaderCompilerVersion()
{
    ui->textEdit->insertPlainText("\n5. FileHeaderCompilerVersion : \n");
    ui->textEdit->insertPlainText((QString)Obj.readFileHeaderCompilerVersion());
}

void MainWindow::printFileHeaderFlagCommonModuleExist()
{
    ui->textEdit->insertPlainText("\n6. FileHeaderFlagCommonModuleExist : \n");

    QByteArray data = Obj.readFileHeaderFlagCommonModuleExist().toHex();
    QString str = (QString) data;
    QString line;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
         line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();

}

void MainWindow::printFileHeaderCountOfBlock()
{
    ui->textEdit->insertPlainText("\n7. FileHeaderCountOfBlock :\n");

    QByteArray data = Obj.readFileHeaderCountOfBlock().toHex();
    QString str = (QString) data;
    QString line;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
          line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printFileHeaderOffsetsOfCommon()
{
    ui->textEdit->insertPlainText("\n8. FileHeaderOffsetsOfCommon : \n");

    QByteArray data = Obj.readFileHeaderCountOfBlock().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
         line+= " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printFileHeaderOffsetsOfBlocks()
{
    ui->textEdit->insertPlainText("\n9. FileHeaderOffsetsOfBlocks :\n");

    QByteArray data = Obj. readFileHeaderOffsetsOfBlocks().toHex();
    QString str = (QString) data;
    QString line;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i%100==99){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
       }
       else if(i%2==1&&i!=0){
         line += " ";
       }

    }

}

void MainWindow::printFileHeaderStartAddressArray()
{
    ui->textEdit->insertPlainText("\n10. FileHeaderStartAddressArray:");

    QByteArray data = Obj. readFileHeaderStartAddressArray().toHex();
    QString str = (QString) data;
    QString line;



    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i%64==0){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
       }
       if(i!=0&&i%2==1){
        line += " ";
       }
    }
}

void MainWindow::printFileHeaderRemark()
{
    ui->textEdit->append("11. FileHeaderRemark : ");
    ui->textEdit->append((QString)Obj. readFileHeaderRemark());
}

void MainWindow::printFileHeaderDataOfIlMode()
{
    ui->textEdit->insertPlainText("\n12. FileHeaderDataOfIlMode : \n");

    QByteArray data = Obj. readFileHeaderDataOfIlMode().toHex();
    QString str = (QString) data;
    QString line;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
           line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printFileHeaderReserved()
{
    ui->textEdit->insertPlainText("\n13. FileHeaderReserved : \n");

    QByteArray data = Obj. readFileHeaderReserved().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
         line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printCommonHeaderOpcodeNDataSet32_r()
{
    ui->textEdit->insertPlainText("\n14. CommonHeaderOpcodeNDataSet32_r : \n");

    QByteArray data = Obj. readCommonHeaderOpcodeNDataSet32_r().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
        line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printCommonHeaderOpcodeNDataSet64_s()
{
    ui->textEdit->insertPlainText("\n15. CommonHeaderOpcodeNDataSet64_s : \n");

    QByteArray data = Obj. readCommonHeaderOpcodeNDataSet64_s().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printCommonHeaderReserved()
{
    ui->textEdit->insertPlainText("\n16. CommonHeaderReserved : \n");

    QByteArray data = Obj. readCommonHeaderReserved().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
          line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printBlock1StartAddress()
{
    ui->textEdit->insertPlainText("\n17. Block1StartAddress : \n");

    QByteArray data = Obj. readBlock1StartAddress().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    line.clear();

}

void MainWindow::printBlock1HeaderOpcodeNDataSet32_r()
{
    ui->textEdit->insertPlainText("\n18. Block1HeaderOpcodeNDataSet32_r : \n");

    QByteArray data = Obj. readBlock1HeaderOpcodeNDataSet32_r().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printBlock1HeaderOpcodeNDataSet64_s()
{
    ui->textEdit->insertPlainText("\n19. Block1HeaderOpcodeNDataSet64_s : \n");

    QByteArray data = Obj. readBlock1HeaderOpcodeNDataSet64_s().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printBlock1HeaderMicroPatternCount()
{
    ui->textEdit->insertPlainText("\n20. Block1HeaderMicroPatternCount : \n");

    QByteArray data = Obj. readBlock1HeaderMicroPatternCount().toHex();
    QString str = (QString) data;
    QString line;


    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}

void MainWindow::printBlock1HeaderReaserverd()
{
    ui->textEdit->insertPlainText("\n21. Block1HeaderReaserverd : \n");

    QByteArray data = Obj. readBlock1HeaderReaserverd().toHex();
    QString str = (QString) data;
    QString line;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i!=0&&i%2==1){
       line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    line.clear();
}
