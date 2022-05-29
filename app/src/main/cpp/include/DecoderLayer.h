//
// Created by Administrator on 2022/5/29.
//

#ifndef HUAXIAPLAYER_DECODERLAYER_H
#define HUAXIAPLAYER_DECODERLAYER_H

#include "PacketQueue.h"
#include "FrameQueue.h"
#include "DecodeParameter.h"

/**
 * 解码层
 */
class DecoderLayer {
private:
    PacketQueue *mAudioPacketQ;
    FrameQueue *mAudioFrameQ;

    PacketQueue *mVideoPacketQ;
    FrameQueue *mVideoFrameQ;

public:
    int open(PacketQueue *audioPacketQ, FrameQueue *audioFrameQ, PacketQueue *videoPacketQ,
             FrameQueue *videoFrameQ, DecodeParameter *decoderParameter);

};


#endif //HUAXIAPLAYER_DECODERLAYER_H
