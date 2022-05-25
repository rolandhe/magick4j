package com.jkqj.magick.image;

import com.jkqj.magick.draw.DrawInfo;
import com.jkqj.magick.draw.PrimitiveSupport;
import com.jkqj.magick.support.GifSupport;
import com.jkqj.magick.support.PdfSupport;
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

    @Test
    public void testPingGif() {

        Image image = Image.factory("/Users/hexiufeng/data/gif/smart-clever.gif", true);

        String fmt = image.getFormat();
        System.out.println(fmt);
        image.destroy();
//       image.get
//        System.out.println(ret);
    }

    @Test
    public void separateImageTest() {
        Image image = Image.factory("/Users/hexiufeng/data/gif/1-2-free-png-image.png");

        Image to = image.separateImage(ChannelType.GreenChannel);

        to.writeImage("/Users/hexiufeng/data/gif/1-2-free-png-image-k.png");
        to.destroy();
        image.destroy();

    }

    @Test
    public void cropImageTest() {
        Image image = Image.factory("/Users/hexiufeng/data/gif/1-2-free-png-image.png");

        int w = image.getColumns();
        int h = image.getRows();

        Image to = ImageTransform.cropImage(image, 0, 0, w / 2, h);

        to.writeImage("/Users/hexiufeng/data/gif/1-2-free-png-image-l.png");
        to.destroy();
        image.destroy();
    }

    @Test
    public void convertPdfToPngTest(){
        String pdf = "/Users/hexiufeng/img/pdf-img/t.pdf";
        String png = "/Users/hexiufeng/img/pdf-img/tg.png";
        int  ret =  PdfSupport.convertPdfToPng(pdf,png,null,false);
        if(ret == PdfSupport.CONVERT_ERROR) {
            System.out.println(ret);
        }

        System.out.println(ret);
        System.out.println(PdfSupport.getResultFileNameList(ret,png));
    }
}
