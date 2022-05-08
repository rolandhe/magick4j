package com.jkqj.magick;

import java.nio.file.Files;
import java.nio.file.Paths;

public class BaseMagick {
    static {
        loadLib();
        init();
    }


    private static void loadLib(){
        String libResPath = String.format("/usr/lib/%s",System.mapLibraryName("Magick4J"));
        if(Files.exists(Paths.get(libResPath))) {
            System.load(libResPath);
            return;
        }
        libResPath = String.format("/usr/local/lib/%s",System.mapLibraryName("Magick4J"));
        if(Files.exists(Paths.get(libResPath))) {
            System.load(libResPath);
            return;
        }
        throw new RuntimeException("can't find Magick4J lib from system lib directory.");
    }
    private static native void init();

    private static native void clean();
}
