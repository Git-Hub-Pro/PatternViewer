#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::receiveFileHeaderSizeFromMainWindow(FileHeaderSize fileHeadersize)
{
   _FileHeader = fileHeadersize;
   printFileHeader();
}

void SettingDialog::receiveCommonHeaderSizeFromMainWindow(CommonHeaderSize commonHeaderSize)
{
   _CommonHeader = commonHeaderSize;
   printCommonHeader();
}

void SettingDialog::receiveBlockHeaderSizeFromMainWindow(BlockHeaderSize blockHeaderSize)
{
    _BlockHeader = blockHeaderSize;
    printBlockHeader();
}

void SettingDialog::receiveBlockNumberFromMainWindow(QString blockNumber)
{
    _blockNum = blockNumber;
    printBlockNum();
}

void SettingDialog::on_cancelPushButton_clicked()
{
   SettingDialog::close();
}

void SettingDialog::on_defaultPushButton_clicked()
{
    setFileHeaderDefault();
    setCommonHeaderDefault();
    setBlockHeaderDefault();
    setBlockNumDefault();

    printFileHeader();
    printCommonHeader();
    printBlockHeader();
    printBlockNum();
}

void SettingDialog::setFileHeaderDefault()
{
    _FileHeader.setDiscemmentCodeSize("4");
    _FileHeader.setSourceFileNameSize("36");
    _FileHeader.setCompileDateSize("8");
    _FileHeader.setCompileTimeSize("8");
    _FileHeader.setCompilerVersionSize("8");
    _FileHeader.setFlagOfPartExistSize("4");
    _FileHeader.setCountOfBlockMSize("4");
    _FileHeader.setOffsetsOfCommonSize("4");
    _FileHeader.setOffsetsBlockSize("16384");
    _FileHeader.setStartAddressSize("16384");
    _FileHeader.setRemarkSize("80");
    _FileHeader.setDataILSize("4");
    _FileHeader.setReservedSize("16");
}

void SettingDialog::setCommonHeaderDefault()
{
    _CommonHeader.setDataSetRsize("4");
    _CommonHeader.setDataSetSsize("4");
    _CommonHeader.setReservedSize("8");
}

void SettingDialog::setBlockHeaderDefault()
{
    _BlockHeader.setStartAddressSize("4");
    _BlockHeader.setDataSetRSize("4");
    _BlockHeader.setDataSetSSize("4");
    _BlockHeader.setPatternCountPSize("4");
    _BlockHeader.setReservedSize("4");
}

void SettingDialog::printFileHeader()
{
    ui->fileHeaderLineEdit1->setText(_FileHeader.getDiscemmentCodeSize());
    ui->fileHeaderLineEdit2->setText(_FileHeader.getSourceFileNameSize());
    ui->fileHeaderLineEdit3->setText(_FileHeader.getCompileDateSize());
    ui->fileHeaderLineEdit4->setText(_FileHeader.getCompileTimeSize());
    ui->fileHeaderLineEdit5->setText(_FileHeader.getCompilerVersionSize());
    ui->fileHeaderLineEdit6->setText(_FileHeader.getFlagOfPartExistSize());
    ui->fileHeaderLineEdit7->setText(_FileHeader.getCountOfBlockMSize());
    ui->fileHeaderLineEdit8->setText(_FileHeader.getOffsetsOfCommonSize());
    ui->fileHeaderLineEdit9->setText(_FileHeader.getOffsetsBlockSize());
    ui->fileHeaderLineEdit10->setText(_FileHeader.getStartAddressSize());
    ui->fileHeaderLineEdit11->setText(_FileHeader.getRemarkSize());
    ui->fileHeaderLineEdit12->setText(_FileHeader.getDataILSize());
    ui->fileHeaderLineEdit13->setText(_FileHeader.getReservedSize());
}

void SettingDialog::printCommonHeader()
{
    ui->commonHeaderLineEdit1->setText(_CommonHeader.getDataSetRsize());
    ui->commonHeaderLineEdit2->setText(_CommonHeader.getDataSetSsize());
    ui->commonHeaderLineEdit3->setText(_CommonHeader.getReservedSize());
}

void SettingDialog::printBlockHeader()
{
    ui->blockHeaderLineEdit1->setText(_BlockHeader.getStartAddressSize());
    ui->blockHeaderLineEdit2->setText(_BlockHeader.getDataSetRSize());
    ui->blockHeaderLineEdit3->setText(_BlockHeader.getDataSetSSize());
    ui->blockHeaderLineEdit4->setText(_BlockHeader.getPatternCountPSize());
    ui->blockHeaderLineEdit5->setText(_BlockHeader.getReservedSize());
}

void SettingDialog::printBlockNum()
{
    ui->blockNumlineEdit->setText(getBlockNum());
}

void SettingDialog::on_applyPushButton_clicked()
{

    setFileHeaderAll();
    setCommonHeaderAll();
    setBlockHeaderAll();
    setBlockNumFromTextEdit();

    connect(this,SIGNAL(sendFileHeaderSize(FileHeaderSize)),parent(),SLOT(receiveFileHeaderSize(FileHeaderSize)));
    emit sendFileHeaderSize(_FileHeader);
    disconnect(this, 0, 0, 0);

    connect(this,SIGNAL(sendCommonHeaderSize(CommonHeaderSize)),parent(),SLOT(receiveCommonHeaderSize(CommonHeaderSize)));
    emit sendCommonHeaderSize(_CommonHeader);
    disconnect(this, 0, 0, 0);

    connect(this,SIGNAL(sendBlockHeaderSize(BlockHeaderSize)),parent(),SLOT(receiveBlockHeaderSize(BlockHeaderSize)));
    emit sendBlockHeaderSize(_BlockHeader);
    disconnect(this, 0, 0, 0);

    connect(this,SIGNAL(sendBlockNumber(QString)),parent(),SLOT(receiveBlockNumber(QString)));
    emit sendBlockNumber(getBlockNum());
    disconnect(this, 0, 0, 0);

}

void SettingDialog::setFileHeaderAll()
{
    _FileHeader.setDiscemmentCodeSize(ui->fileHeaderLineEdit1->text());
    _FileHeader.setSourceFileNameSize(ui->fileHeaderLineEdit2->text());
    _FileHeader.setCompileDateSize(ui->fileHeaderLineEdit3->text());
    _FileHeader.setCompileTimeSize(ui->fileHeaderLineEdit4->text());
    _FileHeader.setCompilerVersionSize(ui->fileHeaderLineEdit5->text());
    _FileHeader.setFlagOfPartExistSize(ui->fileHeaderLineEdit6->text());
    _FileHeader.setCountOfBlockMSize(ui->fileHeaderLineEdit7->text());
    _FileHeader.setOffsetsOfCommonSize(ui->fileHeaderLineEdit8->text());
    _FileHeader.setOffsetsBlockSize(ui->fileHeaderLineEdit9->text());
    _FileHeader.setStartAddressSize(ui->fileHeaderLineEdit10->text());
    _FileHeader.setRemarkSize(ui->fileHeaderLineEdit11->text());
    _FileHeader.setDataILSize(ui->fileHeaderLineEdit12->text());
    _FileHeader.setReservedSize(ui->fileHeaderLineEdit13->text());
}

void SettingDialog::setCommonHeaderAll()
{
    _CommonHeader.setDataSetRsize(ui->commonHeaderLineEdit1->text());
    _CommonHeader.setDataSetSsize(ui->commonHeaderLineEdit2->text());
    _CommonHeader.setReservedSize(ui->commonHeaderLineEdit3->text());
}

void SettingDialog::setBlockHeaderAll()
{
    _BlockHeader.setStartAddressSize(ui->blockHeaderLineEdit1->text());
    _BlockHeader.setDataSetRSize(ui->blockHeaderLineEdit2->text());
    _BlockHeader.setDataSetSSize(ui->blockHeaderLineEdit3->text());
    _BlockHeader.setPatternCountPSize(ui->blockHeaderLineEdit4->text());
    _BlockHeader.setReservedSize(ui->blockHeaderLineEdit5->text());
}

void SettingDialog::setBlockNumFromTextEdit()
{
    setBlockNum(ui->blockNumlineEdit->text());
}
