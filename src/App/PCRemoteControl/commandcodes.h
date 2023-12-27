#pragma once

#include <QString>

namespace CommandCodes
{
    namespace System
    {
        static const QString setVolume = "system.setVolume";
        static const QString getVolume = "system.getVolume";

        static const QString getMute = "system.getMute";
        static const QString setMute = "system.setMute";

        static const QString pcShutdown = "system.pcShutdown";
        static const QString pcSleep = "system.pcSleep";
        static const QString pcHibernate = "system.pcHibernate";
    }

    namespace LightAllow
    {
        static const QString laPlay = "la.play";
        static const QString laFullscreen = "la.fullscreen";
        static const QString laNext = "la.next";
        static const QString laPrev = "la.prev";
        static const QString laLeft = "la.left";
        static const QString laRight = "la.right";
    }

    namespace Aimp
    {
        static const QString aimpGetMute = "aimp.getMute";
        static const QString aimpSetMute = "aimp.setMute";
        static const QString aimpSetVolume = "aimp.setVolume";
        static const QString aimpGetVolume = "aimp.getVolume";
        static const QString aimpLaunch = "aimp.launch";
        static const QString aimpSetShuffle = "aimp.setShuffle";
        static const QString aimpGetShuffle = "aimp.getShuffle";
        static const QString aimpGetState = "aimp.getState";
        static const QString aimpQuit = "aimp.quit";
        static const QString aimpNextTrack = "aimp.nextTrack";
        static const QString aimpPrevTrack = "aimp.prevTrack";
        static const QString aimpPause = "aimp.pause";
        static const QString aimpStop = "aimp.stop";
        static const QString aimpPlay = "aimp.play";
        static const QString aimpSetPosition = "aimp.setPosistion";
        static const QString aimpGetPosition = "aimp.getPosition";
        static const QString aimpGetDuration = "aimp.getDuration";
    }


}
