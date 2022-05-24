#include "headers/com_jkqj_magick_support_GifSupport.h"
#include "headers/gif_support.h"

/*
 * Class:     com_jkqj_magick_support_GifSupport
 * Method:    scale
 * Signature: (Ljava/lang/String;Ljava/lang/String;II)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_support_GifSupport_scale
  (JNIEnv *env, jclass jclazz, jstring fromFile, jstring toFile, jint columns, jint rows)
{
    char srcFileName[MaxTextExtent];
    char toFileName[MaxTextExtent];

    acceptJString(env,fromFile,srcFileName);
    acceptJString(env,toFile,toFileName);

#ifdef _USING_TRACE_MODE_
    logInfo(env,"Java_com_jkqj_magick_support_GifSupport_scale", toFileName);
#endif

    MagickBooleanType ret =  scaleCore(env, srcFileName, toFileName,  rows,  columns, ScaleImage);
    if(ret)
    {
        return JNI_TRUE;
    }
    return JNI_FALSE;
}

/*
 * Class:     com_jkqj_magick_support_GifSupport
 * Method:    thumbnail
 * Signature: (Ljava/lang/String;Ljava/lang/String;II)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_support_GifSupport_thumbnail
 (JNIEnv *env, jclass jclazz, jstring fromFile, jstring toFile, jint columns, jint rows)
{
    char srcFileName[MaxTextExtent];
    char toFileName[MaxTextExtent];

    acceptJString(env,fromFile,srcFileName);
    acceptJString(env,toFile,toFileName);

#ifdef _USING_TRACE_MODE_
    logInfo(env,"Java_com_jkqj_magick_support_GifSupport_thumbnail", toFileName);
#endif

    MagickBooleanType ret =  scaleCore(env, srcFileName, toFileName,  rows,  columns, ThumbnailImage);
    if(ret)
    {
        return JNI_TRUE;
    }
    return JNI_FALSE;
}