package com.jkqj.magick;

public interface MagickEntity {

    long getHandler();

    void destroy();

    long detach();

    void attach(long handler);
}
