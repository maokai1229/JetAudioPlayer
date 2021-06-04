//
// Created by 84534 on 2021/5/26.
//

#ifndef JETAUDIOPLAYER_AUDIOCODEC_H
#define JETAUDIOPLAYER_AUDIOCODEC_H
#include "jni.h"
#include <linux/stddef.h>
#include "PlayerCallback.h"
#include <pthread.h>

extern "C"
{
#include <libavutil/time.h>
#include "libavformat/avformat.h"
};


class AudioCodec{

    public:
         // 全局 JNI 回调
         PlayerCallback *playerCallback = NULL;
         pthread_t *codec_thread = NULL;
         AVFormatContext  *avFormatContext = NULL;
         const char* url = NULL;
         pthread_t  thread_codec;
         pthread_mutex_t init_mutex;

    public:
    AudioCodec(PlayerCallback *playerCallback, const char *url);
    void initFFmpeg();
    void prepare();
    ~AudioCodec();
};

#endif //JETAUDIOPLAYER_AUDIOCODEC_H
