package com.huaxia.huaxiaplayer;


public interface IPlayer {
    /**
     * 播放器以同步的方式进行初始化操作
     */
    void prepare();

    /**
     * 播放器以异步的方式进行初始化操作，结果通过回调通知
     */
    void prepareAsync();

    void setPlayUrl(String playUrl);

    void start();

    void stop();

    void pause();

}
