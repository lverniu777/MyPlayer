package com.huaxia.huaxiaplayer;

/**
 * 华夏播放器
 */
public class HuaXiaPlayer implements IPlayer {

    static {
        System.loadLibrary("huaxiaplayer");
    }

    /**
     * Native 指针
     */
    private int mNativePtr;


    public HuaXiaPlayer() {
        mNativePtr = nativeInit();
    }

    private native int nativeInit();

    @Override
    public void prepare() {
        nativePrepare(mNativePtr);
    }

    private native void nativePrepare(int mNativePtr);

    @Override
    public void prepareAsync() {
        nativePrepareAsync(mNativePtr);
    }

    private native void nativePrepareAsync(int nativePtr);

    @Override
    public void setPlayUrl(String playUrl) {
        nativeSetPlayUrl(mNativePtr, playUrl);
    }

    private native void nativeSetPlayUrl(int nativePtr, String playUrl);

    @Override
    public void start() {

    }

    @Override
    public void stop() {

    }

    @Override
    public void pause() {

    }

}
