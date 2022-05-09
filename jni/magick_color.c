#include "headers/com_jkqj_magick_draw_Color.h"

/*
 * Class:     com_jkqj_magick_draw_Color
 * Method:    getColorInfo
 * Signature: (Ljava/lang/String;)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_jkqj_magick_draw_Color_getColorInfo
  (JNIEnv *env, jclass jclazz, jstring colorName)
{ 
    char name[128];
    acceptJString(env,colorName,name,127);
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    ColorInfo * colorInfo = GetColorInfo(name,exception);
    if(colorInfo == NULL)
    {
        logException(env,"Java_com_jkqj_magick_draw_Color_getColorInfo",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }

    DestroyExceptionInfo(exception);

    jdoubleArray array =  (*env)->NewDoubleArray(env,5);

    (*env)->SetDoubleArrayRegion(env,array, 0,1,&(colorInfo->color.red));
    (*env)->SetDoubleArrayRegion(env,array, 1,1,&(colorInfo->color.green));
    (*env)->SetDoubleArrayRegion(env,array, 2,1,&(colorInfo->color.blue));
    (*env)->SetDoubleArrayRegion(env,array, 3,1,&(colorInfo->color.alpha));
    (*env)->SetDoubleArrayRegion(env,array, 4,1,&(colorInfo->color.index));
    return array;
}