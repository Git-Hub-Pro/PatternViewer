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

    /*
    qDebug()<<Obj.getCommonHeaderOpcodeNDataSet32_r_Address()<<"\n";
    qDebug()<<Obj.getCommonHeaderOpcodeNDataSet64_s_Address()<<"\n";
    qDebug()<<Obj.getCommonHeaderReserved_Address()<<"\n";
    */

}


void MainWindow::receiveBlockHeaderSize(BlockHeaderSize blockHeader)
{
    BlockHeaderObj = blockHeader;

    Obj.setBlock1StartAddress_Address(blockHeader.getStartAddressSize().toInt());
    Obj.setBlock1HeaderOpcodeNDataSet32_r_Address(blockHeader.getDataSetRSize().toInt());
    Obj.setBlock1HeaderOpcodeNDataSet64_s_Address(blockHeader.getDataSetSSize().toInt());
    Obj.setBlock1HeaderMicroPatternCount_Address(blockHeader.getPatternCountPSize().toInt());
    Obj.setBlock1HeaderReaserverd_Address(blockHeader.getReservedSize().toInt());
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
