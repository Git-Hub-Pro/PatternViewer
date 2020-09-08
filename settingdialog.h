#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
#include <file.h>
#include <QMessageBox>

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
    void receiveFileSizeFromMainWindow(int fileSize);

    void on_cancelPushButton_clicked();
    void on_defaultPushButton_clicked();
    void on_applyPushButton_clicked();

signals:
        void sendFileHeaderSizeToMainWindow(FileHeaderSize fileHeader);
        void sendCommonHeaderSizeToMainWindow(CommonHeaderSize commonHeader);
        void sendBlockHeaderSizeToMainWindow(BlockHeaderSize blockHeader);
        void sendBlockNumberToMainWindow(QString number);


private:
    Ui::SettingDialog *ui;


public:
    FileHeaderSize _FileHeader;
    CommonHeaderSize _CommonHeader;
    BlockHeaderSize _BlockHeader;
    QString _blockNum = "1";
    int _fileSize = 0;

    void setFileHeaderAll();
    void setCommonHeaderAll();
    void setBlockHeaderAll();
    void setBlockNumFromTextEdit();

    void setBlockNum(QString num){_blockNum = num;}
    QString getBlockNum(){return _blockNum;}

    void setFileSize(int size){_fileSize = size;}
    int getFileSize(){return _fileSize;}

    void setFileHeaderDefault();
    void setCommonHeaderDefault();
    void setBlockHeaderDefault();
    void setBlockNumDefault(){_blockNum = "1";}

    bool checkError();


    void printFileHeader();
    void printCommonHeader();
    void printBlockHeader();
    void printBlockNum();

    void constraintInputbyInt();

};

#endif // SETTINGDIALOG_H
