//
// Created by Administrator on 2022/5/29.
//

#include "include/RenderLayer.h"

RenderLayer::RenderLayer() {

}

int RenderLayer::open(FrameQueue *audioFrameQ, FrameQueue *videoFrameQ) {
    mAudioFrameQ = audioFrameQ;
    mVideoFrameQ = videoFrameQ;
}