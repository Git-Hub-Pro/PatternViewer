#include "file.h"

QString File::getFilePath()
{

    QString filePath = QFileDialog::getOpenFileName(this,
          tr("Open Image"), "/home/unitest/Documents/QT", tr("Image Files (*.png *.jpg *.bmp *.pat);;Text files (*.txt)"));

    return filePath;
}

bool File::readPatFile()
{
    File Obj;

    QString filePath = Obj.getFilePath();

    QFile file(filePath);

    if (!(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)))
        return false;

    _patFile  = file.readAll();

    return true;
}


QByteArray File::readAll()
{
    return _patFile;
}

void File::setPatFile(QByteArray data)
{
    _patFile = data;
}

QByteArray File::readFileHeaderDiscemmentCode()
{
    // 1. fileHeaderDiscemmentCode format | size : 4 byte  | scope : 0~4

    QByteArray fileHeaderDiscemmentCode;

    for(int i=0;i<4;i++)
    {
       fileHeaderDiscemmentCode.append(_patFile.at(i));
    }

    return fileHeaderDiscemmentCode;
}

QByteArray File::readFileHeaderSourceFileName()
{
    // 2. fileHeaderSourceFileName format | size : 36 byte | scope : 4~40

    QByteArray fileHeaderSourceFileName;

    for(int i=4;i<40;i++)
    {
       fileHeaderSourceFileName.append(_patFile.at(i));
    }

    return fileHeaderSourceFileName;

}

QByteArray File::readFileHeaderCompileDate()
{
    // 3. readFileHeaderCompileDate | size : 8 byte  | scope : 40~48

    QByteArray fileHeaderCompileDate;

    for(int i=40;i<48;i++)
    {
       fileHeaderCompileDate.append(_patFile.at(i));
    }

    return fileHeaderCompileDate;
}

QByteArray File::readFileHeaderCompileTime()
{
    // 4. readFileHeaderCompileTime format | size : 8 byte  | scope : 48~56
    QByteArray fileHeaderCompileTime;

    for(int i=48;i<56;i++)
    {
       fileHeaderCompileTime.append(_patFile.at(i));
    }

    return fileHeaderCompileTime;

}

QByteArray File::readFileHeaderCompilerVersion()
{
    // 5. readFileHeaderCompilerVersion format |  size : 8 byte  | scope : 56~64

    QByteArray fileHeaderCompilerVersion;

    for(int i=56;i<64;i++)
    {
       fileHeaderCompilerVersion.append(_patFile.at(i));
    }

    return fileHeaderCompilerVersion;

}

QByteArray File::readFileHeaderFlagCommonModuleExist()
{
    // 6. readFileHeaderFlagCommonModuleExist format | size : 4 byte  | scope : 64~68
    QByteArray fileHeaderFlagCommonModuleExist;

    for(int i=64;i<68;i++)
    {
       fileHeaderFlagCommonModuleExist.append(_patFile.at(i));
    }

    return fileHeaderFlagCommonModuleExist;
}

QByteArray File::readFileHeaderCountOfBlock()
{
   // 7. readFileHeaderCountOfBlock() format | size : 4 byte  | scope : 68~72  |
    QByteArray fileHeaderCountOfBlock;

    for(int i=68;i<72;i++)
    {
       fileHeaderCountOfBlock.append(_patFile.at(i));
    }

    return fileHeaderCountOfBlock;

}
QByteArray File::readFileHeaderOffsetsOfCommon()
{
    // 8. readFileHeaderOffsetsOfCommon format | size : 4 byte  | scope : 72~76  |
    QByteArray fileHeaderOffsetsOfCommon;

    for(int i=72;i<76;i++)
    {
       fileHeaderOffsetsOfCommon.append(_patFile.at(i));
    }

    return fileHeaderOffsetsOfCommon;
}

QByteArray File::readFileHeaderOffsetsOfBlocks()
{
    // 9. readFileHeaderOffsetsOfBlocks format | size : 16384 byte| scope : 76~16460 |
    QByteArray fileHeaderOffsetsOfBlocks;

    for(int i=76;i<16460;i++)
    {
       fileHeaderOffsetsOfBlocks.append(_patFile.at(i));
    }

    return fileHeaderOffsetsOfBlocks;

}

QByteArray File::readFileHeaderStartAddressArray()
{
    // 10. readFileHeaderStartAddressArray | size : 16384 byte| scope : 16460~32844|
    QByteArray fileHeaderStartAddressArray;

    for(int i=16460;i<32844;i++)
    {
       fileHeaderStartAddressArray.append(_patFile.at(i));
    }

    return fileHeaderStartAddressArray;
}

QByteArray File::readFileHeaderRemark()
{
    // 11. readFileHeaderRemark | size : 80 byte | scope : 32844~32924| HEX
    QByteArray fileHeaderRemark;

    for(int i=32844;i<32924;i++)
    {
       fileHeaderRemark.append(_patFile.at(i));
    }

    return fileHeaderRemark;

}

QByteArray File::readFileHeaderDataOfIlMode()
{
    // 12. readFileHeaderDataOfIlMode | size : 4 byte  | scope : 32924~32928|

    QByteArray fileHeaderDataOfIlMode;

    for(int i=32924;i<32928;i++)
    {
       fileHeaderDataOfIlMode.append(_patFile.at(i));
    }

    return fileHeaderDataOfIlMode;

}

QByteArray File::readFileHeaderReserved()
{
    // 13. readFileHeaderReserved | size : 16 byte | scope : 32928~32944|
    QByteArray fileHeaderReserved;

    for(int i=32928;i<32944;i++)
    {
       fileHeaderReserved.append(_patFile.at(i));
    }

    return fileHeaderReserved;

}


QByteArray File::readCommonHeaderOpcodeNDataSet32_r()
{
    // 14. readCommonHeaderOpcodeNDataSet32 format | size : 4 byte  | scope : 32944~32948
    QByteArray commonHeaderOpcodeNDataSet32;

    for(int i=32944;i<32948;i++)
    {
       commonHeaderOpcodeNDataSet32.append(_patFile.at(i));
    }

    return commonHeaderOpcodeNDataSet32;
}

QByteArray File::readCommonHeaderOpcodeNDataSet64_s()
{
    // 15. readCommonHeaderOpcodeNDataSet64 format | size : 4 byte | scope : 32948~32952
    QByteArray commonHeaderOpcodeNDataSet64;

    for(int i=32948;i<32952;i++)
    {
       commonHeaderOpcodeNDataSet64.append(_patFile.at(i));
    }

    return commonHeaderOpcodeNDataSet64;

}

QByteArray File::readCommonHeaderReserved()
{
    // 16. readCommonHeaderReserved format | size : 8 byte  | scope : 32952~32960  | success
    QByteArray commonHeaderReserved;


    for(int i=32952;i<32960;i++)
    {
       commonHeaderReserved.append(_patFile.at(i));
    }

    return commonHeaderReserved;

}

QByteArray File::readBlock1StartAddress()
{
    // 17. readBlock1StartAddress             format | size : 4 byte | scope : 33567 ~ 33571 |
    QByteArray block1StartAddress;

    for(int i=33567;i<33571;i++)
    {
         block1StartAddress.append(_patFile.at(i));        
    }

    return block1StartAddress;
}

QByteArray File::readBlock1HeaderOpcodeNDataSet32_r()
{
    // 18. readBlock1HeaderOpcodeNDataSet32_r format | size : 4 byte | scope : 33571 ~ 33575 |
    QByteArray block1HeaderOpcodeNDataSet32_r;

    for(int i=33571;i<33575;i++)
    {
       block1HeaderOpcodeNDataSet32_r.append(_patFile.at(i));
    }

    return block1HeaderOpcodeNDataSet32_r;
}

QByteArray File::readBlock1HeaderOpcodeNDataSet64_s()
{
    // 19. readBlock1HeaderOpcodeNDataSet64_s format | size : 4 byte | scope : 33575 ~ 33579 |
    QByteArray block1HeaderOpcodeNDataSet64_s;

    for(int i=33575;i<33579;i++)
    {
       block1HeaderOpcodeNDataSet64_s.append(_patFile.at(i));
    }

    return block1HeaderOpcodeNDataSet64_s;

}

QByteArray File::readBlock1HeaderMicroPatternCount()
{
    // 20. readBlock1HeaderMicroPatternCount  format | size : 4 byte | scope : 33579 ~ 33583 |
    QByteArray block1HeaderMicroPatternCount;

    for(int i=33579;i<33583;i++)
    {
       block1HeaderMicroPatternCount.append(_patFile.at(i));
    }

    return block1HeaderMicroPatternCount;

}

QByteArray File::readBlock1HeaderReaserverd()
{
    // 21. readBlock1HeaderReaserverd        format | size : 16 byte| scope : 33583 ~ 33598 |
    QByteArray block1HeaderReaserverd;

    for(int i=33583;i<33598;i++)
    {
       block1HeaderReaserverd.append(_patFile.at(i));
    }

    return block1HeaderReaserverd;
}

