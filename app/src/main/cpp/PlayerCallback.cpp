//
// Created by 84534 on 2021/5/27.
//

#include "PlayerCallback.h"


PalyerCallback::PalyerCallback(_JavaVM *jVm, JNIEnv *jEnv,jobject *obj){
    javaVm = jVm;
    jniEnv = jEnv;
//    jobj = obj;
    jobj = *obj;

}



