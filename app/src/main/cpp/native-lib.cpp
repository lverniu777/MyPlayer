#include <jni.h>
#include "HuaXiaPlayer.h"
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_huaxia_huaxiaplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_huaxia_huaxiaplayer_HuaXiaPlayer_nativeInit(JNIEnv *env, jobject thiz) {
    auto *huaXiaPlayer = new HuaXiaPlayer();
    return reinterpret_cast<jint>(huaXiaPlayer);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_huaxia_huaxiaplayer_HuaXiaPlayer_nativePrepare(JNIEnv *env, jobject thiz,
                                                        jint native_ptr) {
    if (native_ptr == 0) {
        return;
    }
    auto *huaXiaPlayer = reinterpret_cast<HuaXiaPlayer *>(native_ptr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_huaxia_huaxiaplayer_HuaXiaPlayer_nativeSetPlayUrl(JNIEnv *env, jobject thiz,
                                                           jint native_ptr, jstring play_url) {
    if (native_ptr == 0) {
        return;
    }
    auto *huaXiaPlayer = reinterpret_cast<HuaXiaPlayer *>(native_ptr);
    huaXiaPlayer->setPlayUrl(env, play_url);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_huaxia_huaxiaplayer_HuaXiaPlayer_nativePrepareAsync(JNIEnv *env, jobject thiz,
                                                             jint native_ptr) {
    if (native_ptr == 0) {
        return;
    }
    auto* huaXiaPlayer = reinterpret_cast<HuaXiaPlayer *>(native_ptr);
    huaXiaPlayer->prepareAsync();
}