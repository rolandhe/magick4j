package com.jkqj.magick.log;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class MagickLog {
    private static final Logger LOGGER = LoggerFactory.getLogger(MagickLog.class);

    public static void logMagickException(int errorNumber, String reason, String description, String from) {
        LOGGER.info("magick error: errorNumber:{}, reason:{}, desc:{}, from: {}", errorNumber, reason, description, from);
    }

    public static void logMagickInfo(String message,String from){
        LOGGER.info("magick info: {}, from: {}", message, from);
    }
}
