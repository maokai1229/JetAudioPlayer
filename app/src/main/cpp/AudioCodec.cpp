//
// Created by Admin on 2021/6/1.
//

#include "AudioCodec.h"


AudioCodec::AudioCodec(PlayerCallback *playerCallback, const char *url) {
   // 初始化解码器，内部使用 FFmpeg
    this->url = url;
    this->playerCallback = playerCallback;

}

/**
 * 解码数据
 */
void *decode(void *data) {
    // 初始化 FFmpeg

}

/**
 * FFmpeg 初始化
 */
void AudioCodec::initFFmpeg() {
    //加互斥锁
    pthread_mutex_lock(&init_mutex);
    av_register_all();
    avformat_network_init();


    //解锁
    pthread_mutex_unlock(&init_mutex);
}

void AudioCodec::prepare() {
    pthread_create(&thread_codec,NULL,decode,this);
}
