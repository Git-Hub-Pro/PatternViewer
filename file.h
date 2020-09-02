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
    int fileHeaderDiscemmentCode_Address; //1
    int fileHeaderSourceFileName_Address; //2
    int fileHeaderCompileDate_Address; //3
    int fileHeaderCompileTime_Address; //4
    int fileHeaderCompilerVersion_Address; //5
    int fileHeaderFlagCommonModuleExist_Address; //6
    int fileHeaderCountOfBlock_Address; //7
    int fileHeaderOffsetsOfCommon_Address; //8
    int fileHeaderOffsetsOfBlocks_Address; // 9
    int fileHeaderStartAddressArray_Address; // 10
    int fileHeaderRemark_Address; // 11
    int fileHeaderDataOfIlMode_Address; // 12
    int fileHeaderReserved_Address; //13

    int commonHeaderOpcodeNDataSet32_r_Address;
    int commonHeaderOpcodeNDataSet64_s_Address;
    int commonHeaderReserved_Address;

    int block1StartAddress_Address;
    int block1HeaderOpcodeNDataSet32_r_Address;
    int block1HeaderOpcodeNDataSet64_s_Address;
    int block1HeaderMicroPatternCount_Address;
    int block1HeaderReaserverd_Address;

public:
     void setFileHeaderDiscemmentCode_Address(int value){fileHeaderDiscemmentCode_Address=value;}
     int getFileHeaderDiscemmentCode_Address(){return fileHeaderDiscemmentCode_Address;}
     void setFileHeaderSourceFileName_Address(int value){fileHeaderSourceFileName_Address=value;}
     int getFileHeaderSourceFileName_Address(){return fileHeaderSourceFileName_Address;}
     void setFileHeaderCompileDate_Address(int value){fileHeaderCompileDate_Address=value;}
     int getFileHeaderCompileDate_Address(){return fileHeaderCompileDate_Address;}
     void setFileHeaderCompileTime_Address(int value){fileHeaderCompileTime_Address=value;}
     int getFileHeaderCompileTime_Address(){return fileHeaderCompileTime_Address;}
     void setFileHeaderCompilerVersion_Address(int value){fileHeaderCompilerVersion_Address=value;}
     int getFileHeaderCompilerVersion_Address(){return fileHeaderCompilerVersion_Address;}
     void setFileHeaderFlagCommonModuleExist_Address(int value){fileHeaderFlagCommonModuleExist_Address=value;}
     int getFileHeaderFlagCommonModuleExist_Address(){return fileHeaderFlagCommonModuleExist_Address;}
     void setFileHeaderCountOfBlock_Address(int value){fileHeaderCountOfBlock_Address=value;}
     int getFileHeaderCountOfBlock_Address(){return fileHeaderCountOfBlock_Address;}
     void setFileHeaderOffsetsOfCommon_Address(int value){fileHeaderOffsetsOfCommon_Address=value;}
     int getFileHeaderOffsetsOfCommon_Address(){return fileHeaderOffsetsOfCommon_Address;}
     void setFileHeaderOffsetsOfBlocks_Address(int value){fileHeaderOffsetsOfBlocks_Address=value;}
     int getFileHeaderOffsetsOfBlocks_Address(){return fileHeaderOffsetsOfBlocks_Address;}
     void setFileHeaderStartAddressArray_Address(int value){fileHeaderStartAddressArray_Address=value;}
     int getFileHeaderStartAddressArray_Address(){return fileHeaderStartAddressArray_Address;}
     void setFileHeaderRemark_Address(int value){fileHeaderRemark_Address=value;}
     int getFileHeaderRemark_Address(){return fileHeaderRemark_Address;}
     void setFileHeaderDataOfIlMode_Address(int value){fileHeaderDataOfIlMode_Address=value;}
     int getFileHeaderDataOfIlMode_Address(){return fileHeaderDataOfIlMode_Address;}
     void setFileHeaderReserved_Address(int value){fileHeaderReserved_Address=value;}
     int getFileHeaderReserved_Address(){return fileHeaderReserved_Address;}

     void setCommonHeaderOpcodeNDataSet32_r_Address(int value){commonHeaderOpcodeNDataSet32_r_Address=value;}
     int getCommonHeaderOpcodeNDataSet32_r_Address(){return commonHeaderOpcodeNDataSet32_r_Address;}
     void setCommonHeaderOpcodeNDataSet64_s_Address(int value){commonHeaderOpcodeNDataSet64_s_Address=value;}
     int getCommonHeaderOpcodeNDataSet64_s_Address(){return commonHeaderOpcodeNDataSet64_s_Address;}
     void setCommonHeaderReserved_Address(int value){commonHeaderReserved_Address=value;}
     int getCommonHeaderReserved_Address(){return commonHeaderReserved_Address;}

     void setBlock1StartAddress_Address(int value){block1StartAddress_Address=value;}
     int getBlock1StartAddress_Address(){return block1StartAddress_Address;}
     void setBlock1HeaderOpcodeNDataSet32_r_Address(int value){block1HeaderOpcodeNDataSet32_r_Address=value;}
     int getBlock1HeaderOpcodeNDataSet32_r_Address(){return block1HeaderOpcodeNDataSet32_r_Address;}
     void setBlock1HeaderOpcodeNDataSet64_s_Address(int value){block1HeaderOpcodeNDataSet64_s_Address=value;}
     int getBlock1HeaderOpcodeNDataSet64_s_Address(){return block1HeaderOpcodeNDataSet64_s_Address;}
     void setBlock1HeaderMicroPatternCount_Address(int value){block1HeaderMicroPatternCount_Address=value;}
     int getBlock1HeaderMicroPatternCount_Address(){return block1HeaderMicroPatternCount_Address;}

     void setBlock1HeaderReaserverd_Address(int value){block1HeaderReaserverd_Address=value;}
     int getBlock1HeaderReaserverd_Address(){return block1HeaderReaserverd_Address;}


// public:
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
    QByteArray readCommonHeaderOpcodeNDataSet32_r();    // 14.  readCommonHeaderOpcodeNDataSet32 format | size : 4 byte  | scope : 32944~32948 | HEX
    QByteArray readCommonHeaderOpcodeNDataSet64_s();    // 15.  readCommonHeaderOpcodeNDataSet64 format | size : 4 byte  | scope : 32948~32952 | HEX
    QByteArray readCommonHeaderReserved();              // 16.  readCommonHeaderReserved format         | size : 8 byte  | scope : 32952~32960 | HEX


    // Common Reserver(flexible & variable value) 32960~33552(total : 592 byte , r =62, s = 8) *add Division line FFFFF FFFFF FFFFF


    //Block Header
     QByteArray readBlock1StartAddress();             // 17. readBlock1StartAddress             format | size : 4 byte | scope : 33567 ~ 33571 | HEX
     QByteArray readBlock1HeaderOpcodeNDataSet32_r(); // 18. readBlock1HeaderOpcodeNDataSet32_r format | size : 4 byte | scope : 33571 ~ 33575 | HEX
     QByteArray readBlock1HeaderOpcodeNDataSet64_s(); // 19. readBlock1HeaderOpcodeNDataSet64_s format | size : 4 byte | scope : 33575 ~ 33579 | HEX
     QByteArray readBlock1HeaderMicroPatternCount();  // 20. readBlock1HeaderMicroPatternCount  format | size : 4 byte | scope : 33579 ~ 33583 | HEX
     QByteArray readBlock1HeaderReaserverd();         // 21. readBlock1HeaderReaserverd         format | size : 16 byte| scope : 33583 ~ 33598 | HEX


     //Block1 Body(Register 32 bit, Register 64 bit , Micro Pattern , Reserved)



     //BlockReserverd 75722 ~ 75738 (Reserved : 16 byte, data : FFFF FFFF FFFF FFFF)




     //what is it? 75738 ~ 76004(total : 266 byte)



};

#endif // FILE_H
