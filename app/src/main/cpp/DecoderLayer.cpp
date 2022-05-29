//
// Created by Administrator on 2022/5/29.
//

#include "include/DecoderLayer.h"

int
DecoderLayer::open(PacketQueue *audioPacketQ, FrameQueue *audioFrameQ, PacketQueue *videoPacketQ,
                   FrameQueue *videoFrameQ, DecodeParameter *decoderParameter) {
    mAudioPacketQ = audioPacketQ;
    mAudioFrameQ = audioFrameQ;

    mVideoPacketQ = videoPacketQ;
    mVideoFrameQ = videoFrameQ;
    return 0;
}