//
// Created by Administrator on 2022/5/29.
//

#ifndef HUAXIAPLAYER_RENDERLAYER_H
#define HUAXIAPLAYER_RENDERLAYER_H

#include "FrameQueue.h"

/**
 * 渲染层
 */
class RenderLayer {
private:
    FrameQueue* mAudioFrameQ;
    FrameQueue* mVideoFrameQ;

public:
    RenderLayer();
    int open(FrameQueue *audioFrameQ, FrameQueue *videoFrameQ);
};


#endif //HUAXIAPLAYER_RENDERLAYER_H
