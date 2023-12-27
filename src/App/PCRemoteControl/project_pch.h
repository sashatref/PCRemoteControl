#pragma once

#include <QDebug>
#include <QtPlugin>
#include <QStyleFactory>
#include <QTcpServer>
#include <QJsonDocument>
#include <QJsonObject>
#include <functional>

#include <PropertyBrowser3/settingsform.h>
#include <PropertyBrowser3/Editors/editorproperties.h>
#include <PropertyBrowser3/propertybrowser3.h>

#include <HelperLibrary/IGadget/igadget.h>
#include <HelperLibrary/ExtendApp/extendapp.h>
#include <HelperLibrary/singleton.hpp>
#include <HelperLibrary/Widgets/infowindow.h>
#include <HelperLibrary/Widgets/extendedmainwindow.h>
#include <HelperLibrary/functions.h>
#include <HelperLibrary/Widgets/TrayMenu/traymenu.h>

#include <HttpServer2/httpserver.h>
#include <HttpServer2/Handlers/filesystemrequesthandler.h>
#include <HttpServer2/Handlers/commoncommandhandler.h>
#include <HttpServer2/httprequesthandlerfactory.h>
#include <HttpServer2/httprequesthandler.h>
#include <HttpServer2/httprequest.h>
#include <HttpServer2/httpresponse.h>

using namespace HttpServer2Qt;
