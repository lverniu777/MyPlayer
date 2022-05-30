//
// Created by Administrator on 2022/5/28.
//

#include "include/HuaXiaPlayer.h"
#include <cstring>

/**
 * IO层打开成功回调
 */
static void ioLayerOpened(HuaXiaPlayer *player, DecodeParameter *decodeParameter) {
    player->mDecoderLayer->open(
            player->mAudioPacketQ,
            player->mAudioFrameQ, player->mVideoPacketQ,
            player->mVideoFrameQ, decodeParameter);
    player->mRenderLayer->open(
            player->mAudioFrameQ,
            player->mVideoFrameQ
    );
}

HuaXiaPlayer::HuaXiaPlayer() {
    mIOLayer = new IOLayer();
    mDecoderLayer = new DecoderLayer();
    mRenderLayer = new RenderLayer();
}

HuaXiaPlayer::~HuaXiaPlayer() {
    delete mIOLayer;
}


void HuaXiaPlayer::setPlayUrl(JNIEnv *jniEnv, jstring playUrl) {
    mIOLayer->setPlayUrl(jniEnv, playUrl);
}

void HuaXiaPlayer::prepareAsync() {

    /**
     * 1.初始化缓冲队列、IO层、解码层、渲染层
     * 2.打开多媒体文件
     * 3.回调结果
     */
    mAudioPacketQ = new PacketQueue();
    mAudioFrameQ = new FrameQueue();
    mVideoPacketQ = new PacketQueue();
    mVideoFrameQ = new FrameQueue();

    mIOLayer->open(mAudioPacketQ, mVideoPacketQ, this, ioLayerOpened);
}
