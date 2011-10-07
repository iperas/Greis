#ifndef __SettingsController_h__
#define __SettingsController_h__

#include <QSettings>
#include <QString>
#include "Util/Singleton.h"

using namespace Util;

namespace Common
{
    class Settings
    {
        SINGLETON_BLOCK(Settings)
    public:
        Settings();
        ~Settings();

        bool Initialize(const QString& settingsFile);
        void setValue(const QString& key, const QVariant& value);
        QVariant value(const QString & key, const QVariant & defaultValue = QVariant()) const;

        inline QSettings* settings() { return _pSettings; }
    private:
        QSettings* _pSettings;
        QString _settingsFile;
        bool _initialized;
    };
}

#define sSettings SINGLETON_INSTANCE(::Common::Settings)

#endif
