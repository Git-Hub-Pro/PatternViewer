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
    void on_cancelPushButton_clicked();
    void on_defaultPushButton_clicked();
    void on_applyPushButton_clicked();

signals:
        void sendFileHeaderSize(FileHeaderSize fileHeader);
        void sendCommonHeaderSize(CommonHeaderSize commonHeader);
        void sendBlockHeaderSize(BlockHeaderSize blockHeader);


private:
    Ui::SettingDialog *ui;


public:
    FileHeaderSize FileHeader;
    CommonHeaderSize CommonHeader;
    BlockHeaderSize BlockHeader;

    void setFileHeaderAll();
    void setCommonHeaderAll();
    void setBlockHeaderAll();

    void setFileHeaderDefault();
    void setCommonHeaderDefault();
    void setBlockHeaderDefault();

    void printFileHeader();
    void printCommonHeader();
    void printBlockHeader();




};

#endif // SETTINGDIALOG_H
