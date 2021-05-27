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
    //



}