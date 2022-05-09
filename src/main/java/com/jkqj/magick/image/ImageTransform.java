package com.jkqj.magick.image;

import com.jkqj.magick.BaseMagick;

/**
 * 图片转换工具
 *
 * @author hexiufeng
 *
 */
public class ImageTransform extends BaseMagick {
    /**
     *
     * @param imageHandler
     * @param orientation  OrientationType
     * @return
     */
    private static native  long autoOrientImage(long imageHandler, int orientation);

    private static native long chopImage(long imageHandler,long x,long y, int width, int height);

    private static native long cropImage(long imageHandler,long x,long y, int width, int height);

    private static native long flipImage(long imageHandler);

    private static native long flopImage(long imageHandler);

    private static native long transposeImage(long imageHandler);

    private static native long transverseImage(long imageHandler);


    private static native long trimImage(long imageHandler);


    public static Image autoOrientImage(Image src, int orientation){
        long handler = autoOrientImage(src.getHandler(), orientation);
        return Image.factory(handler);
    }

    public static Image chopImage(Image src,long x,long y, int width, int height){
        long handler = chopImage(src.getHandler(),x,y,width,height);
        return Image.factory(handler);
    }


    public static Image cropImage(Image src,long x,long y, int width, int height){
        long handler = cropImage(src.getHandler(),x,y,width,height);
        return Image.factory(handler);
    }

    public static  Image flipImage(Image src){
        long handler = flipImage(src.getHandler());
        return Image.factory(handler);
    }

    public static  Image flopImage(Image src){
        long handler = flopImage(src.getHandler());
        return Image.factory(handler);
    }

    public static  Image transposeImage(Image src){
        long handler = transposeImage(src.getHandler());
        return Image.factory(handler);
    }

    public static  Image transverseImage(Image src){
        long handler = transverseImage(src.getHandler());
        return Image.factory(handler);
    }

    public static  Image trimImage(Image src){
        long handler = trimImage(src.getHandler());
        return Image.factory(handler);
    }
}
