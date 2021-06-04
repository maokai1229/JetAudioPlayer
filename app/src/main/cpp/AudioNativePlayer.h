//
// Created by Admin on 2021/6/4.
//

#ifndef JETAUDIOPLAYER_AUDIONATIVEPLAYER_H
#define JETAUDIOPLAYER_AUDIONATIVEPLAYER_H

#include "include/libavformat/avformat.h"

extern "C"
{
#include "libavcodec/avcodec.h"
#include <libswresample/swresample.h>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
};


class AudioNativePlayer{

    public:
        int audioStreamIndex = -1;
        AVFormatContext  *avFormatContext = NULL;
        AVCodecParameters *avCodecParameters = NULL;
        PlayerCallback *playerCallback = NULL;

    public:
        AudioNativePlayer(AVFormatContext  *avFormatContext,AVCodecParameters *avCodecParameters,PlayerCallback *playerCallback);
        ~AudioNativePlayer();
        void startPlay();
        void pause();
        void release();
};


#endif //JETAUDIOPLAYER_AUDIONATIVEPLAYER_H
