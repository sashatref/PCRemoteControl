#include "project_pch.h"
#include "settingsinfo.h"



void SettingsInfo::propertyInfoMap(PropertyInfoMapType &m) const
{
    m["port"].m_properties[IntProperty::SpinBoxMaximum] = 60000;
    m["wwwPath"].m_properties[StringProperty::EditorType] = StringProperty::OpenDir;

//    m["protocolCmdLine"].m_properties[StringProperty::EditorType] = StringProperty::ExtendedText;
//    m["lastProject"].m_isHidden     = true;
//    m["regInfoMap"].m_isHidden      = true;
//    m["layoutMap"].m_isHidden       = true;
}

void SettingsInfo::registerType()
{
    GadgetHelper::registerToIGadgetConverter<SettingsInfo>();
}


