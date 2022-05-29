//
// Created by Administrator on 2022/5/29.
//

#include "include/IOLayer.h"
#include "libavformat/avformat.h"

static void *readThread(void *layer) {
    auto *ioLayer = static_cast<IOLayer *>(layer);
    avformat_open_input(&ioLayer->mFormatContext, ioLayer->mPlayUrl, nullptr, nullptr);
    //对于FLV这种流式的封装格式需要使用这个函数才能得到各个AVStream信息
    avformat_find_stream_info(ioLayer->mFormatContext, nullptr);
    if (ioLayer->mOpenCallBack) {
        ioLayer->mOpenCallBack(ioLayer->mPlayer, nullptr);
    }
    return nullptr;
}


IOLayer::IOLayer(HuaXiaPlayer *pPlayer) {
    this->mPlayer = pPlayer;
}

void IOLayer::setPlayUrl(JNIEnv *jniEnv, jstring playUrl) {
    const char *url = jniEnv->GetStringUTFChars(playUrl, nullptr);
    mPlayUrl = new char[strlen(url)];
    strcpy(mPlayUrl, url);
    jniEnv->ReleaseStringUTFChars(playUrl, url);
}


void IOLayer::open(PacketQueue *pQueue, PacketQueue *pPacketQueue,
                   HuaXiaPlayer *player,
                   void (*openCallBack)(HuaXiaPlayer *, DecodeParameter *)) {
    mAudioQ = pQueue;
    mVideoQ = pPacketQueue;
    mFormatContext = avformat_alloc_context();
    mPlayer = player;
    mOpenCallBack = openCallBack;
    pthread_create(&mReadThread, nullptr, readThread, this);
}
