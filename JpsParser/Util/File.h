#ifndef File_h__
#define File_h__

#include "FileException.h"
#include <boost/shared_ptr.hpp>


namespace Util
{
    typedef boost::shared_ptr<QFile> QFilePtr;

    class File
    {
    public:
        // Открытие файла на чтение в бинарном виде. Ошибка если файла нет.
        static QFilePtr OpenReadBinary(QString filename)
        {
            QFilePtr file(new QFile(filename));
            if (!file->open(QIODevice::ReadOnly))
            {
                throw FileException(QString("Ошибка при открытии файла '%1': %2.").arg(filename).arg(file->errorString()));
            }
            return file;
        }
    };
}

#endif // File_h__
