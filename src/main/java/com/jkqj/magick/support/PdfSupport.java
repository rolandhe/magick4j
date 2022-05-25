package com.jkqj.magick.support;

import com.jkqj.magick.BaseMagick;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PdfSupport extends BaseMagick {
    public static final int CONVERT_ERROR = -1;
    public static native int convertPdfToPng(String pdfFile,String pngFile,String density, boolean outSingleFile);

    public static List<String> getResultFileNameList(int size, String outFileName){
        if(size == CONVERT_ERROR){
            return Collections.emptyList();
        }
        List<String> retList = new ArrayList<>(size);
        if(size == 1){
            retList.add(outFileName);
            return retList;
        }
        String prefix = outFileName.substring(0,outFileName.length() - 4);

        for(int i = 0;i < size;i++){
            retList.add(String.format("%s-%d.pdf",prefix,i));
        }
        return retList;
    }
}
