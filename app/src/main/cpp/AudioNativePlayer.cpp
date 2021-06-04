//
// Created by 84534 on 2021/6/4.
//

#include "AudioNativePlayer.h"

AudioNativePlayer::AudioNativePlayer(AVFormatContext *avFormatContext,
                                     AVCodecParameters *avCodecParameters,
                                     PlayerCallback *playerCallback) {
    this->avFormatContext = avFormatContext;
    this->avCodecParameters = avCodecParameters;
    this->playerCallback = playerCallback;

}



