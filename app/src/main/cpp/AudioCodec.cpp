//
// Created by Admin on 2021/6/1.
//

#include "AudioCodec.h"

AudioCodec::AudioCodec(PlayerCallback *playerCallback, const char *url) {
   // 初始化解码器，内部使用 FFmpeg
    this->url = url;
    this->playerCallback = playerCallback;

}
