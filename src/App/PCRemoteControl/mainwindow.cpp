#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <PropertyBrowser3/propertybrowser3.h>

#include "httpserverholder.h"

MainWindow::MainWindow(QWidget *parent) :
    ExtendedMainWindow(parent),
    ui(new Ui::MainWindow),
    m_http(new HttpServerHolder(this))
{
    ui->setupUi(this);

    initAll();

    m_trayMenu = new TrayMenu(this, QIcon(":/images/31314.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsForm form(this);
    form.setValue(QVariant::fromValue(sgSettings::ins()));
    if(form.exec() == QDialog::Accepted)
    {
        sgSettings::ins() = form.getValue().value<SettingsInfo>();
        qApp->emitSettingChangeEvent();
    }
}


void MainWindow::initConnections()
{
    // connect(m_httpServer, &HttpServer::message, this, &MainWindow::onMessage);
    // connect(m_fileHandler, &FilesystemHandler::message, this, &MainWindow::onMessage);
    // connect(m_apiHandler, &ApiHandler::message, this, &MainWindow::onMessage);
}

void MainWindow::on_actionStartServer_triggered()
{
    try
    {
        m_http->startHttpServer();
        onMessage("HTTP | Сервер Запущен", QtInfoMsg);
        ui->actionStartServer->setEnabled(false);
        ui->actionStopServer->setEnabled(true);
    }
    catch(std::exception &e)
    {
        onMessage(e.what(), QtCriticalMsg);
        on_actionStopServer_triggered();
    }
}

void MainWindow::on_actionStopServer_triggered()
{
    m_http->stopHttpServer();

    ui->actionStartServer->setEnabled(true);
    ui->actionStopServer->setEnabled(false);

    onMessage("HTTP | Сервер остановлен", QtInfoMsg);
}

void MainWindow::onMessage(const QString &_text, QtMsgType _type)
{
    ui->logWindow->addMessage(Text::textWithDateTimeStamp(_text), _type);
}

void MainWindow::updateStyle()
{

}

void MainWindow::loadState(const LayoutSaver &_saver)
{
    _saver.loadMainWindow(this, "mw");
}

void MainWindow::saveState(LayoutSaver &_saver) const
{
    _saver.saveMainWindow(this, "mw");
}

void MainWindow::initUiComponets()
{

}

void MainWindow::settingsChanged()
{
    m_http->setPort(sgSettings::ins().m_port);
    m_http->setWWWPath(sgSettings::ins().m_wwwPath);

    // m_httpServer->set_port(m_settings.m_port);
    // m_httpServer->set_isSSlEnable(false);
    // m_fileHandler->set_showDir(false);
    // m_fileHandler->set_cacheLogging(false);
    // m_fileHandler->set_isCacheEnable(false);
    // m_fileHandler->set_documentRoot(m_settings.m_wwwPath);
}
