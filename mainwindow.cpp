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
    FileHeaderObj = fileHeader;

    Obj.setFileHeaderDiscemmentCode_Address(0);
    Obj.setFileHeaderSourceFileName_Address(Obj.getFileHeaderDiscemmentCode_Address()+fileHeader.getDiscemmentCodeSize().toInt());
    Obj.setFileHeaderCompileDate_Address(Obj.getFileHeaderSourceFileName_Address()+fileHeader.getSourceFileNameSize().toInt());
    Obj.setFileHeaderCompileTime_Address(Obj.getFileHeaderCompileDate_Address()+fileHeader.getCompileDateSize().toInt());
    Obj.setFileHeaderCompilerVersion_Address(Obj.getFileHeaderCompileTime_Address()+fileHeader.getCompileTimeSize().toInt());
    Obj.setFileHeaderFlagCommonModuleExist_Address(Obj.getFileHeaderCompilerVersion_Address()+fileHeader.getCompilerVersionSize().toInt());
    Obj.setFileHeaderCountOfBlock_Address(Obj.getFileHeaderFlagCommonModuleExist_Address()+fileHeader.getFlagOfPartExistSize().toInt());
    Obj.setFileHeaderOffsetsOfCommon_Address(Obj.getFileHeaderCountOfBlock_Address()+fileHeader.getCountOfBlockMSize().toInt());
    Obj.setFileHeaderOffsetsOfBlocks_Address(Obj.getFileHeaderOffsetsOfCommon_Address()+fileHeader.getOffsetsOfCommonSize().toInt());
    Obj.setFileHeaderStartAddressArray_Address(Obj.getFileHeaderOffsetsOfBlocks_Address()+fileHeader.getOffsetsBlockSize().toInt());
    Obj.setFileHeaderRemark_Address(Obj.getFileHeaderStartAddressArray_Address()+fileHeader.getStartAddressSize().toInt());
    Obj.setFileHeaderDataOfIlMode_Address(Obj.getFileHeaderRemark_Address()+fileHeader.getRemarkSize().toInt());
    Obj.setFileHeaderReserved_Address(Obj.getFileHeaderDataOfIlMode_Address()+fileHeader.getDataILSize().toInt());

    /*
    qDebug()<<Obj.getFileHeaderDiscemmentCode_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderSourceFileName_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderCompileDate_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderCompileTime_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderCompilerVersion_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderFlagCommonModuleExist_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderCountOfBlock_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderOffsetsOfCommon_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderOffsetsOfBlocks_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderStartAddressArray_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderRemark_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderDataOfIlMode_Address()<<"\n";
    qDebug()<<Obj.getFileHeaderReserved_Address()<<"\n";
    */

}


void MainWindow::receiveCommonHeaderSize(CommonHeaderSize commonHeader)
{
    CommonHeaderObj = commonHeader;

    Obj.setCommonHeaderOpcodeNDataSet32_r_Address(Obj.getFileHeaderReserved_Address()+FileHeaderObj.getReservedSize().toInt());
    Obj.setCommonHeaderOpcodeNDataSet64_s_Address(Obj.getCommonHeaderOpcodeNDataSet32_r_Address()+commonHeader.getDataSetRsize().toInt());
    Obj.setCommonHeaderReserved_Address(Obj.getCommonHeaderOpcodeNDataSet64_s_Address()+commonHeader.getDataSetSsize().toInt());
    setCommonBodyAddress();
    /*
    qDebug()<<Obj.getCommonHeaderOpcodeNDataSet32_r_Address()<<"\n";
    qDebug()<<Obj.getCommonHeaderOpcodeNDataSet64_s_Address()<<"\n";
    qDebug()<<Obj.getCommonHeaderReserved_Address()<<"\n";
    */

}


void MainWindow::receiveBlockHeaderSize(BlockHeaderSize blockHeader)
{
    BlockHeaderObj = blockHeader;
    setBlock1BodyAddress();

}


void MainWindow::on_openButton_clicked()
{
    // ASCII : value name / Hex : value name.toHex()
    // Print File information.

    initVariable();

    if(Obj.readPatFile()){
    ui->textEdit->clear();
    setDynamicFatFileAddress();

    printHexFileInTableWidget();
    printFileInformationInLabel();
    printFileHeaderInTextEdit();
    printCommonHeaderInTextEdit();
    printCommonBodyInTextEdit();
    printBlockHeaderInTextEdit();
    printBlockBodyInTextEdit();
   }
}

void MainWindow::initVariable()
{
    _found = false;
}

int MainWindow::stringToIntLittleEndian(QString hexString)
{
    QString temp = hexString;
    int size = hexString.length();

    for(int i=0;i<size;i++)
        hexString[size-i-1] = temp[i];

    temp = hexString;

    for(int i=0;i<size/2;i++)
        for(int j=0;j<2;j++)
            hexString[i*2+j] = temp[i*2+1-j];

    return hexString.toUInt(false,16);

}

void MainWindow::setDynamicFatFileAddress()
{
    setCommonBodyAddress();
    setBlock1BodyAddress();
}

void MainWindow::setCommonBodyAddress()
{
    QString data = (QString) Obj.readCommonHeaderOpcodeNDataSet32_r(Obj.getCommonHeaderOpcodeNDataSet32_r_Address(),Obj.getCommonHeaderOpcodeNDataSet64_s_Address()).toHex();
    int value = stringToIntLittleEndian(data);

    Obj.setCommonBodyRegister32_r_Address(Obj.getCommonHeaderReserved_Address()+Obj.CommonHeaderObj.getReservedSize().toInt());
    Obj.setCommonBodyRegister64_s_Address(Obj.getCommonBodyRegister32_r_Address()+value*8);
}

void MainWindow::setBlock1BodyAddress()
{
    QString data = (QString) Obj.readCommonHeaderOpcodeNDataSet32_r(Obj.getCommonHeaderOpcodeNDataSet64_s_Address(),Obj.getCommonHeaderReserved_Address()).toHex();
    int value = stringToIntLittleEndian(data);
    int r,s,p;

    Obj.setBlock1StartAddress_Address(Obj.getCommonBodyRegister64_s_Address()+value*12+15); // add Division line FFFFF FFFFF FFFFF
    Obj.setBlock1HeaderOpcodeNDataSet32_r_Address(Obj.getBlock1StartAddress_Address()+Obj.BlockHeaderObj.getStartAddressSize().toInt());
    Obj.setBlock1HeaderOpcodeNDataSet64_s_Address(Obj.getBlock1HeaderOpcodeNDataSet32_r_Address()+Obj.BlockHeaderObj.getDataSetRSize().toInt());
    Obj.setBlock1HeaderMicroPatternCount_Address(Obj.getBlock1HeaderOpcodeNDataSet64_s_Address()+Obj.BlockHeaderObj.getDataSetSSize().toInt());
    Obj.setBlock1HeaderReaserverd_Address(Obj.getBlock1HeaderMicroPatternCount_Address()+Obj.BlockHeaderObj.getPatternCountPSize().toInt());

    data = (QString) Obj.readBlock1HeaderOpcodeNDataSet32_r(Obj.getBlock1HeaderOpcodeNDataSet32_r_Address(),Obj.getBlock1HeaderOpcodeNDataSet64_s_Address()).toHex();
    value = stringToIntLittleEndian(data);
    r = value;

    Obj.setBlock1BodyRegister32_r_Address(Obj.getBlock1HeaderReaserverd_Address()+Obj.BlockHeaderObj.getReservedSize().toInt());
    Obj.setBlock1BodyRegister64_s_Address(Obj.getBlock1BodyRegister32_r_Address()+value*8);

    data = (QString) Obj.readBlock1HeaderOpcodeNDataSet64_s(Obj.getBlock1HeaderOpcodeNDataSet64_s_Address(),Obj.getBlock1HeaderMicroPatternCount_Address()).toHex();
    value = stringToIntLittleEndian(data);
    s = value;

    Obj.setBlock1BodyMicroPattern_Address(Obj.getBlock1BodyRegister64_s_Address()+value*12);

    data = (QString) Obj.readBlock1HeaderMicroPatternCount(Obj.getBlock1HeaderMicroPatternCount_Address(),Obj.getBlock1HeaderReaserverd_Address()).toHex();
    value = stringToIntLittleEndian(data);
    p = value;

    Obj.setBlock1BodyReserved_Address(Obj.getBlock1BodyMicroPattern_Address()+value*116);

    int x = 16 -(r*8+s*12+p*64) % 16;
    Obj.setBlock1BodyReserved_size(x);
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
        informationFile.append(Obj.readFileHeaderSourceFileName(Obj.getFileHeaderSourceFileName_Address(),Obj.getFileHeaderCompileDate_Address()));
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
