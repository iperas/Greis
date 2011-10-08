#include "IniSettings.h"
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QMap>
#include <QTextCodec>

namespace Util
{
    IniSettings::IniSettings()
    {
        _pSettings = 0;
    }

    IniSettings::~IniSettings()
    {
        if (_pSettings)
            delete _pSettings;
    }

    bool IniSettings::Initialize(const QString& settingsFile)
    {
        _settingsFile = settingsFile;
        _pSettings = new QSettings(_settingsFile, QSettings::IniFormat);
        _initialized = true;
        return true;
    }

    void IniSettings::setValue( const QString& key, const QVariant& value )
    {
        _pSettings->setValue(key, value);
    }

    QVariant IniSettings::value( const QString & key, const QVariant & defaultValue /*= QVariant()*/ ) const
    {
        return _pSettings->value(key, defaultValue);
    }
}
