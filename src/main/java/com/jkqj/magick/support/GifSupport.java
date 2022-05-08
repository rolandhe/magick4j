package com.jkqj.magick.support;

import com.jkqj.magick.BaseMagick;

public class GifSupport extends BaseMagick {
    public static native boolean scale(String fromGifFile, String toGifFile, int columns, int rows);
}
