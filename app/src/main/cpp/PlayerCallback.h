//
// Created by 84534 on 2021/5/26.
//

#ifndef JETAUDIOPLAYER_PLAYERCALLBACK_H
#define JETAUDIOPLAYER_PLAYERCALLBACK_H

#include "jni.h"
#include <linux/stddef.h>
#define MAIN_THREAD 0
#define CHILD_THREAD 1

class PlayerCallback{

    public:
    // JVM 引用,用于在子线程也能回调
    _JavaVM * javaVm = NULL;
    // JNI_env
    JNIEnv * jniEnv = NULL;
    // Java 对象的对应的指针地址
    jobject jobj;
    // Java 方法ID
    jmethodID jmid_inited;


public:
    //构造
    PlayerCallback(_JavaVM *javaVm, JNIEnv *jniEnv, jobject* jobj);

    //析构
    ~PlayerCallback();

    // 回调 Java,播放器初始化成功
    void onInitedCallback(int threadType);
};


#endif

//JETAUDIOPLAYER_PLAYERCALLBACK_H
