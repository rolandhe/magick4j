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

    acceptJString(env,fromFile,srcFileName,MaxTextExtent - 1);
    acceptJString(env,toFile,toFileName,MaxTextExtent - 1);
    MagickBooleanType ret =  scaleCore( srcFileName, toFileName,  rows,  columns);
    if(ret)
    {
        return JNI_TRUE;
    }
    return JNI_FALSE;
}