#include "mainhandlerfactory.h"
#include "apihandler.h"

HttpRequestHandler *MainHandlerFactory::handleRequest(HttpRequest *_req, HttpResponse *_res)
{
    if(_req->getUrl().path().startsWith("/api"))
    {
        return new ApiHandler();
    }

    return new FileSystemRequestHandler(m_wwwPath);
}
