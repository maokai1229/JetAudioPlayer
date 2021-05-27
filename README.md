# JetAudioPlayer
### 前言
实现了一个极简版的音频播放器，音频解码使用 FFmpeg ，播放使用 OpenSl ES

之前对视频、音频的解码，都是用 MediaCodec 实现，这次我们使用 FFmpeg，其实就是使用软解的方式；播放音频的 API 除了 OpenSl 还可以用 AudioTrack，只不过 AudioTrack 是 Java 方法，Ndk 的方式播放时存在频繁的内存拷贝，而 OpenSl 可以避免这个过程，性能上更优秀,之前在网上看到一篇文章，其中介绍腾讯视频也是改用了 OpenSl 

在动手实现前，首先需要思考几个问题：
1. 解码后的数据放到哪里，是否需要一个队列或者缓冲区？
2. 解码和播放放到同一个线程还是单独开辟？
3. 音频播放前是否需要重采样？
4. 播放器底层使用 C、C++ 完成，怎么回调给 Java 层？
5. 解码速度比播放速度要快，当解码数据大量未被使用时，是否需要暂停解码？

### 设计结构
* AudioCodec 子线程解码
* AudioNativePlayer 子线程播放(OpenSl ES)
* PcmDataQueue   PCM 数据缓冲区
* PlayerCallback  回调给 Java 层
* PlayerStatus 播放器状态


### 使用 OpenSl ES 的流程
* 初始化接口
* 初始化混音器
* 配置采样率等信息
* 设置回调


### cmake 配置
首先我们导入 FFmpeg 对应的 so 库文件到 cpp 目录下，为了让 Cmake 在编译时能够找到库文件，我们需要在 build.gradle 文件中声明文件的路径

[如何告诉CMake（通过externalNativeBuild调用）在哪里查找库？](https://www.5axxw.com/questions/content/48qvwy)

```
 externalNativeBuild {
            cmake {
               ******
            }
        }
     // 具体参考代码中的配置   
        
```

### 实践代码
[简单音乐播放器 Github 地址](https://github.com/maokai1229/JetAudioPlayer)

### 其他
缓冲区大小: 采样位数 * 采样频率 * 通道数
例如: (采样位数 16 个字节) 2 * (采样频率) 44100 * (通道数) 2  

当喇叭播放完数据时,触发回调函数,此时我们往里面填充解码好的 PCM 数据
在音频播放时,不管使用是用 AudioTrack 还是 OpenSl 都需重采样


### 遇到的问题
* #include jni.h  时报红，找不到 jni.h 

解决方案：~~在网上看到一种方式，在 cmakelist 文件中 include ndk 头文件,而 stackoverflow 上的回答是 ndk r15 以后取消了对 gcc 的支持，需要调低 ndk 的版本，由于是几年前的回复了，所以暂时不考虑，先试着引入 ndk 路径~~

发现 native-lib.cpp 中正常，但在同一目录下的，就不行,首先检查 ndk 环境变量是否正确配置,然后去项目的 local.properties 文件中配置 ndk 路径,最后去 Project Struct 中指定 ndk 版本,rebuild 项目后,爆红的部分消失

```
//  local.properties
sdk.dir=C\:\\Soft\\sdk-eclipse
ndk.dir=C\:\\Soft\\sdk-eclipse\\ndk-bundle
```
![image.png](https://upload-images.jianshu.io/upload_images/5639648-cde205da45acad9c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/720)


### 相关链接
* [Android Studio build.gradle 中配置 cmake，及各 arguments 详解
](https://blog.csdn.net/afei__/article/details/81271594)
