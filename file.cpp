#include "file.h"

QString File::getFilePath()
{

    QString PWDPath = QCoreApplication::applicationDirPath();

    QString filePath = QFileDialog::getOpenFileName(this,
          tr("Open Image"), PWDPath, tr("Image Files (*.pat)"));

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

QByteArray File::readFileHeaderDiscemmentCode(int startAddress,int endAddress)
{
    // 1. fileHeaderDiscemmentCode format | size : 4 byte  | scope : 0~4

    QByteArray fileHeaderDiscemmentCode;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderDiscemmentCode.append(_patFile.at(i));
    }

    return fileHeaderDiscemmentCode;
}

QByteArray File::readFileHeaderSourceFileName(int startAddress,int endAddress)
{
    // 2. fileHeaderSourceFileName format | size : 36 byte | scope : 4~40

    QByteArray fileHeaderSourceFileName;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderSourceFileName.append(_patFile.at(i));
    }

    return fileHeaderSourceFileName;

}

QByteArray File::readFileHeaderCompileDate(int startAddress,int endAddress)
{
    // 3. readFileHeaderCompileDate | size : 8 byte  | scope : 40~48

    QByteArray fileHeaderCompileDate;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderCompileDate.append(_patFile.at(i));
    }

    return fileHeaderCompileDate;
}

QByteArray File::readFileHeaderCompileTime(int startAddress,int endAddress)
{
    // 4. readFileHeaderCompileTime format | size : 8 byte  | scope : 48~56
    QByteArray fileHeaderCompileTime;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderCompileTime.append(_patFile.at(i));
    }

    return fileHeaderCompileTime;

}

QByteArray File::readFileHeaderCompilerVersion(int startAddress,int endAddress)
{
    // 5. readFileHeaderCompilerVersion format |  size : 8 byte  | scope : 56~64

    QByteArray fileHeaderCompilerVersion;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderCompilerVersion.append(_patFile.at(i));
    }

    return fileHeaderCompilerVersion;

}

QByteArray File::readFileHeaderFlagCommonModuleExist(int startAddress,int endAddress)
{
    // 6. readFileHeaderFlagCommonModuleExist format | size : 4 byte  | scope : 64~68
    QByteArray fileHeaderFlagCommonModuleExist;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderFlagCommonModuleExist.append(_patFile.at(i));
    }

    return fileHeaderFlagCommonModuleExist;
}

QByteArray File::readFileHeaderCountOfBlock(int startAddress,int endAddress)
{
   // 7. readFileHeaderCountOfBlock() format | size : 4 byte  | scope : 68~72  |
    QByteArray fileHeaderCountOfBlock;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderCountOfBlock.append(_patFile.at(i));
    }

    return fileHeaderCountOfBlock;

}
QByteArray File::readFileHeaderOffsetsOfCommon(int startAddress,int endAddress)
{
    // 8. readFileHeaderOffsetsOfCommon format | size : 4 byte  | scope : 72~76  |
    QByteArray fileHeaderOffsetsOfCommon;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderOffsetsOfCommon.append(_patFile.at(i));
    }

    return fileHeaderOffsetsOfCommon;
}

QByteArray File::readFileHeaderOffsetsOfBlocks(int startAddress,int endAddress)
{
    // 9. readFileHeaderOffsetsOfBlocks format | size : 16384 byte| scope : 76~16460 |
    QByteArray fileHeaderOffsetsOfBlocks;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderOffsetsOfBlocks.append(_patFile.at(i));
    }

    return fileHeaderOffsetsOfBlocks;

}

QByteArray File::readFileHeaderStartAddressArray(int startAddress,int endAddress)
{
    // 10. readFileHeaderStartAddressArray | size : 16384 byte| scope : 16460~32844|
    QByteArray fileHeaderStartAddressArray;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderStartAddressArray.append(_patFile.at(i));
    }

    return fileHeaderStartAddressArray;
}

QByteArray File::readFileHeaderRemark(int startAddress,int endAddress)
{
    // 11. readFileHeaderRemark | size : 80 byte | scope : 32844~32924| HEX
    QByteArray fileHeaderRemark;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderRemark.append(_patFile.at(i));
    }

    return fileHeaderRemark;

}

QByteArray File::readFileHeaderDataOfIlMode(int startAddress,int endAddress)
{
    // 12. readFileHeaderDataOfIlMode | size : 4 byte  | scope : 32924~32928|

    QByteArray fileHeaderDataOfIlMode;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderDataOfIlMode.append(_patFile.at(i));
    }

    return fileHeaderDataOfIlMode;

}

QByteArray File::readFileHeaderReserved(int startAddress,int endAddress)
{
    // 13. readFileHeaderReserved | size : 16 byte | scope : 32928~32944|
    QByteArray fileHeaderReserved;

    for(int i=startAddress;i<endAddress;i++)
    {
       fileHeaderReserved.append(_patFile.at(i));
    }

    return fileHeaderReserved;

}


QByteArray File::readCommonHeaderOpcodeNDataSet32_r(int startAddress,int endAddress)
{
    // 14. readCommonHeaderOpcodeNDataSet32 format | size : 4 byte  | scope : 32944~32948
    QByteArray commonHeaderOpcodeNDataSet32;

    for(int i=startAddress;i<endAddress;i++)
    {
       commonHeaderOpcodeNDataSet32.append(_patFile.at(i));
    }

    return commonHeaderOpcodeNDataSet32;
}

QByteArray File::readCommonHeaderOpcodeNDataSet64_s(int startAddress,int endAddress)
{
    // 15. readCommonHeaderOpcodeNDataSet64 format | size : 4 byte | scope : 32948~32952
    QByteArray commonHeaderOpcodeNDataSet64;

    for(int i=startAddress;i<endAddress;i++)
    {
       commonHeaderOpcodeNDataSet64.append(_patFile.at(i));
    }

    return commonHeaderOpcodeNDataSet64;

}

QByteArray File::readCommonHeaderReserved(int startAddress,int endAddress)
{
    // 16. readCommonHeaderReserved format | size : 8 byte  | scope : 32952~32960  | success
    QByteArray commonHeaderReserved;


    for(int i=startAddress;i<endAddress;i++)
    {
       commonHeaderReserved.append(_patFile.at(i));
    }

    return commonHeaderReserved;

}

QByteArray File::readCommonBodyRegister32(int startAddress, int endAddress)
{
    // 17. readBlock1StartAddress
    QByteArray commonBodyRegister32;

    for(int i=startAddress;i<endAddress;i++)
    {
         commonBodyRegister32.append(_patFile.at(i));
    }

    return commonBodyRegister32;

}

QByteArray File::readCommonBodyRegister64(int startAddress, int endAddress)
{
    // 18. readBlock1StartAddress
    QByteArray commonBodyRegister64;

    for(int i=startAddress;i<endAddress;i++)
    {
         commonBodyRegister64.append(_patFile.at(i));
    }

    return commonBodyRegister64;
}

QByteArray File::readBlock1StartAddress(int startAddress, int endAddress)
{
    // 19. readBlock1StartAddress             format | size : 4 byte | scope : 33567 ~ 33571 |
    QByteArray block1StartAddress;

    for(int i=startAddress;i<endAddress;i++)
    {
         block1StartAddress.append(_patFile.at(i));        
    }

    return block1StartAddress;
}

QByteArray File::readBlock1HeaderOpcodeNDataSet32_r(int startAddress, int endAddress)
{
    // 20. readBlock1HeaderOpcodeNDataSet32_r format | size : 4 byte | scope : 33571 ~ 33575 |
    QByteArray block1HeaderOpcodeNDataSet32_r;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1HeaderOpcodeNDataSet32_r.append(_patFile.at(i));
    }

    return block1HeaderOpcodeNDataSet32_r;
}

QByteArray File::readBlock1HeaderOpcodeNDataSet64_s(int startAddress, int endAddress)
{
    // 21. readBlock1HeaderOpcodeNDataSet64_s format | size : 4 byte | scope : 33575 ~ 33579 |
    QByteArray block1HeaderOpcodeNDataSet64_s;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1HeaderOpcodeNDataSet64_s.append(_patFile.at(i));
    }

    return block1HeaderOpcodeNDataSet64_s;

}

QByteArray File::readBlock1HeaderMicroPatternCount(int startAddress, int endAddress)
{
    // 22. readBlock1HeaderMicroPatternCount  format | size : 4 byte | scope : 33579 ~ 33583 |
    QByteArray block1HeaderMicroPatternCount;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1HeaderMicroPatternCount.append(_patFile.at(i));
    }

    return block1HeaderMicroPatternCount;

}

QByteArray File::readBlock1HeaderReaserverd(int startAddress, int endAddress)
{
    // 23. readBlock1HeaderReaserverd        format | size : 16 byte| scope : 33583 ~ 33598 |
    QByteArray block1HeaderReaserverd;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1HeaderReaserverd.append(_patFile.at(i));
    }

    return block1HeaderReaserverd;
}

QByteArray File::readBlock1BodyRegister32(int startAddress, int endAddress)
{
    // 24. readBlock1BodyRegister32
    QByteArray block1BodyRegister32;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1BodyRegister32.append(_patFile.at(i));
    }

    return block1BodyRegister32;
}

QByteArray File::readBlock1BodyRegister64(int startAddress, int endAddress)
{
    // 25. readBlock1BodyRegister32
    QByteArray block1BodyRegister64;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1BodyRegister64.append(_patFile.at(i));
    }

    return block1BodyRegister64;

}

QByteArray File::readBlock1BodyMicroPattern(int startAddress, int endAddress)
{
    // 26. readBlock1BodyMicroPattern
    QByteArray block1BodyMicroPattern;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1BodyMicroPattern.append(_patFile.at(i));
    }

    return block1BodyMicroPattern;

}

QByteArray File::readBlock1BodyReserved(int startAddress, int endAddress)
{
    // 27. readBlock1BodyMicroPattern
    QByteArray block1BodyReserved;

    for(int i=startAddress;i<endAddress;i++)
    {
       block1BodyReserved.append(_patFile.at(i));
    }

    return block1BodyReserved;
}

