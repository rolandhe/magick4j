package com.jkqj.magick.image;

import com.jkqj.magick.BaseMagick;
import com.jkqj.magick.MagickEntity;

/**
 * 图片元数据信息
 *
 * @author hexiufeng
 *
 */
public class ImageInfo extends BaseMagick implements MagickEntity {
    private long handler;

    private static native long init();

    private static native void destroyHandler(long handler);


    private static native void quality(long handler, int quality);

    /**
     * @param handler
     * @param compression CompressType
     */
    private static native void compression(long handler, int compression);

    private static native void setMagick(long handler, String fmt);

    private static native void setFileName(long handler, String fileName);

    private ImageInfo() {
    }

    public static ImageInfo factory() {
        ImageInfo imageInfo = new ImageInfo();

        imageInfo.handler = init();

        return imageInfo;
    }

    public static ImageInfo factory(long handler) {
        ImageInfo imageInfo = new ImageInfo();

        imageInfo.handler = handler;

        return imageInfo;
    }


    @Override
    public long getHandler() {
        return handler;
    }

    @Override
    public void destroy() {
        if (handler == 0) {
            return;
        }

        destroyHandler(handler);
        handler = 0;
    }

    @Override
    public long detach() {
        long curHandler = handler;
        handler = 0;
        return curHandler;
    }

    @Override
    public void attach(long handler) {
        destroy();
        this.handler = handler;
    }

    public void setQuality(int quality) {
        if (handler == 0) {
            return;
        }
        quality(handler, quality);
    }

    public void setCompression(int compression) {
        if (handler == 0) {
            return;
        }
        compression(handler, compression);
    }

    public void setImageFmt(String fmt) {
        if (handler == 0) {
            return;
        }
        setMagick(handler, fmt);
    }

    public void setFileName(String fileName) {
        if (handler == 0) {
            return;
        }
        setFileName(handler, fileName);
    }
}
