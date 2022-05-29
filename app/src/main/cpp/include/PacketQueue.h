//
// Created by Administrator on 2022/5/29.
//

#ifndef HUAXIAPLAYER_PACKETQUEUE_H
#define HUAXIAPLAYER_PACKETQUEUE_H

#include <queue>
#include "libavformat/avformat.h"

using namespace std;

/**
 * 线程安全的Packet缓冲队列
 */
class PacketQueue {
private:
    queue<AVPacket> mPacketQueue;
};


#endif //HUAXIAPLAYER_PACKETQUEUE_H
