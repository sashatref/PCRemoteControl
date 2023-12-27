#include "httpserverholder.h"

HttpServerHolder::HttpServerHolder(QObject *_parent):
    QObject(_parent)
{
    m_factory = new MainHandlerFactory();
    m_httpServer = new HttpServer(m_factory, this);

    ServerOptions opt;
    opt.addToIndexRedirect();
    m_httpServer->setServerOptions(opt);
}

void HttpServerHolder::setPort(int _port)
{
    m_port = _port;

    ServerOptions opt = m_httpServer->getServerOptions();
    opt.port = m_port;
    m_httpServer->setServerOptions(opt);
}

void HttpServerHolder::setWWWPath(const QString &_wwwPath)
{
    m_factory->setWWWPath(_wwwPath);
}

void HttpServerHolder::stopHttpServer()
{
    m_httpServer->stop();
}

void HttpServerHolder::startHttpServer()
{
    m_httpServer->start();
}
