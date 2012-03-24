#ifndef File_h__
#define File_h__

#include <memory>
#include <QtCore/QFile>
#include <QtCore/QString>

namespace ProjectBase
{
    typedef std::shared_ptr<QFile> QFilePtr;

    class File
    {
    public:
        // Открытие файла на чтение в бинарном виде. Ошибка если файла нет.
        static QFilePtr OpenReadBinary(QString filename);
    };
}

#endif // File_h__
