package com.jkqj.magick.draw;

import com.jkqj.magick.BaseMagick;
import com.jkqj.magick.MagickEntity;

/**
 * 封装ImageMagick DrawInfo结构，用于控制在图片上绘制
 *
 * @author hexiufeng
 *
 */
public class DrawInfo extends BaseMagick implements MagickEntity {
    private long handler;

    /**
     * 初始化底层指针
     *
     * @return
     */
    private static native long init();

    /**
     * 销毁底层指针s
     * @param handler
     */
    private static native void destroy(long handler);

    private static native void setFont(long handler, String fontName);

    private static native void setText(long handler, String text);

    private static native void setMetrics(long handler, String metrics);

    private static native void setFontFamily(long handler, String family);


    private static native void setPointSize(long handler, double pointSize);

    private static native void annotation(long handler, double x, double y, String text);

    private static native void setFill(long handler, String color);

    private static native void setStroke(long handler, String color);

    private static native void setPrimitive(long handler, String primitiveCmd);

    /**
     * @param handler
     * @param gravityType GravityType
     */
    private static native void setGravity(long handler, int gravityType);

    /**
     * @param handler
     * @param align   AlignType
     */
    private static native void setAlign(long handler, int align);

    private static native void setViewBoxRectangle(long handler, long x, long y, int w, int h);

    private static native void setStrokeWidth(long handler, double width);

    private static native void setGeometry(long handler, double x, double y);

    private static native void setEncoding(long handler, String encoding);


    private DrawInfo() {

    }

    public static DrawInfo factory() {
        DrawInfo info = new DrawInfo();
        info.handler = init();

        return info;
    }

    public static DrawInfo factory(long handler) {
        DrawInfo info = new DrawInfo();
        info.handler = handler;

        return info;
    }

    @Override
    public long getHandler() {
        return handler;
    }

    @Override
    public void destroy() {
        if (this.handler == 0) {
            return;
        }
        destroy(handler);
        handler = 0;
    }

    @Override
    public long detach() {
        long tmp = handler;
        handler = 0;
        return tmp;
    }

    @Override
    public void attach(long handler) {
        destroy();
        this.handler = handler;
    }


    public void setFont(String fontName) {
        if (handler == 0) {
            return;
        }
        setFont(handler, fontName);
    }

    public void setFontSize(double size) {
        if (handler == 0) {
            return;
        }
        setPointSize(handler, size);
    }

    public void setFontFamily(String family) {
        if (handler == 0) {
            return;
        }
        setFontFamily(handler, family);
    }

    /**
     * 字体颜色设置
     * @param color
     */
    public void setFillColor(String color) {
        if (handler == 0) {
            return;
        }
        setFill(handler, color);
    }

    public void setStrokeColor(String color) {
        if (handler == 0) {
            return;
        }
        setStroke(handler, color);
    }

    /**
     * 需要绘制的文本
     *
     * @param text
     */
    public void setText(String text) {
        if (handler == 0) {
            return;
        }
        setText(handler, text);
    }


    public void setMetrics(String metrics) {
        if (handler == 0) {
            return;
        }
        setMetrics(handler, metrics);
    }

    /**
     * 设置绘制原语
     *
     * @param primitive
     */
    public void setPrimitive(String primitive) {
        if (handler == 0) {
            return;
        }
        setPrimitive(handler, primitive);
    }

    /**
     * 设置annotation原语，底层会对文本进行转义
     *
     * @param x
     * @param y
     * @param text
     */
    public void setAnnotationPrimitive(double x, double y, String text) {
        if (handler == 0) {
            return;
        }
        annotation(handler, x, y, text);
    }

    public void setGravity(int gravity) {
        if (handler == 0) {
            return;
        }
        setGravity(handler, gravity);
    }

    public void setAlign(int align) {
        if (handler == 0) {
            return;
        }
        setAlign(handler, align);
    }

    public void setViewBoxRectangle(long x, long y, int w, int h) {
        setViewBoxRectangle(handler, x, y, w, h);
    }

    public void setStrokeWidth(double w) {
        setStrokeWidth(handler, w);
    }

    /**
     * 设置绘制坐标
     *
     * @param x
     * @param y
     */
    public void setGeometry(double x, double y) {
        setGeometry(handler, x, y);
    }

    public void setEncoding(String encoding) {
        setEncoding(handler, encoding);
    }
}
