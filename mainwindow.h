#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "file.h"
#include "finddialog.h"
#include "settingdialog.h"
#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QByteArray>
#include <QLabel>
#include <QStandardItem>
#include <QTextDocument>
#include <QMessageBox>
#include <QTextCursor>
#include <QTextCharFormat>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendFileHeaderSizeToSettingDialog(FileHeaderSize);
    void sendCommonHeaderSizeToSettingDialog(CommonHeaderSize);
    void sendBlockHeaderSizeToSettingDialog(BlockHeaderSize);
    void sendBlockNumberToSettingDialog(QString);

private slots:

    void receiveKeyword(QString keyword);
    void receiveNextButtonSignal(QString keyword);
    void receiveDialogEndSignal();

    void receiveFileHeaderSize(FileHeaderSize fileHeader);
    void receiveCommonHeaderSize(CommonHeaderSize commonHeader);
    void receiveBlockHeaderSize(BlockHeaderSize blockHeader);
    void receiveBlockNumber(QString blockNumber);

    void on_openButton_clicked();
    void on_clearButton_clicked();
    void on_modifyFindButton_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_settingButton_clicked();

    void on_actionOpen_triggered();

    void on_actionFind_triggered();

    void on_actionSetting_triggered();

private:
    Ui::MainWindow *ui;

public:
    void printFileInformationInLabel();
    void printHexFileInTableWidget();
    void printBinaryFileInTable_Widget2();

    void printFileHeaderInTextEdit();
    void printCommonHeaderInTextEdit();
    void printCommonBodyInTextEdit();
    void printBlockHeaderInTextEdit();
    void printBlockBodyInTextEdit();

    void printFileHeaderDiscemmentCode();
    void printFileHeaderSourceFileName();
    void printFileHeaderCompileDate();
    void printFileHeaderCompileTime();
    void printFileHeaderCompilerVersion();
    void printFileHeaderFlagCommonModuleExist();
    void printFileHeaderCountOfBlock();
    void printFileHeaderOffsetsOfCommon();
    void printFileHeaderOffsetsOfBlocks();
    void printFileHeaderStartAddressArray();
    void printFileHeaderRemark();
    void printFileHeaderDataOfIlMode();
    void printFileHeaderReserved();

    void printCommonHeaderOpcodeNDataSet32_r();
    void printCommonHeaderOpcodeNDataSet64_s();
    void printCommonHeaderReserved();    

    void printCommonBodyRegister32();
    void printCommonBodyRegister64();

    void printBlock1StartAddress();
    void printBlock1HeaderOpcodeNDataSet32_r();
    void printBlock1HeaderOpcodeNDataSet64_s();
    void printBlock1HeaderMicroPatternCount();
    void printBlock1HeaderReaserverd();

    void printBlock1BodyRegister32();
    void printBlock1BodyRegister64();
    void printBlock1BodyMicroPattern();
    void printBlock1Reserved();


    void initVariable();
    void setFileHeaderAddress();
    void setCommonHeaderAddress();
    void setCommonBodyAddress();
    void setBlock1BodyAddress();
    void setDynamicFatFileAddress();

    int  stringToIntLittleEndian(QString hexString);

    QString hexStringToBinaryString(QString hexString);

    void findAllKeyword(QString keyword);
    void findKeywordSequence(QString keyword);

    void setCursorNum(int cursorNum){_cursorNum = cursorNum;}
    int  getCursorNum(){return _cursorNum;}

    void setCursorPosition(int cursorPosition){_cursorPosition = cursorPosition;}
    int  getCursorPosition(){return _cursorPosition;}

    void setIsOpenFile(bool isOpen){_isOpenFile = isOpen;}
    bool getIsOpenFile(){return _isOpenFile;}

    void setBlockNumber(QString number){_blockNumber=number;}
    QString getBlockNumber(){return _blockNumber;}

private:
    File Obj;
    FileHeaderSize FileHeaderObj;
    CommonHeaderSize CommonHeaderObj;
    BlockHeaderSize BlockHeaderObj;

    bool _found;
    bool _isOpenFile = false;
    int _cursorNum;
    int _cursorPosition;
    int _count =0;
    QString _blockNumber = "1";



};

#endif // MAINWINDOW_H
