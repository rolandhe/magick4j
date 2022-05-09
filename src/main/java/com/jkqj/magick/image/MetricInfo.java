package com.jkqj.magick.image;

/**
 * 绘制文本时，其所占用的空间信息描述
 *
 * @author hexiufeng
 */
public class MetricInfo {
    private double ascent;
    private double descent;
    private double width;
    private double height;

    public double getAscent() {
        return ascent;
    }

    public void setAscent(double ascent) {
        this.ascent = ascent;
    }

    public double getDescent() {
        return descent;
    }

    public void setDescent(double descent) {
        this.descent = descent;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
}
