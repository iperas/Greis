#ifndef File_h__
#define File_h__

#include <memory>
#include <QtCore/QFile>
#include <QtCore/QString>

namespace Common
{
    typedef std::shared_ptr<QFile> QFilePtr;

    class File
    {
    public:
        // �������� ����� �� ������ � �������� ������. ������ ���� ����� ���.
        static QFilePtr OpenReadBinary(QString filename);

        // �������� ����� ��� �������� ����������� ���������� ����� � ��� ��������. � �������� ������.
        static QFilePtr CreateBinary(QString filename);
    };
}

#endif // File_h__
