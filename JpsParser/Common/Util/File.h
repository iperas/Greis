#ifndef File_h__
#define File_h__

#include "../Exceptions/FileException.h"
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<QFile> FilePtr;

class File
{
public:
    // Открытие файла на чтение в бинарном виде. Ошибка если файла нет.
    static FilePtr OpenReadBinary(QString filename)
    {
        FilePtr file(new QFile(filename));
        if (!file->open(QIODevice::ReadOnly))
        {
            throw FileException(QString("Ошибка при открытии файла '%1': %2.").arg(filename).arg(file->errorString()));
        }
        return file;
    }
};

#endif // File_h__
