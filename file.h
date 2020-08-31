#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QDataStream>
#include <QCoreApplication>

class File : public QWidget
{

private:
    QByteArray _patFile;


public:
    QString getFilePath();

    bool readPatFile(); // Open patFile
    void setPatFile(QByteArray data);


    QByteArray readAll(); // get patFile

    //File Header : 0 ~ 32944 (total : 32944 byte)
    QByteArray readFileHeaderDiscemmentCode();          // 1.  readFileHeaderDiscemmentCode() format     | size : 4 byte  | scope : 0~4    | HEX
    QByteArray readFileHeaderSourceFileName();          // 2.  readFileHeaderSourceFileName format       | size : 36 byte | scope : 4~40   | ASCII
    QByteArray readFileHeaderCompileDate();             // 3.  readFileHeaderCompileDate format          | size : 8 byte  | scope : 40~48  | ASCII
    QByteArray readFileHeaderCompileTime();             // 4.  readFileHeaderCompileTime format          | size : 8 byte  | scope : 48~56  | ASCII
    QByteArray readFileHeaderCompilerVersion();         // 5.  readFileHeaderCompilerVersion format      | size : 8 byte  | scope : 56~64  | ASCII
    QByteArray readFileHeaderFlagCommonModuleExist();   // 6.  readFileHeaderFlagCommonModuleExist format| size : 4 byte  | scope : 64~68  | HEX
    QByteArray readFileHeaderCountOfBlock();            // 7.  readFileHeaderCountOfBlock() format       | size : 4 byte  | scope : 68~72  | HEX
    QByteArray readFileHeaderOffsetsOfCommon();         // 8.  readFileHeaderOffsetsOfCommon format      | size : 4 byte  | scope : 72~76  | HEX
    QByteArray readFileHeaderOffsetsOfBlocks();         // 9.  readFileHeaderOffsetsOfBlocks format      | size : 16384 byte| scope : 76~16460 | HEX
    QByteArray readFileHeaderStartAddressArray();       // 10.  readFileHeaderStartAddressArray format   | size : 16384 byte| scope : 16460~32844| HEX
    QByteArray readFileHeaderRemark();                  // 11.  readFileHeaderRemark format              | size : 80 byte | scope : 32844~32924| HEX
    QByteArray readFileHeaderDataOfIlMode();            // 12.  readFileHeaderDataOfIlMode format        | size : 4 byte  | scope : 32924~32928| HEX
    QByteArray readFileHeaderReserved();                // 13.  readFileHeaderReserved format            | size : 16 byte | scope : 32928~32944| HEX

    //Common Header 32944 ~ 32960(total : 16 byte)
    QByteArray readCommonHeaderOpcodeNDataSet32_r();    // 14.  readCommonHeaderOpcodeNDataSet32 format | size : 4 byte  | scope : 32944~32948 | success
    QByteArray readCommonHeaderOpcodeNDataSet64_s();    // 15.  readCommonHeaderOpcodeNDataSet64 format | size : 4 byte  | scope : 32948~32952 | success
    QByteArray readCommonHeaderReserved();              // 16.  readCommonHeaderReserved format         | size : 8 byte  | scope : 32952~32960 | success


    // Common Reserver(flexible & variable value) 32960~33552(total : 592 byte , r =62, s = 8)




    //Block Header
     QByteArray readBlock1StartAddress();             // 17. readBlock1StartAddress             format | size : 4 byte | scope : 33567 ~ 33571 |
     QByteArray readBlock1HeaderOpcodeNDataSet32_r(); // 18. readBlock1HeaderOpcodeNDataSet32_r format | size : 4 byte | scope : 33571 ~ 33575 |
     QByteArray readBlock1HeaderOpcodeNDataSet64_s(); // 19. readBlock1HeaderOpcodeNDataSet64_s format | size : 4 byte | scope : 33575 ~ 33579 |
     QByteArray readBlock1HeaderMicroPatternCount();  // 20. readBlock1HeaderMicroPatternCount  format | size : 4 byte | scope : 33579 ~ 33583 |
     QByteArray readBlock1HeaderReaserverd();         // 21. readBlock1HeaderReaserverd         format | size : 16 byte| scope : 33583 ~ 33598 |


};

#endif // FILE_H
