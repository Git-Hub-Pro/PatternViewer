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

void SettingDialog::on_cancelPushButton_clicked()
{
   SettingDialog::close();
}

void SettingDialog::on_defaultPushButton_clicked()
{
    setFileHeaderDefault();
    setCommonHeaderDefault();
    setBlockHeaderDefault();

    printFileHeader();
    printCommonHeader();
    printBlockHeader();
}

void SettingDialog::setFileHeaderDefault()
{
    FileHeader.setDiscemmentCodeSize("4");
    FileHeader.setSourceFileNameSize("36");
    FileHeader.setCompileDateSize("8");
    FileHeader.setCompileTimeSize("8");
    FileHeader.setCompilerVersionSize("8");
    FileHeader.setFlagOfPartExistSize("4");
    FileHeader.setCountOfBlockMSize("4");
    FileHeader.setOffsetsOfCommonSize("4");
    FileHeader.setOffsetsBlockSize("16384");
    FileHeader.setStartAddressSize("16384");
    FileHeader.setRemarkSize("80");
    FileHeader.setDataILSize("4");
    FileHeader.setReservedSize("16");
}

void SettingDialog::setCommonHeaderDefault()
{
    CommonHeader.setDataSetRsize("4");
    CommonHeader.setDataSetSsize("4");
    CommonHeader.setReservedSize("8");
}

void SettingDialog::setBlockHeaderDefault()
{
    BlockHeader.setStartAddressSize("4");
    BlockHeader.setDataSetRSize("4");
    BlockHeader.setDataSetSSize("4");
    BlockHeader.setPatternCountPSize("4");
    BlockHeader.setReservedSize("4");
}

void SettingDialog::printFileHeader()
{
    ui->fileHeaderLineEdit1->setText(FileHeader.getDiscemmentCodeSize());
    ui->fileHeaderLineEdit2->setText(FileHeader.getSourceFileNameSize());
    ui->fileHeaderLineEdit3->setText(FileHeader.getCompileDateSize());
    ui->fileHeaderLineEdit4->setText(FileHeader.getCompileTimeSize());
    ui->fileHeaderLineEdit5->setText(FileHeader.getCompilerVersionSize());
    ui->fileHeaderLineEdit6->setText(FileHeader.getFlagOfPartExistSize());
    ui->fileHeaderLineEdit7->setText(FileHeader.getCountOfBlockMSize());
    ui->fileHeaderLineEdit8->setText(FileHeader.getOffsetsOfCommonSize());
    ui->fileHeaderLineEdit9->setText(FileHeader.getOffsetsBlockSize());
    ui->fileHeaderLineEdit10->setText(FileHeader.getStartAddressSize());
    ui->fileHeaderLineEdit11->setText(FileHeader.getRemarkSize());
    ui->fileHeaderLineEdit12->setText(FileHeader.getDataILSize());
    ui->fileHeaderLineEdit13->setText(FileHeader.getReservedSize());
}

void SettingDialog::printCommonHeader()
{
    ui->commonHeaderLineEdit1->setText(CommonHeader.getDataSetRsize());
    ui->commonHeaderLineEdit2->setText(CommonHeader.getDataSetSsize());
    ui->commonHeaderLineEdit3->setText(CommonHeader.getReservedSize());
}

void SettingDialog::printBlockHeader()
{
    ui->blockHeaderLineEdit1->setText(BlockHeader.getStartAddressSize());
    ui->blockHeaderLineEdit2->setText(BlockHeader.getDataSetRSize());
    ui->blockHeaderLineEdit3->setText(BlockHeader.getDataSetSSize());
    ui->blockHeaderLineEdit4->setText(BlockHeader.getPatternCountPSize());
    ui->blockHeaderLineEdit5->setText(BlockHeader.getReservedSize());
}

void SettingDialog::on_applyPushButton_clicked()
{

    setFileHeaderAll();
    setCommonHeaderAll();
    setBlockHeaderAll();

    connect(this,SIGNAL(sendFileHeaderSize(FileHeaderSize)),parent(),SLOT(receiveFileHeaderSize(FileHeaderSize)));
    emit sendFileHeaderSize(FileHeader);
    disconnect(this, 0, 0, 0);

    connect(this,SIGNAL(sendCommonHeaderSize(CommonHeaderSize)),parent(),SLOT(receiveCommonHeaderSize(CommonHeaderSize)));
    emit sendCommonHeaderSize(CommonHeader);
    disconnect(this, 0, 0, 0);

    connect(this,SIGNAL(sendBlockHeaderSize(BlockHeaderSize)),parent(),SLOT(receiveBlockHeaderSize(BlockHeaderSize)));
    emit sendBlockHeaderSize(BlockHeader);
    disconnect(this, 0, 0, 0);

}

void SettingDialog::setFileHeaderAll()
{
    FileHeader.setDiscemmentCodeSize(ui->fileHeaderLineEdit1->text());
    FileHeader.setSourceFileNameSize(ui->fileHeaderLineEdit2->text());
    FileHeader.setCompileDateSize(ui->fileHeaderLineEdit3->text());
    FileHeader.setCompileTimeSize(ui->fileHeaderLineEdit4->text());
    FileHeader.setCompilerVersionSize(ui->fileHeaderLineEdit5->text());
    FileHeader.setFlagOfPartExistSize(ui->fileHeaderLineEdit6->text());
    FileHeader.setCountOfBlockMSize(ui->fileHeaderLineEdit7->text());
    FileHeader.setOffsetsOfCommonSize(ui->fileHeaderLineEdit8->text());
    FileHeader.setOffsetsBlockSize(ui->fileHeaderLineEdit9->text());
    FileHeader.setStartAddressSize(ui->fileHeaderLineEdit10->text());
    FileHeader.setRemarkSize(ui->fileHeaderLineEdit11->text());
    FileHeader.setDataILSize(ui->fileHeaderLineEdit12->text());
    FileHeader.setReservedSize(ui->fileHeaderLineEdit13->text());
}

void SettingDialog::setCommonHeaderAll()
{
    CommonHeader.setDataSetRsize(ui->commonHeaderLineEdit1->text());
    CommonHeader.setDataSetSsize(ui->commonHeaderLineEdit2->text());
    CommonHeader.setReservedSize(ui->commonHeaderLineEdit3->text());
}

void SettingDialog::setBlockHeaderAll()
{
    BlockHeader.setStartAddressSize(ui->blockHeaderLineEdit1->text());
    BlockHeader.setDataSetRSize(ui->blockHeaderLineEdit2->text());
    BlockHeader.setDataSetSSize(ui->blockHeaderLineEdit3->text());
    BlockHeader.setPatternCountPSize(ui->blockHeaderLineEdit4->text());
    BlockHeader.setReservedSize(ui->blockHeaderLineEdit5->text());
}
