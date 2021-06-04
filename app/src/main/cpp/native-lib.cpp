#include <jni.h>
#include <string>
#include "PlayerCallback.h"
#include "AndroidLog.h"
#include "AudioCodec.h"


extern "C"{
#include <libavformat/avformat.h>
}

_JavaVM *javaVM = NULL;
PlayerCallback *palyerCallback = NULL;


extern "C"
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    javaVM = vm;
    JNIEnv *env = NULL;
    jint result;

    if (vm->GetEnv((void **)&env, JNI_VERSION_1_6) == JNI_OK) {
        LOGE("Catch JNI_VERSION_1_6");
        result = JNI_VERSION_1_6;
    }
    else if (vm->GetEnv((void **)&env, JNI_VERSION_1_4) == JNI_OK) {
        LOGE("Catch JNI_VERSION_1_4");
        result = JNI_VERSION_1_4;
    }
    else {
        LOGE("Default JNI_VERSION_1_2");
        result = JNI_VERSION_1_2;
    }
    return result;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_bailun_kai_jetaudioplayer_AudioPlayer_n_1init(JNIEnv *env, jobject thiz, jstring url) {
    // TODO: implement n_init()
//    const char * stream_url= env->GetStringUTFChars(url,0);
    // 初始化回调
    if (palyerCallback == NULL){
        palyerCallback = new PlayerCallback(javaVM, env, &thiz);
    }
    // 初始化 FFmpeg 、解码器


    // 初始化完成，回调 Java 层
}