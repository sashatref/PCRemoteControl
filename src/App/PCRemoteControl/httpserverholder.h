#pragma once

#include <QObject>

#include "mainhandlerfactory.h"

class HttpServerHolder : public QObject
{
    Q_OBJECT
public:
    HttpServerHolder(QObject *_parent = nullptr);

    void setPort(int _port);
    void setWWWPath(const QString &_wwwPath);

public slots:
    void startHttpServer();
    void stopHttpServer();

private:
    HttpServer *m_httpServer = nullptr;
    MainHandlerFactory *m_factory = nullptr;
    int m_port = 80;
};



