#include "headers/com_jkqj_magick_BaseMagick.h"


/*
 * Class:     com_jkqj_magick_BaseMagick
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_BaseMagick_init(JNIEnv *env, jclass jclazz)
{
    MagickCoreGenesis(NULL, MagickFalse);
}

/*
 * Class:     com_jkqj_magick_BaseMagick
 * Method:    clean
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_BaseMagick_clean
  (JNIEnv *env, jclass jclazz)
{
    MagickCoreTerminus();
}