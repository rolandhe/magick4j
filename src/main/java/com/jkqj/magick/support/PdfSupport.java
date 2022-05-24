package com.jkqj.magick.support;

import com.jkqj.magick.BaseMagick;

public class PdfSupport extends BaseMagick {
    public static native boolean convertPdfToPng(String pdfFile,String pngFile,String density, boolean rmTempFile);
}
