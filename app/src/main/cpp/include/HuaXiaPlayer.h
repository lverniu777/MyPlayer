//
// Created by Administrator on 2022/5/28.
//

#ifndef HUAXIAPLAYER_HUAXIAPLAYER_H
#define HUAXIAPLAYER_HUAXIAPLAYER_H

#include "IOLayer.h"
#include "DecoderLayer.h"
#include "RenderLayer.h"

/**
 * 华夏播放器
 */
class HuaXiaPlayer {
private:
    /**
     * IO层
     */
    IOLayer *mIOLayer;


public:

    /**
     * 解码层
     */
    DecoderLayer *mDecoderLayer;


    /**
     * 渲染层
     */
    RenderLayer *mRenderLayer;

    PacketQueue *mAudioPacketQ;
    FrameQueue *mAudioFrameQ;

    PacketQueue *mVideoPacketQ;
    FrameQueue *mVideoFrameQ;

    HuaXiaPlayer();

    ~HuaXiaPlayer();

    void setPlayUrl(JNIEnv *jniEnv, jstring playUrl);

    void prepareAsync();

};


#endif //HUAXIAPLAYER_HUAXIAPLAYER_H
