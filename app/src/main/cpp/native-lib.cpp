#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_bailun_kai_jetaudioplayer_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT void JNICALL
Java_com_bailun_kai_jetaudioplayer_AudioPlayer_n_1init(JNIEnv *env, jobject thiz, jstring url) {
    // TODO: implement n_init()
    const char * stream_url= env->GetStringUTFChars(url,0);
    // 初始化 FFmpeg 、解码器


    // 初始化完成，回调 Java 层
}