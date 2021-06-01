package com.bailun.kai.jetaudioplayer;

import android.util.Log;

public class AudioPlayer {

    private String mAudioUrl;
    private static AudioPlayer INSTANCE;

    private AudioPlayer(){}

    public static AudioPlayer getInstance(){
        if (INSTANCE == null){
            INSTANCE = new AudioPlayer();
        }
        return INSTANCE;
    }

    static {
        System.loadLibrary("native-lib");
    }

    public void init(String url){
        if (url == null){
            return;
        }
        mAudioUrl = url;
        // 初始化播放器
        n_init(url);
    }

    public native void n_init(String url);

    /**
     * Jni 反射执行该方法
     */
    public void onInitedCallback(){
        Log.e("来自 JNI 的回调"," Success");
    }

}
