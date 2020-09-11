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

class FileHeaderSize
{
    private:
            QString discemmentCodeSize ="4";
            QString sourceFileNameSize ="36";
            QString compileDateSize = "8";
            QString compileTimeSize = "8";
            QString compilerVersionSize = "8";
            QString flagOfPartExistSize = "4";
            QString countOfBlockMSize ="4";
            QString offsetsOfCommonSize="4";
            QString offsetsBlockSize ="16384";
            QString startAddressSize="16384";
            QString remarkSize="80";
            QString dataILSize="4";
            QString reservedSize="16";
   public:
          void setDiscemmentCodeSize(QString value){discemmentCodeSize=value;}
          QString getDiscemmentCodeSize(){return discemmentCodeSize;}

          void setSourceFileNameSize(QString value){sourceFileNameSize=value;}
          QString getSourceFileNameSize(){return sourceFileNameSize;}

          void setCompileDateSize(QString value){compileDateSize=value;}
          QString getCompileDateSize(){return compileDateSize;}

          void setCompileTimeSize(QString value){compileTimeSize=value;}
          QString getCompileTimeSize(){return compileTimeSize;}

          void setCompilerVersionSize(QString value){compilerVersionSize=value;}
          QString getCompilerVersionSize(){return compilerVersionSize;}

          void setFlagOfPartExistSize(QString value){flagOfPartExistSize=value;}
          QString getFlagOfPartExistSize(){return flagOfPartExistSize;}

          void setCountOfBlockMSize(QString value){countOfBlockMSize=value;}
          QString getCountOfBlockMSize(){return countOfBlockMSize;}

          void setOffsetsOfCommonSize(QString value){offsetsOfCommonSize=value;}
          QString getOffsetsOfCommonSize(){return offsetsOfCommonSize;}

          void setOffsetsBlockSize(QString value){offsetsBlockSize=value;}
          QString getOffsetsBlockSize(){return offsetsBlockSize;}

          void setStartAddressSize(QString value){startAddressSize=value;}
          QString getStartAddressSize(){return startAddressSize;}

          void setRemarkSize(QString value){remarkSize=value;}
          QString getRemarkSize(){return remarkSize;}

          void setDataILSize(QString value){dataILSize=value;}
          QString getDataILSize(){return dataILSize;}

          void setReservedSize(QString value){reservedSize=value;}
          QString getReservedSize(){return reservedSize;}

};

class CommonHeaderSize
{
        private:
        QString dataSetRsize="4";
        QString dataSetSsize="4";
        QString reservedSize="8";

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
    QString startAddressSize="4";
    QString dataSetRSize="4";
    QString dataSetSSize="4";
    QString patternCountPSize="4";
    QString reservedSize="16";
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

    int commonBodyRegister32_r_Address;
    int commonBodyRegister64_s_Address;


    int block1StartAddress_Address;
    int block1HeaderOpcodeNDataSet32_r_Address;
    int block1HeaderOpcodeNDataSet64_s_Address;
    int block1HeaderMicroPatternCount_Address;
    int block1HeaderReaserverd_Address;

    int block1BodyRegister32_r_Address;
    int block1BodyRegister64_s_Address;
    int block1BodyMicroPattern_Address;
    int block1BodyReserved_Address;
    int block1BodyReserved_size;

    QString blockNum;

public:
     FileHeaderSize FileHeaderObj;
     CommonHeaderSize CommonHeaderObj;
     BlockHeaderSize BlockHeaderObj;
     File(){
         fileHeaderDiscemmentCode_Address = 0; //1
         fileHeaderSourceFileName_Address = 4; //2
         fileHeaderCompileDate_Address = 40; //3
         fileHeaderCompileTime_Address = 48; //4
         fileHeaderCompilerVersion_Address = 56; //5
         fileHeaderFlagCommonModuleExist_Address = 64; //6
         fileHeaderCountOfBlock_Address = 68; //7
         fileHeaderOffsetsOfCommon_Address = 72; //8
         fileHeaderOffsetsOfBlocks_Address = 76; // 9
         fileHeaderStartAddressArray_Address = 16460; // 10
         fileHeaderRemark_Address = 32844; // 11
         fileHeaderDataOfIlMode_Address = 32924; // 12
         fileHeaderReserved_Address = 32928; //13

         commonHeaderOpcodeNDataSet32_r_Address=32944;
         commonHeaderOpcodeNDataSet64_s_Address=32948;
         commonHeaderReserved_Address=32952;

         commonBodyRegister32_r_Address = 0;
         commonBodyRegister64_s_Address = 0;


         block1StartAddress_Address = 0;
         block1HeaderOpcodeNDataSet32_r_Address = 0;
         block1HeaderOpcodeNDataSet64_s_Address = 0;
         block1HeaderMicroPatternCount_Address = 0;
         block1HeaderReaserverd_Address = 0;

         block1BodyRegister32_r_Address = 0;
         block1BodyRegister64_s_Address = 0;
         block1BodyMicroPattern_Address = 0;
         block1BodyReserved_Address = 0;
         block1BodyReserved_size = 0;

         blockNum = "1";
     }

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

     void setCommonBodyRegister32_r_Address(int value){commonBodyRegister32_r_Address=value;}
     int getCommonBodyRegister32_r_Address(){return commonBodyRegister32_r_Address;}
     void setCommonBodyRegister64_s_Address(int value){commonBodyRegister64_s_Address=value;}
     int getCommonBodyRegister64_s_Address(){return commonBodyRegister64_s_Address;}


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

     void setBlock1BodyRegister32_r_Address(int value){block1BodyRegister32_r_Address=value;}
     int getBlock1BodyRegister32_r_Address(){return block1BodyRegister32_r_Address;}
     void setBlock1BodyRegister64_s_Address(int value){block1BodyRegister64_s_Address=value;}
     int getBlock1BodyRegister64_s_Address(){return block1BodyRegister64_s_Address;}
     void setBlock1BodyMicroPattern_Address(int value){block1BodyMicroPattern_Address=value;}
     int getBlock1BodyMicroPattern_Address(){return block1BodyMicroPattern_Address;}
     void setBlock1BodyReserved_Address(int value){block1BodyReserved_Address=value;}
     int getBlock1BodyReserved_Address(){return block1BodyReserved_Address;}

     void setBlock1BodyReserved_size(int value){block1BodyReserved_size = value;}
     int getblock1BodyReserved_size(){return block1BodyReserved_size;}

     void setBlockNumber(QString value){blockNum = value;}
     QString getBlockNumber(){return blockNum;}

     int getFileSize(){return _patFile.length();}

  public:
    QString getFilePath();
    bool readPatFile(); // Open patFile
    void setPatFile(QByteArray data);


    QByteArray readAll(); // get patFile

    QByteArray readPatFile(int startAddress,int endAddress);


};

/*
//File Header : 0 ~ 32944 (total : 32944 byte)
1.  readFileHeaderDiscemmentCode() format     | size : 4 byte  | scope : 0~4    | HEX
2.  readFileHeaderSourceFileName format       | size : 36 byte | scope : 4~40   | ASCII
3.  readFileHeaderCompileDate format          | size : 8 byte  | scope : 40~48  | ASCII
4.  readFileHeaderCompileTime format          | size : 8 byte  | scope : 48~56  | ASCII
5.  readFileHeaderCompilerVersion format      | size : 8 byte  | scope : 56~64  | ASCII
6.  readFileHeaderFlagCommonModuleExist format| size : 4 byte  | scope : 64~68  | HEX
7.  readFileHeaderCountOfBlock() format       | size : 4 byte  | scope : 68~72  | HEX
8.  readFileHeaderOffsetsOfCommon format      | size : 4 byte  | scope : 72~76  | HEX
9.  readFileHeaderOffsetsOfBlocks format      | size : 16384 byte| scope : 76~16460 | HEX
10.  readFileHeaderStartAddressArray format   | size : 16384 byte| scope : 16460~32844| HEX
11.  readFileHeaderRemark format              | size : 80 byte | scope : 32844~32924| HEX
12.  readFileHeaderDataOfIlMode format        | size : 4 byte  | scope : 32924~32928| HEX
13.  readFileHeaderReserved format            | size : 16 byte | scope : 32928~32944| HEX
//Common Header 32944 ~ 32960(total : 16 byte)
14.  readCommonHeaderOpcodeNDataSet32 format | size : 4 byte  | scope : 32944~32948 | HEX
15.  readCommonHeaderOpcodeNDataSet64 format | size : 4 byte  | scope : 32948~32952 | HEX
16.  readCommonHeaderReserved format         | size : 8 byte  | scope : 32952~32960 | HEX
// Common Reserver(flexible & variable value) 32960~33552(total : 592 byte , r =62, s = 8) *add Division line FFFFF FFFFF FFFFF
17. readCommonBodyRegister32_r format          | scope:32960~33456
18. readCommonBodyRegister64_s format          | scope:33456~33567
//Block Header
 19. readBlock1StartAddress             format | size : 4 byte | scope : 33567 ~ 33571 | HEX
 20. readBlock1HeaderOpcodeNDataSet32_r format | size : 4 byte | scope : 33571 ~ 33575 | HEX
 21. readBlock1HeaderOpcodeNDataSet64_s format | size : 4 byte | scope : 33575 ~ 33579 | HEX
 22. readBlock1HeaderMicroPatternCount  format | size : 4 byte | scope : 33579 ~ 33583 | HEX
 23. readBlock1HeaderReaserverd         format | size : 16 byte| scope : 33583 ~ 33598 | HEX
 //Block1 Body(Register 32 bit, Register 64 bit , Micro Pattern , Reserved)
 24. readBlock1BodyRegister32 format | scope:33599~34007
 25. readBlock1BodyRegister64 format | scope:34007~34079
 26. readBlock1BodyMicroPattern format |
 //Block1 Body Reserverd 75722 ~ 75738 (Reserved : 16 byte, data : FFFF FFFF FFFF FFFF)
 //what is it? 75738 ~ 76004(total : 266 byte)
 */

#endif // FILE_H
