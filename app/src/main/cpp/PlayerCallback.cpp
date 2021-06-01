//
// Created by 84534 on 2021/5/27.
//

#include "PlayerCallback.h"
#include "AndroidLog.h"

PalyerCallback::PalyerCallback(_JavaVM *jVm, JNIEnv *jEnv,jobject *obj){
    javaVm = jVm;
    jniEnv = jEnv;
//    jobj = obj;
    jobj = *obj;
    jobj = jEnv->NewGlobalRef(reinterpret_cast<jobject>(obj));

    jclass jclazz = jEnv->GetObjectClass(jobj);

    if (!jclazz){
        if (LOG_DEBUG){
            LOGE("jclazz error")
        }
        return;
    }
    // 使用 jni 层调用 Java 反射方法
    jmid_inited = jEnv->GetMethodID(jclazz,"onInitedCallback","()V");
}

void PalyerCallback::onInitedCallback(int threadType) {

    if (threadType == MAIN_THREAD){
        // 主线程回调
        jniEnv->CallVoidMethod(jobj,jmid_inited);
    } else{
        //子线程需要使用 JVM->AttachCurrentThread 连接
       if (javaVm->AttachCurrentThread(&jniEnv,0) != JNI_OK){
           if (LOG_DEBUG){
                LOGE("JVM->AttachCurrentThread error")
           }
       }
       //invoke
       jniEnv->CallVoidMethod(jobj,jmid_inited);
       javaVm->DetachCurrentThread();
    }
}











