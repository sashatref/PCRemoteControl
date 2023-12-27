#pragma once

#include <QObject>

#include <helperLibrary/setgetMacro.h>
#include <helperLibrary/converterfunctions.h>

#include <PropertyBrowser3/ipropertyinfomap.h>

using namespace PropertyBrowser3Qt;

class SettingsInfo : public IGadget, public IPropertyBrowserBase
{
    Q_GADGET
    DEFINE_MO
    Q_PROPERTY(int port MEMBER m_port)
    Q_PROPERTY(bool autoStart MEMBER m_autoStart)
    Q_PROPERTY(QString wwwPath MEMBER m_wwwPath)
public:
    virtual void propertyInfoMap(PropertyInfoMapType &m) const override;

    static void registerType();

    int m_port = 80;
    bool m_autoStart = false;
    QString m_wwwPath;
};

Q_DECLARE_METATYPE(SettingsInfo)

using sgSettings = Singleton<SettingsInfo>;
