#/********************************************************************
#	created:
#	filename: 	HttpServer.pro
#	file ext:	qmake project
#	author:		Aleksandr Neborak

#	Copyright (C) Avia Ltd. Ukraine. Kremenchug 2016
#	All Rights Reserved

#	Project:	Qt Http(s) server

#       Библиотека для запуска HTTP(S) сервера

#*********************************************************************/
QT              += network widgets gui xml
HLP_LIB         += CACHE DEFAULT

TEMPLATE = app

PRECOMPILED_HEADER = project_pch.h

DEFINES += STATIC
TARGET = RemoteControlHttp

include(D:/git_projects/include/common.pri)
include(D:/git_projects/HelperLibrary/HelperLibrary2.pri)
include(D:/git_projects/HttpServer/HttpServer.pri)
include(D:/git_projects/PropertyBrowser3/PropertyBrowser3.pri)
include(D:/git_projects/Serialization/Serialization.pri)
include(D:/git_projects/CustomWidgets/CustomWidgets.pri)

LIBS += -lOle32 -lUser32
RC_FILE =

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsinfo.cpp \
    apihandler.cpp \
    commandcodes.cpp \
    winapifunctions.cpp \
    basecommandhandler.cpp

HEADERS += \
    mainwindow.h \
    settingsinfo.h \
    project_pch.h \
    apihandler.h \
    commandcodes.h \
    winapifunctions.h \
    icommandhandler.h \
    basecommandhandler.h


FORMS += \
    mainwindow.ui

RESOURCES += \
    images.qrc


#installs section


isEmpty(INSTALL_DIR) {
    INSTALL_DIR = $$PWD/..
}

binFiles.files += ../bin/*
binFiles.path = $${INSTALL_DIR}/bin

translations.files += translate/*.qm
translations.path = $${INSTALL_DIR}/translations

www.files += www/RemoteControl/RemoteControl/*.css
www.files += www/RemoteControl/RemoteControl/*.html
www.files += www/RemoteControl/RemoteControl/*.js

www.path = $${INSTALL_DIR}/bin/$${QT_VERSION}/www


INSTALLS += binFiles            \
            translations        \
            www

DISTFILES += \
    www/index.html
