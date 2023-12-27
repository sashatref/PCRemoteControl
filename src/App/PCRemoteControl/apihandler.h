#pragma once

class ApiHandler : public RestApiHandler
{
    Q_OBJECT
public:
    ApiHandler(QObject *parent = 0);

signals:
    void message(const QString &_text, QtMsgType _msgType);

private:
    struct InData
    {
        QString code;
        QString value;
        QString resultStatus;
        QString resultCode;
        QVariant resultValue;
    };

    template<class T>
    void registerInternal(const QString &_command,
                               T *_obj,
                               void (T::*func)(InData&))
    {
        auto newFunc = std::bind(func, _obj, std::placeholders::_1);
        registerInternal(_command, newFunc);
    }

    void registerInternal(const QString &_command, std::function<void(InData &)> _handler);
    QByteArray commonHandler(const QString &_command, const ResponceInfo &req, std::function<void (InData &)> _handler);

    void getVolume(InData &d);
    void setVolume(InData &d);
    void pcHibernate(InData &d);
    void pcShutdown(InData &d);
    void pcSleep(InData &d);
    void setMute(InData &d);
    void getMute(InData &d);

    void laFullscreen(InData &d);
    void laLeft(InData &d);
    void laNext(InData &d);
    void laPlay(InData &d);
    void laPrev(InData &d);
    void laRight(InData &d);

    void aimpGetDuration(InData &d);
    void aimpGetMute(InData &d);
    void aimpGetPosition(InData &d);
    void aimpGetShuffle(InData &d);
    void aimpGetState(InData &d);
    void aimpGetVolume(InData &d);
    void aimpNextTrack(InData &d);
    void aimpPause(InData &d);
    void aimpPlay(InData &d);
    void aimpPrevTrack(InData &d);
    void aimpQuit(InData &d);
    void aimpSetMute(InData &d);
    void aimpSetPosition(InData &d);
    void aimpSetShuffle(InData &d);
    void aimpSetVolume(InData &d);
    void aimpStop(InData &d);
};
