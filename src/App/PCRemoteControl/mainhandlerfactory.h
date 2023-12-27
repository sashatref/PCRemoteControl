#pragma once

class MainHandlerFactory : public HttpRequestHandlerFactory
{
    Q_OBJECT
public: 
    void setWWWPath(const QString &_path)
    {
        m_wwwPath = _path;
    }

    virtual HttpRequestHandler *handleRequest(HttpRequest *_req, HttpResponse *_res) override;

private:
    QString m_wwwPath;
};

