#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "print.h"

void MainWindow::printFileInformationInLabel()
{
    QString informationFile;

    QByteArray fileData = Obj.readAll();

    informationFile.append("File Name : ");
    informationFile.append(Obj.readPatFile(Obj.getFileHeaderSourceFileName_Address(),Obj.getFileHeaderCompileDate_Address()));
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

void MainWindow::printBinaryFileInTable_Widget2()
{
    QByteArray fileData = Obj.readPatFile(Obj.getBlock1BodyMicroPattern_Address(),Obj.getBlock1BodyReserved_Address()).toHex();

    int column = 32;
    int row = fileData.size()/2;

    QString hexString = (QString) fileData;
    QString binaryString = hexStringToBinaryString(hexString);


     ui->tableWidget_2->setRowCount(row);
     ui->tableWidget_2->setColumnCount(column);


     int microBitTable_row_num = 0;
     int microPattern_row_num = 0;
     int changeColor = 0;

     for(int i=0;i<row;i++){

         if(i%2==0){
             for(int j=0;j<column;j++){
                QTableWidgetItem *item = ui->tableWidget_2->item(i,j);
                if(!item){
                    item = new QTableWidgetItem();

                    if(changeColor%2==0) item->setBackground(Qt::gray);
                    else item->setBackground(Qt::darkGreen);

                    ui->tableWidget_2->setItem(i,j,item);
                }

                QString binraryStringOne = MicroBitTable[microBitTable_row_num][j];

                item->setText(binraryStringOne);
             }
             microBitTable_row_num += 1;
             microBitTable_row_num %= 29;

             if(microBitTable_row_num==0){
                   changeColor += 1;
                   changeColor %= 2;
             }
         }
         else{
             for(int j=0;j<column;j++){
                QTableWidgetItem *item = ui->tableWidget_2->item(i,j);
                if(!item){
                    item = new QTableWidgetItem();
                    ui->tableWidget_2->setItem(i,j,item);
                }

                QString binraryStringOne = binaryString.at(microPattern_row_num*32+j);

                item->setText(binraryStringOne);
             }
             microPattern_row_num += 1;
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
    printFileHeaderStartAddressArray();
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

void MainWindow::printCommonBodyInTextEdit()
{
    printCommonBodyRegister32();
    printCommonBodyRegister64();
}

void MainWindow::printBlockHeaderInTextEdit()
{
    printBlock1StartAddress();
    printBlock1HeaderOpcodeNDataSet32_r();
    printBlock1HeaderOpcodeNDataSet64_s();
    printBlock1HeaderMicroPatternCount();
    printBlock1HeaderReaserverd();
}

void MainWindow::printBlockBodyInTextEdit()
{
    printBlock1BodyRegister32();
    printBlock1BodyRegister64();
    printBlock1BodyMicroPattern();
    printBlock1Reserved();
}

void MainWindow::printFileHeaderDiscemmentCode()
{
    ui->textEdit->insertPlainText("1. FileHeaderDiscemmentCode : scope : ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderDiscemmentCode_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderSourceFileName_Address()));
    ui->textEdit->insertPlainText("\n");

    // QByteArray data = Obj.readFileHeaderDiscemmentCode(Obj.getFileHeaderDiscemmentCode_Address(),Obj.getFileHeaderSourceFileName_Address()).toHex();
    QByteArray data = Obj.readPatFile(Obj.getFileHeaderDiscemmentCode_Address(),Obj.getFileHeaderSourceFileName_Address()).toHex();

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
    ui->textEdit->insertPlainText("\n\n2. FileHeaderSourceFileName : scope :  ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderSourceFileName_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCompileDate_Address()));
    ui->textEdit->insertPlainText("\n");
    ui->textEdit->insertPlainText((QString)Obj.readPatFile(Obj.getFileHeaderSourceFileName_Address(),Obj.getFileHeaderCompileDate_Address()));
}

void MainWindow::printFileHeaderCompileDate()
{
    ui->textEdit->insertPlainText("\n\n3. FileHeaderCompileDate : scope : ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCompileDate_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCompileTime_Address()));
    ui->textEdit->insertPlainText("\n");
    ui->textEdit->insertPlainText((QString)Obj.readPatFile(Obj.getFileHeaderCompileDate_Address(),Obj.getFileHeaderCompileTime_Address()));
}

void MainWindow::printFileHeaderCompileTime()
{
    ui->textEdit->insertPlainText("\n\n4. FileHeaderCompileTime : scope :  ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCompileTime_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCompilerVersion_Address()));
    ui->textEdit->insertPlainText("\n");
    ui->textEdit->insertPlainText((QString)Obj.readPatFile(Obj.getFileHeaderCompileTime_Address(),Obj.getFileHeaderCompilerVersion_Address()));
}

void MainWindow::printFileHeaderCompilerVersion()
{
    ui->textEdit->insertPlainText("\n\n5. FileHeaderCompilerVersion : scope : ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCompilerVersion_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderFlagCommonModuleExist_Address()));
    ui->textEdit->insertPlainText("\n");
    ui->textEdit->insertPlainText((QString)Obj.readPatFile(Obj.getFileHeaderCompilerVersion_Address(),Obj.getFileHeaderFlagCommonModuleExist_Address()));
}

void MainWindow::printFileHeaderFlagCommonModuleExist()
{
    ui->textEdit->insertPlainText("\n\n6. FileHeaderFlagCommonModuleExist : scope: ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderFlagCommonModuleExist_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCountOfBlock_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj.readPatFile(Obj.getFileHeaderFlagCommonModuleExist_Address(),Obj.getFileHeaderCountOfBlock_Address()).toHex();
    // QByteArray data = Obj.readFileHeaderFlagCommonModuleExist(Obj.getFileHeaderFlagCommonModuleExist_Address(),Obj.getFileHeaderCountOfBlock_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n7. FileHeaderCountOfBlock :scope :");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderCountOfBlock_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderOffsetsOfCommon_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj.readPatFile(Obj.getFileHeaderCountOfBlock_Address(),Obj.getFileHeaderOffsetsOfCommon_Address()).toHex();

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
    ui->textEdit->insertPlainText("\n\n8. FileHeaderOffsetsOfCommon : scope : ");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderOffsetsOfCommon_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderOffsetsOfBlocks_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj.readPatFile(Obj.getFileHeaderOffsetsOfCommon_Address(),Obj.getFileHeaderOffsetsOfBlocks_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n9. FileHeaderOffsetsOfBlocks : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderOffsetsOfBlocks_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderStartAddressArray_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getFileHeaderOffsetsOfBlocks_Address(),Obj.getFileHeaderStartAddressArray_Address()).toHex();
    QString str = (QString) data;
    QString line;
    int number =1;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i%100==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
       }
       if(i%100==99){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i%2==1&&i!=0){
         line += " ";
       }

    }

    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();

}

void MainWindow::printFileHeaderStartAddressArray()
{
    ui->textEdit->insertPlainText("\n\n10. FileHeaderStartAddressArray: scope :");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderStartAddressArray_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderRemark_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getFileHeaderStartAddressArray_Address(),Obj.getFileHeaderRemark_Address()).toHex();
    QString str = (QString) data;
    QString line;
    int number =1;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i%100==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
       }
       if(i%100==99){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i%2==1&&i!=0){
         line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();
}

void MainWindow::printFileHeaderRemark()
{
    ui->textEdit->append("\n11. FileHeaderRemark : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderRemark_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderDataOfIlMode_Address()));
    ui->textEdit->insertPlainText("\n");
    ui->textEdit->append((QString)Obj. readPatFile(Obj.getFileHeaderRemark_Address(),Obj.getFileHeaderDataOfIlMode_Address()));
}

void MainWindow::printFileHeaderDataOfIlMode()
{
    ui->textEdit->insertPlainText("\n\n12. FileHeaderDataOfIlMode : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderDataOfIlMode_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderReserved_Address()));
    ui->textEdit->insertPlainText("\n");
    QByteArray data = Obj. readPatFile(Obj.getFileHeaderDataOfIlMode_Address(),Obj.getFileHeaderReserved_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n13. FileHeaderReserved : scope :");
    ui->textEdit->insertPlainText(QString::number(Obj.getFileHeaderReserved_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonHeaderOpcodeNDataSet32_r_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getFileHeaderReserved_Address(),Obj.getCommonHeaderOpcodeNDataSet32_r_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n14. CommonHeaderOpcodeNDataSet32_r : scope: ");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonHeaderOpcodeNDataSet32_r_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonHeaderOpcodeNDataSet64_s_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getCommonHeaderOpcodeNDataSet32_r_Address(),Obj.getCommonHeaderOpcodeNDataSet64_s_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n15. CommonHeaderOpcodeNDataSet64_s : scope : ");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonHeaderOpcodeNDataSet64_s_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonHeaderReserved_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getCommonHeaderOpcodeNDataSet64_s_Address(),Obj.getCommonHeaderReserved_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n16. CommonHeaderReserved : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonHeaderReserved_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonBodyRegister32_r_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getCommonHeaderReserved_Address(),Obj.getCommonBodyRegister32_r_Address()).toHex();
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

void MainWindow::printCommonBodyRegister32()
{
    ui->textEdit->insertPlainText("\n\n17. CommonBodyRegister32_r : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonBodyRegister32_r_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonBodyRegister64_s_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getCommonBodyRegister32_r_Address(),Obj.getCommonBodyRegister64_s_Address()).toHex();

    QString str = (QString) data;
    QString line;
    int number = 1;

    for(int i=0;i<str.length();i++){

       if(i%8==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
           line += "  OPCODE : ";
       }

       line += str[i];

       if(i%8==3){
           line += "    DATA : ";
       }
       if(i%8==7){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i!=0&&i%2==1){
          line += " ";
       }
    }

    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();

}

void MainWindow::printCommonBodyRegister64()
{
    ui->textEdit->insertPlainText("\n\n18. CommonBodyRegister64_s : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getCommonBodyRegister64_s_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1StartAddress_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getCommonBodyRegister64_s_Address(),Obj.getBlock1StartAddress_Address()).toHex();
    QString str = (QString) data;
    QString line;
    int number = 1;


    for(int i=0;i<str.length();i++){

       if(i%12==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
           line += "  OPCODE : ";
       }

       line += str[i];

       if(i%12==3){
           line += "    DATA : ";
       }
       if(i%12==11){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i!=0&&i%2==1){
          line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();
}

void MainWindow::printBlock1StartAddress()
{
    ui->textEdit->insertPlainText("\n\n19. Block1StartAddress : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1StartAddress_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderOpcodeNDataSet32_r_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getBlock1StartAddress_Address(),Obj.getBlock1HeaderOpcodeNDataSet32_r_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n20. Block1HeaderOpcodeNDataSet32_r : scope :");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderOpcodeNDataSet32_r_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderOpcodeNDataSet64_s_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getBlock1HeaderOpcodeNDataSet32_r_Address(),Obj.getBlock1HeaderOpcodeNDataSet64_s_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n21. Block1HeaderOpcodeNDataSet64_s : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderOpcodeNDataSet64_s_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderMicroPatternCount_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getBlock1HeaderOpcodeNDataSet64_s_Address(),Obj.getBlock1HeaderMicroPatternCount_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n22. Block1HeaderMicroPatternCount : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderMicroPatternCount_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderReaserverd_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getBlock1HeaderMicroPatternCount_Address(),Obj.getBlock1HeaderReaserverd_Address()).toHex();
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
    ui->textEdit->insertPlainText("\n\n23. Block1HeaderReserverd : scope : ");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1HeaderReaserverd_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyRegister32_r_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getBlock1HeaderReaserverd_Address(),Obj.getBlock1BodyRegister32_r_Address()).toHex();
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

void MainWindow::printBlock1BodyRegister32()
{
    ui->textEdit->insertPlainText("\n\n24. Block1BodyRegister32 : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyRegister32_r_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyRegister64_s_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj.readPatFile(Obj.getBlock1BodyRegister32_r_Address(),Obj.getBlock1BodyRegister64_s_Address()).toHex();

    QString str = (QString) data;
    QString line;
    int number = 1;

    for(int i=0;i<str.length();i++){

       if(i%8==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
           line += "  OPCODE : ";
       }
       line += str[i];

       if(i%8==3){
         line += "    DATA : ";
       }

       if(i%8==7){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i!=0&&i%2==1){
          line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();
}

void MainWindow::printBlock1BodyRegister64()
{
    ui->textEdit->insertPlainText("\n\n25. Block1BodyRegister64 : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyRegister64_s_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyMicroPattern_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj.readPatFile(Obj.getBlock1BodyRegister64_s_Address(),Obj.getBlock1BodyMicroPattern_Address()).toHex();
    QString str = (QString) data;
    QString line;
    int number = 1;


    for(int i=0;i<str.length();i++){
       if(i%12==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
           line += "  OPCODE : ";
       }

       line += str[i];

       if(i%12==7){
           line += "    DATA : ";
       }
       if(i%12==11){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i!=0&&i%2==1){
          line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();
}

void MainWindow::printBlock1BodyMicroPattern()
{
    ui->textEdit->insertPlainText("\n\n26. Block1BodyMicroPattern : scope:");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyMicroPattern_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyReserved_Address()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj.readPatFile(Obj.getBlock1BodyMicroPattern_Address(),Obj.getBlock1BodyReserved_Address()).toHex();
    QString str = (QString) data;
    QString line;
    int number = 1;

    for(int i=0;i<str.length();i++){
       line += str[i];

       if(i%116==0){
           ui->textEdit->insertPlainText("line ");
           ui->textEdit->insertPlainText(QString::number(number));
           ui->textEdit->insertPlainText("   :   ");
       }
       if(i%116==115){
           ui->textEdit->insertPlainText(line);
           ui->textEdit->append("");
           line.clear();
           number++;
       }
       else if(i!=0&&i%2==1){
          line += " ";
       }
    }
    ui->textEdit->insertPlainText(line);
    ui->textEdit->append("");
    line.clear();

}

void MainWindow::printBlock1Reserved()
{
    ui->textEdit->insertPlainText("\n\n27. Block1HeaderReaserverd : scope :");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyReserved_Address()+1));
    ui->textEdit->insertPlainText("~");
    ui->textEdit->insertPlainText(QString::number(Obj.getBlock1BodyReserved_Address()+Obj.getblock1BodyReserved_size()));
    ui->textEdit->insertPlainText("\n");

    QByteArray data = Obj. readPatFile(Obj.getBlock1BodyReserved_Address(),Obj.getBlock1BodyReserved_Address()+Obj.getblock1BodyReserved_size()).toHex();
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
