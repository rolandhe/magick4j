package com.jkqj.magick.log;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * 用于jni c 库的回调输出：<br>
 * <ul>
 *     <li>ImageMagick产生的异常</li>
 *     <li>jni c 的输出日志</li>
 * </ul>
 *
 * @author hexiufeng
 */
public class MagickLog {
    private static final Logger LOGGER = LoggerFactory.getLogger(MagickLog.class);

    /**
     * 输出ImageMagick产生的异常信息，来自ExceptionInfo的信息。
     * 由logException c函数回调
     *
     * @param errorNumber  ExceptionInfo.error_number
     * @param reason   ExceptionInfo.reason
     * @param description ExceptionInfo.description
     * @param from   哪个调用方法返回的
     */
    public static void logMagickException(int errorNumber, String reason, String description, String from) {
        LOGGER.error("magick error: errorNumber:{}, reason:{}, desc:{}, from: {}", errorNumber, reason, description, from);
    }

    /**
     * 输出 Magick4J.so的日志信息。
     * 由logInfo c函数回调
     *
     * @param message  日志消息
     * @param from  哪个调用方法返回的
     */
    public static void logMagickInfo(String message,String from){
        LOGGER.info("magick info: {}, from: {}", message, from);
    }
}
