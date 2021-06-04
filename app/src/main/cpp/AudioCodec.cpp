//
// Created by Admin on 2021/6/1.
//

#include "AudioCodec.h"
#include "AndroidLog.h"

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
    // 加互斥锁
    pthread_mutex_lock(&init_mutex);
    av_register_all();
    avformat_network_init();
    avFormatContext = avformat_alloc_context();
    // 开启流
    if (avformat_open_input(&avFormatContext,url,NULL,NULL) != AVFORMAT_SUCCESS){
        // 读取失败
        if (LOG_DEBUG){
            LOGE("avformat_open_input : error")
        }
        return;
        // todo 触发 java 回调
    }
    // 获取流的信息
    if (avformat_find_stream_info(avFormatContext,NULL) < AVFORMAT_SUCCESS){
        if (LOG_DEBUG){
            LOGE("avformat_find_stream_info : error")
        }
        return;
    }
    // 读取轨道信息，找到音频轨道
    for (int index = 0; index < avFormatContext->nb_streams; index++) {
        // 读取音频轨资源数据
        if (avFormatContext->streams[index]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO){
            // 把数据保存到播放类中

        }
    }


    // 解锁
    pthread_mutex_unlock(&init_mutex);
}

void AudioCodec::prepare() {
    pthread_create(&thread_codec,NULL,decode,this);
}
