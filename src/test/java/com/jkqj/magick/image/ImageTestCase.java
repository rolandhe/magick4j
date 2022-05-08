package com.jkqj.magick.image;

import com.jkqj.magick.draw.DrawInfo;
import com.jkqj.magick.draw.PrimitiveSupport;
import com.jkqj.magick.support.GifSupport;
import org.junit.Test;

public class ImageTestCase {
    @Test
    public void testAnnotateByApiMode() {
        Image image = Image.factory();
        image.setColumns(500);
        image.setRows(300);
        image.setBackgroundColorString("black");

        DrawInfo drawInfo = DrawInfo.factory();
        drawInfo.setText("hello world!");
        drawInfo.setFontSize(45);
        drawInfo.setStrokeColor("yellow");
        drawInfo.setFillColor("white");
        drawInfo.setStrokeWidth(2);


        drawInfo.setGeometry(50, 50);

        image.annotateImage(drawInfo);


        image.writeImage("/Users/hexiufeng/data/gif/draw.png");

        drawInfo.destroy();
        image.destroy();
    }

    @Test
    public void testAnnotateByTextCommand() {
        Image image = Image.factory("/Users/hexiufeng/data/gif/gg.png", false);

        DrawInfo drawInfo = DrawInfo.factory();
        // 如果输出中文，必须设置支持中文的字体，比宋体
//        drawInfo.setFont();
        drawInfo.setFontSize(14);
        drawInfo.setStrokeColor("yellow");
        drawInfo.setFillColor("white");

        drawInfo.setAnnotationPrimitive(30, 30, "hello world!");

        image.drawImageByPrimitive(drawInfo);

        boolean ret = image.writeImage("/Users/hexiufeng/data/gif/gg1.png");

        drawInfo.destroy();

        System.out.println(image.getColumns());
        image.destroy();

    }

    @Test
    public void testAnnotateAndRotateByCommand() {
        Image image = Image.factory();
        image.setColumns(500);
        image.setRows(300);
        image.setBackgroundColorString("black");

        DrawInfo drawInfo = DrawInfo.factory();
        drawInfo.setFontSize(45);
        drawInfo.setStrokeColor("yellow");
        drawInfo.setFillColor("white");
        drawInfo.setStrokeWidth(2);

        String primitive = PrimitiveSupport.textRotatePrimitive(45, 100, 100, "hello world!");
        drawInfo.setPrimitive(primitive);

        image.drawImageByPrimitive(drawInfo);


        image.writeImage("/Users/hexiufeng/data/gif/draw1.png");

        drawInfo.destroy();
        image.destroy();
    }

    @Test
    public void testCompositeImage() {
        Image image = Image.factory();

        image.setBackgroundColorString("black");

        DrawInfo drawInfo = DrawInfo.factory();
//        drawInfo.setFont();
        drawInfo.setEncoding("utf-8");
        drawInfo.setText("hello world!");
        drawInfo.setFontSize(45);
//        drawInfo.setStrokeColor("blue");
        drawInfo.setFillColor("yellow");
//        drawInfo.setStrokeWidth(2);
        MetricInfo metricInfo = image.getTypeMetrics(drawInfo);


        image.setColumns((int) metricInfo.getWidth());
        image.setRows((int) metricInfo.getHeight());

        double h = metricInfo.getHeight();

        drawInfo.setGeometry(0, (int) h);
        image.annotateImage(drawInfo);

        Image backImage = Image.factory("/Users/hexiufeng/data/gif/gg.png", false);

        boolean r = backImage.compositeImage(image, CompositeOperator.SrcOverCompositeOp, 20L, 20L);


        image.writeImage("/Users/hexiufeng/data/gif/draw3.png");

        backImage.writeImage("/Users/hexiufeng/data/gif/draw4.png");
        backImage.destroy();

        drawInfo.destroy();
        image.destroy();
    }

    @Test
    public void testGifScacle() {

        boolean ret = GifSupport.scale("/Users/hexiufeng/data/gif/smart-clever.gif",
                "/Users/hexiufeng/data/gif/smart-clever23.gif", 200, 100);
        System.out.println(ret);
    }
}