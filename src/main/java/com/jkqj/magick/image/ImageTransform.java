package com.jkqj.magick.image;

import com.jkqj.magick.BaseMagick;
import com.jkqj.magick.support.GifSupport;

/**
 * 图片转换工具
 *
 * @author hexiufeng
 */
public class ImageTransform extends BaseMagick {
    /**
     * @param imageHandler
     * @param orientation  {@link OrientationType}
     * @return
     */
    private static native long autoOrientImage(long imageHandler, int orientation);

    private static native long chopImage(long imageHandler, long x, long y, int width, int height);

    private static native long cropImage(long imageHandler, long x, long y, int width, int height);

    private static native long flipImage(long imageHandler);

    private static native long flopImage(long imageHandler);

    private static native long transposeImage(long imageHandler);

    private static native long transverseImage(long imageHandler);


    private static native long trimImage(long imageHandler);


    public static Image autoOrientImage(Image src, int orientation) {
        long handler = autoOrientImage(src.getHandler(), orientation);
        return Image.factory(handler);
    }

    public static Image chopImage(Image src, long x, long y, int width, int height) {
        long handler = chopImage(src.getHandler(), x, y, width, height);
        return Image.factory(handler);
    }


    /**
     * 裁剪图片
     *
     * @param src
     * @param x
     * @param y
     * @param width
     * @param height
     * @return
     */
    public static Image cropImage(Image src, long x, long y, int width, int height) {
        long handler = cropImage(src.getHandler(), x, y, width, height);
        return Image.factory(handler);
    }

    public static Image flipImage(Image src) {
        long handler = flipImage(src.getHandler());
        return Image.factory(handler);
    }

    public static Image flopImage(Image src) {
        long handler = flopImage(src.getHandler());
        return Image.factory(handler);
    }

    public static Image transposeImage(Image src) {
        long handler = transposeImage(src.getHandler());
        return Image.factory(handler);
    }

    public static Image transverseImage(Image src) {
        long handler = transverseImage(src.getHandler());
        return Image.factory(handler);
    }

    public static Image trimImage(Image src) {
        long handler = trimImage(src.getHandler());
        return Image.factory(handler);
    }

    public static boolean quickScaleImage(String srcImgFile, String dstImgFile, int columns, int rows, boolean useThumbnail) {
        Image src = Image.factory(srcImgFile, true);
        if (src == null) {
            return false;
        }

        String fmt = src.getFormat();
        src.destroy();
        if (fmt.equalsIgnoreCase("GIF")) {
            if (useThumbnail) {
                return GifSupport.thumbnail(srcImgFile, dstImgFile, columns, rows);
            }
            return GifSupport.scale(srcImgFile, dstImgFile, columns, rows);
        }

        src = Image.factory(srcImgFile);

        Image dstImage = null;

        if (useThumbnail) {
            dstImage = src.thumbnailImage(columns, rows);
        } else {
            dstImage = src.scaleImage(columns, rows);
        }
        src.destroy();
        if (dstImage == null) {
            return false;
        }
        boolean ret = dstImage.writeImage(dstImgFile);

        dstImage.destroy();

        return ret;
    }
}
