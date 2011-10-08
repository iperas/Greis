#ifndef Path_h__
#define Path_h__

#include <QtCore/QtCore>

namespace Util
{
    class Path
    {
    public:
        static QString ApplicationDirPath()
        {
            return QCoreApplication::applicationDirPath();
        }

        static QString ApplicationFilePath()
        {
            return QCoreApplication::applicationFilePath();
        }

        static QString Combine(const QString& a, const QString& b)
        {
            QString an = QDir::fromNativeSeparators(a);
            QString bn = QDir::fromNativeSeparators(b);
            if (!an.endsWith('/') && !bn.startsWith('/'))
            {
                an.append('/');
            }
            QString ret = QDir::toNativeSeparators(an + bn);
            return ret;
        }
    };
}

#endif // Path_h__