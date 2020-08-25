#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

class File : public QWidget
{

private:
    QByteArray _patFile;


public:
    QString getFilePath();

    void readPatFile(); // Open patFile
    void setPatFile(QByteArray data);


    QByteArray readAll(); // get patFile

    //File Header : 0 ~ 688
    QByteArray readFileHeaderDiscemmentCode();        // 1.  readFileHeaderDiscemmentCode() format | size : 4 byte  | scope : 0~4    | HEX
    QByteArray readFileHeaderSourceFileName();        // 2.  readFileHeaderSourceFileName format | size : 36 byte | scope : 4~40   | ASCII
    QByteArray readFileHeaderCompileDate();           // 3.  readFileHeaderCompileDate format | size : 8 byte  | scope : 40~48  | ASCII
    QByteArray readFileHeaderCompileTime();           // 4.  readFileHeaderCompileTime format | size : 8 byte  | scope : 48~56  | ASCII
    QByteArray readFileHeaderCompilerVersion();       // 5.  readFileHeaderCompilerVersion format | size : 8 byte  | scope : 56~64  | ASCII
    QByteArray readFileHeaderFlagCommonModuleExist(); // 6.  readFileHeaderFlagCommonModuleExist format | size : 4 byte  | scope : 64~68  | HEX
    QByteArray readFileHeaderCountOfBlock();          // 7.  readFileHeaderCountOfBlock() format | size : 4 byte  | scope : 68~72  | HEX
    QByteArray readFileHeaderOffsetsOfCommon();       // 8.  readFileHeaderOffsetsOfCommon format | size : 4 byte  | scope : 72~76  | HEX
    QByteArray readFileHeaderOffsetsOfBlocks();       // 9.  readFileHeaderOffsetsOfBlocks format | size : 256 byte| scope : 76~332 | HEX
    QByteArray readFileHeaderStartAddressArray();     // 10. readFileHeaderStartAddressArray | size : 256 byte| scope : 332~588| HEX
    QByteArray readFileHeaderRemark();                // 11. readFileHeaderRemark | size : 80 byte | scope : 588~668| HEX
    QByteArray readFileHeaderDataOfIlMode();          // 12. readFileHeaderDataOfIlMode | size : 4 byte  | scope : 668~672| HEX
    QByteArray readFileHeaderReserved();              // 13. readFileHeaderReserved | size : 16 byte | scope : 672~688| HEX

    //Common Header 688 ~ 704
    QByteArray readCommonHeaderOpcodeNDataSet32();   // 14.  readCommonHeaderOpcodeNDataSet32 format | size : 4 byte  | scope : 688~692    | HEX
    QByteArray readCommonHeaderOpcodeNDataSet64();   // 15.  readCommonHeaderOpcodeNDataSet64 format | size : 4 byte | scope : 692~696   | HEX
    QByteArray readCommonHeaderReserved();           // 16.  readCommonHeaderReserved format | size : 8 byte  | scope : 696~704  | HEX




};

#endif // FILE_H
