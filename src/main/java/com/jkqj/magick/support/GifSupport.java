package com.jkqj.magick.support;

import com.jkqj.magick.BaseMagick;

/**
 * 处理gif图片的快捷方法，所有逻辑直接封装在c代码中，该类只是个套壳，可以保证性能
 *
 * @author hexiufeng
 *
 */
public class GifSupport extends BaseMagick {
    /**
     * gif的缩放，缩放完了依然是动图
     *
     * @param fromGifFile
     * @param toGifFile
     * @param columns
     * @param rows
     * @return
     */
    public static native boolean scale(String fromGifFile, String toGifFile, int columns, int rows);

    /**
     * gif的缩略图，缩略图依然是动图。
     *
     * 它和scale区别是：thumbnail 会删除元数据信息，比如profile，让图片所占字节更少
     *
     * @param fromGifFile
     * @param toGifFile
     * @param columns
     * @param rows
     * @return
     */
    public static native boolean thumbnail(String fromGifFile, String toGifFile, int columns, int rows);
}
