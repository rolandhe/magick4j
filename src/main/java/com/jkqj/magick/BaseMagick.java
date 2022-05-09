package com.jkqj.magick;

import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * 所有对象的基类，确保导入 .so库，并初始化ImageMagick
 *
 * @author hexiufeng
 */
public class BaseMagick {
    static {
        loadLib();
        init();
    }

    /**
     * 加载jni 库： libMagick4J.so,
     * 从linux系统的常用路径下搜索，需要提前安装
     *
     */
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

    /**
     * 初始化ImageMagick 库
     *
     */
    private static native void init();

    /**
     * 释放ImageMagick库资源，一般不用调用，因为kill -9会自动释放资源 ^_^
     */
    private static native void clean();
}
