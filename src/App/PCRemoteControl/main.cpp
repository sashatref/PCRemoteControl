#include <QApplication>

#include "settingsinfo.h"
#include "project_pch.h"
#include "buildNumber.h"
#include "mainwindow.h"

namespace {
void registerTypes()
{
    SettingsInfo::registerType();
    PropertyBrowser3::registerBaseTypes();
}
}

Q_IMPORT_PLUGIN(CustomStylePlugin)


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    Q_INIT_RESOURCE(CustomStylePlugin);

#ifdef STATIC
    Q_INIT_RESOURCE(Propertybrowser3_images);
    Q_INIT_RESOURCE(loggertemplate);
#endif

    registerTypes();

    ExtendApp a(argc, argv);
    a.setApplicationVersion(FULL_VER);
    a.setStyle(QStyleFactory::create("customStyle"));
    a.parseCommandLine();

    SettingsInfo *s = sgSettings::instance();
    a.loadSettings(s);

    QObject::connect(&a, &ExtendApp::aboutToQuit, [&] { a.saveSettings(s); });
    QObject::connect(&a, &ExtendApp::onExceptionMsg, [](const QString &_msg) {
        InfoWindow(_msg).exec();
    });

    MainWindow w;
    w.setObjectName("MainWindow");
    a.loadLayout();
    w.loadWidgetState(a.getLayoutSaver()->value(w.objectName()));
    w.show();

    w.setOnSaveCallback([&](const QVariant &_val)
    {
        a.getLayoutSaver()->insert(w.objectName(), _val);
    });

    if(s->m_autoStart)
    {
        w.on_actionStartServer_triggered();
    }

    return a.exec();
}
