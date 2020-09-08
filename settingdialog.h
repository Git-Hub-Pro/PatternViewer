#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <file.h>

namespace Ui {
class SettingDialog;
}
class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void receiveFileHeaderSizeFromMainWindow(FileHeaderSize fileHeadersize);
    void receiveCommonHeaderSizeFromMainWindow(CommonHeaderSize commonHeaderSize);
    void receiveBlockHeaderSizeFromMainWindow(BlockHeaderSize blockHeaderSize);
    void receiveBlockNumberFromMainWindow(QString blockNumber);

    void on_cancelPushButton_clicked();
    void on_defaultPushButton_clicked();
    void on_applyPushButton_clicked();

signals:
        void sendFileHeaderSize(FileHeaderSize fileHeader);
        void sendCommonHeaderSize(CommonHeaderSize commonHeader);
        void sendBlockHeaderSize(BlockHeaderSize blockHeader);
        void sendBlockNumber(QString number);


private:
    Ui::SettingDialog *ui;


public:
    FileHeaderSize _FileHeader;
    CommonHeaderSize _CommonHeader;
    BlockHeaderSize _BlockHeader;
    QString _blockNum = "1";

    void setFileHeaderAll();
    void setCommonHeaderAll();
    void setBlockHeaderAll();
    void setBlockNumFromTextEdit();

    void setBlockNum(QString num){_blockNum = num;}
    QString getBlockNum(){return _blockNum;}

    void setFileHeaderDefault();
    void setCommonHeaderDefault();
    void setBlockHeaderDefault();
    void setBlockNumDefault(){_blockNum = "1";}


    void printFileHeader();
    void printCommonHeader();
    void printBlockHeader();
    void printBlockNum();



};

#endif // SETTINGDIALOG_H
