package com.jkqj.magick.image;

public interface PixelMask {
    int UndefinedPixelMask = 0x000000;
    int ReadPixelMask = 0x000001;
    int WritePixelMask = 0x000002;
    int CompositePixelMask = 0x000004;
}
