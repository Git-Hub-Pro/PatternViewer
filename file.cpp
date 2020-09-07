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

QByteArray File::readPatFile(int startAddress, int endAddress)
{
    QByteArray patFile;

    for(int i=startAddress;i<endAddress;i++)
    {
       patFile.append(_patFile.at(i));
    }

    return patFile;

}

void File::setPatFile(QByteArray data)
{
    _patFile = data;
}
