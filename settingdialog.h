#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QString>
#include <QDebug>
namespace Ui {
class SettingDialog;
}

class FileHeaderSize
{
    private:
            QString discemmentCodeSize;
            QString sourceFileNameSize;
            QString compileDateSize;
            QString compileTimeSize;
            QString compilerVersionSize;
            QString flagOfPartExistSize;
            QString countOfBlockMSize;
            QString offsetsOfCommonSize;
            QString offsetsBlockSize;
            QString startAddressSize;
            QString remarkSize;
            QString dataILSize;
            QString reservedSize;
   public:
          // 1
          void setDiscemmentCodeSize(QString value){discemmentCodeSize=value;}
          QString getDiscemmentCodeSize(){return discemmentCodeSize;}
          // 2
          void setSourceFileNameSize(QString value){sourceFileNameSize=value;}
          QString getSourceFileNameSize(){return sourceFileNameSize;}
          // 3
          void setCompileDateSize(QString value){compileDateSize=value;}
          QString getCompileDateSize(){return compileDateSize;}
          // 4
          void setCompileTimeSize(QString value){compileTimeSize=value;}
          QString getCompileTimeSize(){return compileTimeSize;}
          // 5
          void setCompilerVersionSize(QString value){compilerVersionSize=value;}
          QString getCompilerVersionSize(){return compilerVersionSize;}
          // 6
          void setFlagOfPartExistSize(QString value){flagOfPartExistSize=value;}
          QString getFlagOfPartExistSize(){return flagOfPartExistSize;}
          // 7
          void setCountOfBlockMSize(QString value){countOfBlockMSize=value;}
          QString getCountOfBlockMSize(){return countOfBlockMSize;}
          // 8
          void setOffsetsOfCommonSize(QString value){offsetsOfCommonSize=value;}
          QString getOffsetsOfCommonSize(){return offsetsOfCommonSize;}
          // 9
          void setOffsetsBlockSize(QString value){offsetsBlockSize=value;}
          QString getOffsetsBlockSize(){return offsetsBlockSize;}
          // 10
          void setStartAddressSize(QString value){startAddressSize=value;}
          QString getStartAddressSize(){return startAddressSize;}
          // 11
          void setRemarkSize(QString value){remarkSize=value;}
          QString getRemarkSize(){return remarkSize;}
          // 12
          void setDataILSize(QString value){dataILSize=value;}
          QString getDataILSize(){return dataILSize;}
          // 13
          void setReservedSize(QString value){reservedSize=value;}
          QString getReservedSize(){return reservedSize;}

};

class CommonHeaderSize
{
        private:
        QString dataSetRsize;
        QString dataSetSsize;
        QString reservedSize;

        public:
        void setDataSetRsize(QString value){dataSetRsize=value;}
        QString getDataSetRsize(){return dataSetRsize;}

        void setDataSetSsize(QString value){dataSetSsize=value;}
        QString getDataSetSsize(){return dataSetSsize;}

        void setReservedSize(QString value){reservedSize=value;}
        QString getReservedSize(){return reservedSize;}

};
class BlockHeaderSize
{
private:
    QString startAddressSize;
    QString dataSetRSize;
    QString dataSetSSize;
    QString patternCountPSize;
    QString reservedSize;
public:
    void setStartAddressSize(QString value){startAddressSize=value;}
    QString getStartAddressSize(){return startAddressSize;}

    void setDataSetRSize(QString value){dataSetRSize=value;}
    QString getDataSetRSize(){return dataSetRSize;}

    void setDataSetSSize(QString value){dataSetSSize=value;}
    QString getDataSetSSize(){return dataSetSSize;}

    void setPatternCountPSize(QString value){patternCountPSize=value;}
    QString getPatternCountPSize(){return patternCountPSize;}

    void setReservedSize(QString value){reservedSize=value;}
    QString getReservedSize(){return reservedSize;}

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
    CommonHeaderSize CommonHeader;
    BlockHeaderSize BlockHeader;

    void setFileHeaderAll();

    void setFileHeaderDefault();
    void setCommonHeaderDefault();
    void setBlockHeaderDefault();

    void printFileHeader();
    void printCommonHeader();
    void printBlockHeader();




};

#endif // SETTINGDIALOG_H
