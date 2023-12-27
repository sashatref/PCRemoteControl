#include "apihandler.h"

#include "commandcodes.h"
#include "winapifunctions.h"


ApiHandler::ApiHandler(QObject *parent) :
    RestApiHandler         (parent)
{
    registerInternal(CommandCodes::System::getVolume, this, &ApiHandler::getVolume);
    registerInternal(CommandCodes::System::setVolume, this, &ApiHandler::setVolume);
    registerInternal(CommandCodes::System::pcHibernate, this, &ApiHandler::pcHibernate);
    registerInternal(CommandCodes::System::pcShutdown, this, &ApiHandler::pcShutdown);
    registerInternal(CommandCodes::System::pcSleep, this, &ApiHandler::pcSleep);
    registerInternal(CommandCodes::System::setMute, this, &ApiHandler::setMute);
    registerInternal(CommandCodes::System::getMute, this, &ApiHandler::getMute);
    registerInternal(CommandCodes::LightAllow::laFullscreen, this, &ApiHandler::laFullscreen);

    registerInternal(CommandCodes::LightAllow::laLeft, this, &ApiHandler::laLeft);
    registerInternal(CommandCodes::LightAllow::laNext, this, &ApiHandler::laNext);
    registerInternal(CommandCodes::LightAllow::laPlay, this, &ApiHandler::laPlay);
    registerInternal(CommandCodes::LightAllow::laPrev, this, &ApiHandler::laPrev);
    registerInternal(CommandCodes::LightAllow::laRight, this, &ApiHandler::laRight);

    registerInternal(CommandCodes::Aimp::aimpGetDuration, this, &ApiHandler::aimpGetDuration);
    registerInternal(CommandCodes::Aimp::aimpGetMute, this, &ApiHandler::aimpGetMute);
    registerInternal(CommandCodes::Aimp::aimpGetPosition, this, &ApiHandler::aimpGetPosition);
    registerInternal(CommandCodes::Aimp::aimpGetShuffle, this, &ApiHandler::aimpGetShuffle);
    registerInternal(CommandCodes::Aimp::aimpGetState, this, &ApiHandler::aimpGetState);
    registerInternal(CommandCodes::Aimp::aimpGetVolume, this, &ApiHandler::aimpGetVolume);
    registerInternal(CommandCodes::Aimp::aimpNextTrack, this, &ApiHandler::aimpNextTrack);
    registerInternal(CommandCodes::Aimp::aimpPause, this, &ApiHandler::aimpPause);
    registerInternal(CommandCodes::Aimp::aimpPlay, this, &ApiHandler::aimpPlay);
    registerInternal(CommandCodes::Aimp::aimpPrevTrack, this, &ApiHandler::aimpPrevTrack);
    registerInternal(CommandCodes::Aimp::aimpQuit, this, &ApiHandler::aimpQuit);
    registerInternal(CommandCodes::Aimp::aimpSetMute, this, &ApiHandler::aimpSetMute);
    registerInternal(CommandCodes::Aimp::aimpSetPosition, this, &ApiHandler::aimpSetPosition);
    registerInternal(CommandCodes::Aimp::aimpSetShuffle, this, &ApiHandler::aimpSetShuffle);
    registerInternal(CommandCodes::Aimp::aimpSetVolume, this, &ApiHandler::aimpSetVolume);
    registerInternal(CommandCodes::Aimp::aimpStop, this, &ApiHandler::aimpStop);
}

void ApiHandler::registerInternal(const QString &_command, std::function<void (InData &)> _handler)
{
    registerCommonCommand(_command, [=](const ResponceInfo &req, RequestData*){return commonHandler(_command, req, _handler);});
}

QByteArray ApiHandler::commonHandler(const QString &_command, const ResponceInfo &req, std::function<void (InData &)> _handler)
{
    InData data;
    data.code = req.getParams().value("code").toString();
    data.value = req.getParams().value("value").toString();
    data.resultStatus = "ok";
    data.resultCode = data.code;
    data.resultValue = data.value;

    _handler(data);

    QVariantMap out {
        { "code", data.resultCode },
        { "status", data.resultStatus },
        { "value", data.resultValue}
    };
    return Text::writeToJson(out);
}

void ApiHandler::getVolume(InData &d)
{
    d.resultValue = System::getVolumeLevel();
}

void ApiHandler::setVolume(InData &d)
{
    int validValue = d.value.toInt();
    Numerics::fixValue(validValue, 0, 100);

    System::setVolumeLevel(validValue);

    d.resultValue = validValue;
}

void ApiHandler::pcHibernate(InData &d)
{
    System::pcHibernate();
}

void ApiHandler::pcShutdown(InData &d)
{
    System::pc_shutdown();
}

void ApiHandler::pcSleep(InData &d)
{
    System::pc_sleep();
}

void ApiHandler::setMute(InData &d)
{
    System::volume_mute(QVariant(d.value).toBool());
}

void ApiHandler::getMute(InData &d)
{
    d.resultValue = System::getMuteStatus();
}

void ApiHandler::laFullscreen(InData &d)
{
    LA::clickLAFullScreen();
}

void ApiHandler::laLeft(InData &d)
{
    LA::clickLALeft();
}

void ApiHandler::laNext(InData &d)
{
    LA::clickLANext();
}

void ApiHandler::laPlay(InData &d)
{
    LA::clickLAPlay();
}

void ApiHandler::laPrev(InData &d)
{
    LA::clickLAPrev();
}

void ApiHandler::laRight(InData &d)
{
    LA::clickLARight();
}

void ApiHandler::aimpGetDuration(InData &d)
{
    d.resultValue = Aimp::getDuration();
}

void ApiHandler::aimpGetMute(InData &d)
{
    d.resultValue = Aimp::getMuteStatus();
}

void ApiHandler::aimpGetPosition(InData &d)
{
    d.resultValue = Aimp::getPosition();
}

void ApiHandler::aimpGetShuffle(InData &d)
{
    d.resultValue = Aimp::getShuffle();
}

void ApiHandler::aimpGetState(InData &d)
{
    d.resultValue = Aimp::getState();
}

void ApiHandler::aimpGetVolume(InData &d)
{
    d.resultValue = Aimp::getVolumeLevel();
}

void ApiHandler::aimpNextTrack(InData &d)
{
    Aimp::nextTrack();
}

void ApiHandler::aimpPause(InData &d)
{
    Aimp::pause();
}

void ApiHandler::aimpPlay(InData &d)
{
    Aimp::play();
}

void ApiHandler::aimpPrevTrack(InData &d)
{
    Aimp::prevTrack();
}

void ApiHandler::aimpQuit(InData &d)
{
    Aimp::quit();
}

void ApiHandler::aimpSetMute(InData &d)
{
    Aimp::setMuteStatus(QVariant(d.value).toBool());
}

void ApiHandler::aimpSetPosition(InData &d)
{
    Aimp::setPosition(d.value.toInt());
}

void ApiHandler::aimpSetShuffle(InData &d)
{
    Aimp::setShuffle(QVariant(d.value).toBool());
}

void ApiHandler::aimpSetVolume(InData &d)
{
    int validValue = d.value.toInt();
    Numerics::fixValue(validValue, 0, 100);

    Aimp::setVolumeLevel(validValue);

    d.resultValue = validValue;
}

void ApiHandler::aimpStop(InData &d)
{
    Aimp::stop();
}

