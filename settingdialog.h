#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>

namespace Ui {
class SettingDialog;
}

class FileHeaderSize //: public QDialog
{
    private:
            int discemmentCodeSize;
            int sourceFileNameSize;
            int compileDateSize;
            int compileTimeSize;
            int compilerVersionSize;
            int flagOfPartExistSize;
            int countOfBlockMSize;
            int offsetsOfCommonSize;
            int offsetsBlockSize;
            int startAddressSize;
            int remarkSize;
            int dataILSize;
            int reservedSize;
   public:
          // 1
          void setDiscemmentCodeSize(int value){discemmentCodeSize=value;}
          int getDiscemmentCodeSize(){return discemmentCodeSize;}
          // 2
          void setSourceFileNameSize(int value){sourceFileNameSize=value;}
          int getSourceFileNameSize(){return sourceFileNameSize;}
          // 3
          void setCompileDateSize(int value){compileDateSize=value;}
          int getCompileDateSize(){return compileDateSize;}
          // 4
          void setCompileTimeSize(int value){compileTimeSize=value;}
          int getCompileTimeSize(){return compileTimeSize;}
          // 5
          void setCompilerVersionSize(int value){compilerVersionSize=value;}
          int getCompilerVersionSize(){return compilerVersionSize;}
          // 6
          void setFlagOfPartExistSize(int value){flagOfPartExistSize=value;}
          int getFlagOfPartExistSize(){return flagOfPartExistSize;}
          // 7
          void setCountOfBlockMSize(int value){countOfBlockMSize=value;}
          int getCountOfBlockMSize(){return countOfBlockMSize;}
          // 8
          void setOffsetsOfCommonSize(int value){offsetsOfCommonSize=value;}
          int getOffsetsOfCommonSize(){return offsetsOfCommonSize;}
          // 9
          void setOffsetsBlockSize(int value){offsetsBlockSize=value;}
          int getOffsetsBlockSize(){return offsetsBlockSize;}
          // 10
          void setStartAddressSize(int value){startAddressSize=value;}
          int getStartAddressSize(){return startAddressSize;}
          // 11
          void setRemarkSize(int value){remarkSize=value;}
          int getRemarkSize(){return remarkSize;}
          // 12
          void setDataILSize(int value){dataILSize=value;}
          int getDataILSize(){return dataILSize;}
          // 13
          void setReservedSize(int value){reservedSize=value;}
          int getReservedSize(){return reservedSize;}

};

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private slots:
    void on_cancelPushButton_clicked();

    void on_defaultPushButton_clicked();

private:
    Ui::SettingDialog *ui;


public:
    FileHeaderSize FileHeader;

    void setFileHeaderAll();
    void setFileHeaderDefault();
    void printFileHeader();

};

#endif // SETTINGDIALOG_H
