package com.jkqj.magick.draw;

public class PrimitiveSupport {

    public static native String escapeString(String src);

    private PrimitiveSupport() {
    }

    public static String defaultImagePrimitive(int x, int y, int w, int h, String fileName) {
        String format = "image SrcOver %d,%d %d,%d %s";
        return String.format(format, x, y, w, h, fileName);
    }

    public static String imagePrimitive(int x, int y, int w, int h, String imageFileName, String op) {
        String format = "image %s %d,%d %d,%d %s";
        return String.format(format, x, y, w, h, op, imageFileName);
    }

    public static String textPrimitive(double x, double y, String text) {
        String format = "text %.20g %.20g '%s'";

        return String.format(format, x, y, escapeString(text));
    }

    public static String textRotatePrimitive(int rotate, int x, int y, String text) {
//        String format = "rotate %.20g text %.20g %.20g '%s'\n";
        String format = "rotate %d text %d %d '%s'";

        return String.format(format, rotate, x, y, escapeString(text));
    }
}
