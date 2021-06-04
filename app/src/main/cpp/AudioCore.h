//
// Created by 84534 on 2021/5/26.
//

#ifndef JETAUDIOPLAYER_AUDIOCORE_H
#define JETAUDIOPLAYER_AUDIOCORE_H
#include "jni.h"
#include <linux/stddef.h>
#include "PlayerCallback.h"
#include "AudioNativePlayer.h"
#include <pthread.h>

extern "C"
{
#include <libavutil/time.h>
#include "libavformat/avformat.h"
};

const int AVFORMAT_SUCCESS = 0;

class AudioCore{

    public:
         // 全局 JNI 回调
         PlayerCallback *playerCallback = NULL;
         pthread_t *codec_thread = NULL;
         AVFormatContext  *avFormatContext = NULL;
         const char* url = NULL;
         AudioNativePlayer * audioNativePlayer = NULL;
         pthread_t  thread_codec;
         pthread_mutex_t init_mutex;

    public:
    AudioCore(PlayerCallback *playerCallback, const char *url);
    void initFFmpeg();
    void prepare();
    ~AudioCore();
};

#endif //JETAUDIOPLAYER_AUDIOCORE_H
