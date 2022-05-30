//
// Created by Administrator on 2022/5/29.
//

#ifndef HUAXIAPLAYER_IOLAYER_H
#define HUAXIAPLAYER_IOLAYER_H

#include <jni.h>
#include "libavformat/avformat.h"
#include "PacketQueue.h"
#include "HuaXiaPlayer.h"
#include "DecodeParameter.h"
#include <pthread.h>

/**
 * 文件读取IO层，
 */
class IOLayer {
private:

    /**
     * IO read thread
     */
    pthread_t mReadThread;
public:
    AVFormatContext *mFormatContext;
    PacketQueue *mAudioQ;
    PacketQueue *mVideoQ;
    char *mPlayUrl;
    HuaXiaPlayer *mPlayer;

    /**
     * 获得流编码参数回调函数
     */
    void (*mOpenCallBack)(HuaXiaPlayer *, DecodeParameter *);

    void setPlayUrl(JNIEnv *pEnv, jstring pJstring);


    IOLayer(HuaXiaPlayer *pPlayer);

    ~IOLayer();

    void open(PacketQueue *audioPacketQ, PacketQueue *videoPacketQ,
              HuaXiaPlayer *player,
              void (*openCallback)(HuaXiaPlayer *, DecodeParameter *));
};


#endif //HUAXIAPLAYER_IOLAYER_H
