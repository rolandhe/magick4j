package com.jkqj.magick.image;

import com.jkqj.magick.BaseMagick;
import com.jkqj.magick.MagickEntity;
import com.jkqj.magick.draw.DrawInfo;

/**
 * 图片核心处理类
 *
 * @author hexiufeng
 *
 */
public class Image extends BaseMagick implements MagickEntity {
    private long handler;

    private static native long init(long imageInfoHandler);

    private static native void destroyHandler(long handler);

    private static native void strip(long handler);

    /**
     * @param imageHandler
     * @param pixelMask        PixelMask
     * @param maskImageHandler
     * @return
     */
    private static native boolean setImageMask(long imageHandler, int pixelMask, long maskImageHandler);

    /**
     * @param imageHandler
     * @param pixelMask    PixelMask
     * @return
     */
    private static native long getImageMask(long imageHandler, int pixelMask);


    private static native boolean setImageExtent(long imageHandler, int columns, int rows);

    private static native boolean setImageAlpha(long imageHandler, float alpha);

    private static native boolean getImageAlphaChannel(long handler);

    /**
     * @param handler
     * @param channelType ChannelType
     * @return
     */
    private static native long separateImage(long handler, int channelType);


    private static native String getImageProperty(long handler, String key);

    private static native String getNextImageProperty(long handler);

    private static native boolean setImageProperty(long handler, String key, String value);

    private static native String removeImageProperty(long handler, String key);


    private static native long readImage(String fileName);


    private static native boolean writeImage(long handler, String toFile);


    private static native long pingImage(long imageInfoHandler);

    /**
     * @param handler
     * @param compositeOp     CompositeOperator
     * @param srcImageHandler
     * @param x
     * @param y
     * @return
     */
    private static native boolean compositeImage(long handler, long srcImageHandler, int compositeOp, boolean clipToSelf, long x, long y);

    private static native boolean textureImage(long handler, long srcImageHandler);


    /**
     * https://imagemagick.org/api/distort.php
     *
     * @param handler
     * @param degrees
     * @return
     */
    private static native long rotateImage(long handler, double degrees);

    private static native long scaleImage(long handler, int columns, int rows);

    private static native int getColumns(long handler);

    private static native int getRows(long handler);

    private static native int getDelay(long handler);

    private static native void setColumns(long handler, int columns);

    private static native void setRows(long handler, int rows);

    private static native void setDelay(long handler, int delay);

    /**
     * ThumbnailImage() changes the size of an image to the given dimensions and removes any associated profiles.
     * The goal is to produce small low cost thumbnail images suited for display on the Web.
     *
     * @param handler
     * @param columns
     * @param rows
     * @return
     */
    public static native long thumbnailImage(long handler, int columns, int rows);

    private static native void setBackgroundColor(long handler, double r, double g, double b);

    private static native void setBorderColor(long handler, double r, double g, double b);

    private static native boolean annotateImage(long handler, long drawHandler);

    private static native void setBackgroundColorString(long handler, String color);

    private static native void setBorderColorString(long handler, String color);


    private static native void drawImage(long handler, long drawHandler);

    private static native void setMagick(long handler, String fmt);

    /**
     * 暂时不用
     *
     * @param handler
     * @param fileName
     */
    private static native void setFileName(long handler, String fileName);

    private static native double[] getTypeMetrics(long handler, long drawInfoHandler);

    private static native long shearImage(long handler, double x, double y);

    private static native long integralRotateImage(long handler, int rotations);

    private static native long shearRotateImage(long handler, double degrees);

    private static native long deskewImage(long handler, double threshold);

    private static native long adaptiveResizeImage(long handler, int columns, int rows);


    private static native long blurImage(long handler, double radius, double sigma);

    private static native long adaptiveBlurImage(long handler, double radius, double sigma);

    private static native long adaptiveSharpenImage(long handler, double radius, double sigma);

    private static native long embossImage(long handler, double radius, double sigma);

    private static native long gaussianBlurImage(long handler, double radius, double sigma);

    private static native long kuwaharaImage(long handler, double radius, double sigma);

    private static native long sharpenImage(long handler, double radius, double sigma);

    /**
     * @param handler
     * @param method  PixelInterpolateMethod
     * @param radius
     * @return
     */
    private static native long spreadImage(long handler, int method, double radius);

    private static native long bilateralBlurImage(long handler, int width, int height, double intensitySigma, double spatialSigma);

    private static native long despeckleImage(long handler);

    private static native long edgeImage(long handler, double radius);

    private Image() {

    }

    public static Image factory() {
        Image image = new Image();
        ImageInfo imageInfo = ImageInfo.factory();

        image.handler = init(imageInfo.getHandler());
        imageInfo.destroy();

        return image;
    }

    public static Image factory(long handler) {
        if (handler == 0) {
            return null;
        }

        Image image = new Image();

        image.attach(handler);
        return image;
    }

    /**
     * 基于文件构建图片对象
     *
     * @param fileName
     * @return
     */
    public static Image factory(String fileName) {
        return factory(fileName,false);
    }

    /**
     * 基于文件构建图片对象
     *
     * @param fileName
     * @param ping  true, 仅仅读取基础原数据信息，资源消耗少， false，读取图片所有数据
     * @return
     */
    public static Image factory(String fileName, boolean ping) {
        long imageHandler = 0;
        if (ping) {
            ImageInfo imageInfo = ImageInfo.factory();
            imageInfo.setFileName(fileName);
            try {
                imageHandler = pingImage(imageInfo.getHandler());
            } finally {
                imageInfo.destroy();
            }
        } else {
            imageHandler = readImage(fileName);
        }
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public void strip() {
        if (handler == 0) {
            return;
        }
        strip(handler);
    }

    public Image rotateImage(double degrees) {
        if (handler == 0) {
            return null;
        }

        long rotateHandler = rotateImage(handler, degrees);
        if (rotateHandler == 0) {
            return null;
        }
        return Image.factory(rotateHandler);
    }

    public Image scaleImage(int columns, int rows) {
        if (handler == 0) {
            return null;
        }

        long scaleHandler = scaleImage(handler, columns, rows);
        if (scaleHandler == 0) {
            return null;
        }
        return Image.factory(scaleHandler);
    }

    public Image thumbnailImage(int columns, int rows) {
        if (handler == 0) {
            return null;
        }

        long thumbnailHandler = thumbnailImage(handler, columns, rows);
        if (thumbnailHandler == 0) {
            return null;
        }
        return Image.factory(thumbnailHandler);
    }

    public boolean writeImage(String toFile) {
        if (handler == 0) {
            return false;
        }
        return writeImage(handler, toFile);
    }

    public boolean compositeImage(Image srcImage, int compositeOp, boolean clipToSelf, long x, long y) {
        if (handler == 0 || srcImage == null || srcImage.getHandler() == 0) {
            return false;
        }
        return compositeImage(handler, srcImage.getHandler(), compositeOp, clipToSelf, x, y);
    }

    public boolean compositeImage(Image srcImage, int compositeOp, long x, long y) {
        return compositeImage(srcImage, compositeOp, true, x, y);
    }

    public boolean textureImage(Image srcImage) {
        if (handler == 0 || srcImage == null || srcImage.getHandler() == 0) {
            return false;
        }
        return textureImage(handler, srcImage.getHandler());
    }

    /**
     * 必须设置DrawInfo.setGeometry
     * <p>
     * 注意:也可以使用DrawInfo.setAnnotationPrimitive + drawImage完成相应功能
     *
     * @param drawInfo
     * @return
     */
    public boolean annotateImage(DrawInfo drawInfo) {
        if (handler == 0 || drawInfo == null || drawInfo.getHandler() == 0) {
            return false;
        }
        return annotateImage(handler, drawInfo.getHandler());
    }

    /**
     * primitive是一个文本命令，eg. "rotate 45 text 10,10 'Works like magick!'".
     * 同 convert -draw 文本命令。
     * 基于primitive可以实现和convert -draw完全相同的能力s
     *
     * @param drawInfo DrawInfo.setPrimitive必须被配置
     */
    public void drawImageByPrimitive(DrawInfo drawInfo) {
        if (handler == 0 || drawInfo == null || drawInfo.getHandler() == 0) {
            return;
        }
        drawImage(handler, drawInfo.getHandler());
    }

    /**
     * 按照通道分离图片
     *
     * @param channelType  ChannelType
     * @return
     */
    public Image separateImage(int channelType) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = separateImage(handler, channelType);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    /**
     * 锐化
     *
     * @param x
     * @param y
     * @return
     */
    public Image shearImage(double x, double y) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = shearImage(handler, x, y);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image integralRotateImage(int rotations) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = integralRotateImage(handler, rotations);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image shearRotateImage(double degrees) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = shearRotateImage(handler, degrees);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image deskewImage(double threshold) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = deskewImage(handler, threshold);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image adaptiveResizeImage(int columns, int rows) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = adaptiveResizeImage(handler, columns, rows);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }


    public Image blurImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = blurImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image adaptiveBlurImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = adaptiveBlurImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image adaptiveSharpenImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = adaptiveSharpenImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image embossImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = embossImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image gaussianBlurImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = gaussianBlurImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image kuwaharaImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = kuwaharaImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image sharpenImage(double radius, double sigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = sharpenImage(handler, radius, sigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }


    public Image spreadImage(int method, double radius) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = spreadImage(handler, method, radius);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image bilateralBlurImage(int width, int height, double intensitySigma, double spatialSigma) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = bilateralBlurImage(handler, width, height, intensitySigma, spatialSigma);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image despeckleImage() {
        if (handler == 0) {
            return null;
        }
        long imageHandler = despeckleImage(handler);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public Image edgeImage(double radius) {
        if (handler == 0) {
            return null;
        }
        long imageHandler = edgeImage(handler, radius);
        if (imageHandler == 0) {
            return null;
        }
        return Image.factory(imageHandler);
    }

    public MetricInfo getTypeMetrics(DrawInfo drawInfo) {
        double[] ret = getTypeMetrics(handler, drawInfo.getHandler());
        if (ret == null) {
            return null;
        }
        MetricInfo metricInfo = new MetricInfo();
        int index = 0;
        metricInfo.setAscent(ret[index++]);
        metricInfo.setDescent(ret[index++]);
        metricInfo.setWidth(ret[index++]);
        metricInfo.setHeight(ret[index++]);

        return metricInfo;
    }


    public void setImageMask(int pixelMask, Image maskImage) {
        if (handler == 0) {
            return;
        }
        setImageMask(handler, pixelMask, maskImage.getHandler());
    }

    public Image getImageMask(int pixelMask) {
        if (handler == 0) {
            return null;
        }
        long maskHandler = getImageMask(handler, pixelMask);
        if (maskHandler == 0) {
            return null;
        }
        return Image.factory(maskHandler);
    }

    public boolean setImageExtent(int columns, int rows) {
        if (handler == 0) {
            return false;
        }
        return setImageExtent(handler, columns, rows);
    }

    public void setImageAlpha(float alpha) {
        if (handler == 0) {
            return;
        }
        setImageAlpha(handler, alpha);
    }

    public boolean hasAlphaChannel() {
        if (handler == 0) {
            return false;
        }
        return getImageAlphaChannel(handler);
    }

    public String getImageProperty(String key) {
        if (handler == 0) {
            return null;
        }
        return getImageProperty(handler, key);
    }

    public boolean setImageProperty(String key, String value) {
        if (handler == 0) {
            return false;
        }
        return setImageProperty(handler, key, value);
    }

    public String getNextImageProperty() {
        if (handler == 0) {
            return null;
        }
        return getNextImageProperty(handler);
    }


    public String removeImageProperty(String key) {
        if (handler == 0) {
            return null;
        }
        return removeImageProperty(handler, key);
    }

    public int getColumns() {
        return getColumns(handler);
    }

    public void setColumns(int columns) {
        setColumns(handler, columns);
    }

    public int getRows() {
        return getRows(handler);
    }

    public void setRows(int rows) {
        setRows(handler, rows);
    }


    public int getDelay() {
        return getDelay(handler);
    }

    public void setDelay(int delay) {
        setDelay(handler, delay);
    }

    public void setBackgroundColor(double r, double g, double b) {
        setBackgroundColor(handler, r, g, b);
    }

    public void setBackgroundColorString(String color) {
        setBackgroundColorString(handler, color);
    }

    public void setBorderColor(double r, double g, double b) {
        setBorderColor(handler, r, g, b);
    }

    public void setBorderColorString(String color) {
        setBorderColorString(handler, color);
    }

    public void setFileFmt(String fmt) {
        setMagick(handler, fmt);
    }

    public void setFileName(String fileName) {
        setFileName(handler, fileName);
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
}
