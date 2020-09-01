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
    printFileHeader();
}

void SettingDialog::setFileHeaderDefault()
{
    FileHeader.setDiscemmentCodeSize(4);
    FileHeader.setSourceFileNameSize(36);
    FileHeader.setCompileDateSize(8);
    FileHeader.setCompileTimeSize(8);
    FileHeader.setCompilerVersionSize(8);
    FileHeader.setFlagOfPartExistSize(4);
    FileHeader.setCountOfBlockMSize(4);
    FileHeader.setOffsetsOfCommonSize(4);
    FileHeader.setOffsetsBlockSize(16384);
    FileHeader.setStartAddressSize(16384);
    FileHeader.setRemarkSize(80);
    FileHeader.setDataILSize(4);
    FileHeader.setReservedSize(16);
    qDebug()<<FileHeader.getDiscemmentCodeSize();
}

void SettingDialog::printFileHeader()
{
    qDebug()<<(QString)FileHeader.getDiscemmentCodeSize();

    ui->fileHeaderLineEdit1->setText((QString)FileHeader.getDiscemmentCodeSize());
    ui->fileHeaderLineEdit2->setText((QString)FileHeader.getSourceFileNameSize());
    ui->fileHeaderLineEdit3->setText((QString)FileHeader.getCompileDateSize());
    ui->fileHeaderLineEdit4->setText((QString)FileHeader.getCompileTimeSize());
    ui->fileHeaderLineEdit5->setText((QString)FileHeader.getCompilerVersionSize());
    ui->fileHeaderLineEdit6->setText((QString)FileHeader.getFlagOfPartExistSize());
    ui->fileHeaderLineEdit7->setText((QString)FileHeader.getCountOfBlockMSize());
    ui->fileHeaderLineEdit8->setText((QString)FileHeader.getOffsetsOfCommonSize());
    ui->fileHeaderLineEdit9->setText((QString)FileHeader.getOffsetsBlockSize());
    ui->fileHeaderLineEdit10->setText((QString)FileHeader.getStartAddressSize());
    ui->fileHeaderLineEdit11->setText((QString)FileHeader.getRemarkSize());
    ui->fileHeaderLineEdit12->setText((QString)FileHeader.getDataILSize());
    ui->fileHeaderLineEdit13->setText((QString)FileHeader.getReservedSize());

}
