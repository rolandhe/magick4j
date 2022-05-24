#include "headers/com_jkqj_magick_image_ImageInfo.h"

/*
 * Class:     com_jkqj_magick_image_ImageInfo
 * Method:    init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageInfo_init
  (JNIEnv *env , jclass jclazz)
{
   return (jlong)CloneImageInfo(NULL);
}

/*
 * Class:     com_jkqj_magick_image_ImageInfo
 * Method:    destroyHandler
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_ImageInfo_destroyHandler
  (JNIEnv *env , jclass jclazz, jlong handler)
{
   if(handler == NULL)
   {
     return;
   }
   DestroyImageInfo((ImageInfo*)handler);
}

/*
 * Class:     com_jkqj_magick_image_ImageInfo
 * Method:    quality
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_ImageInfo_quality
 (JNIEnv *env, jclass jclazz, jlong handler, jint quality)
 {
    ImageInfo * info = (ImageInfo*)handler;
    if(info == NULL)
    {
      return;
    }
    info->quality = (size_t) quality;
 }

/*
 * Class:     com_jkqj_magick_image_ImageInfo
 * Method:    compression
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_ImageInfo_compression
 (JNIEnv *env, jclass jclazz, jlong handler, jint compression)
 {
    ImageInfo * info = (ImageInfo*)handler;
    if(info == NULL)
    {
      return;
    }
    info->compression = compression;
 }

/*
 * Class:     com_jkqj_magick_image_ImageInfo
 * Method:    setMagick
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_ImageInfo_setMagick
  (JNIEnv *env, jclass jclazz, jlong handler, jstring fmt)
{
      ImageInfo * info = (ImageInfo*)handler;
      if(info == NULL)
      {
        return;
      }
      acceptJString(env,fmt,info->magick);
}

/*
 * Class:     com_jkqj_magick_image_ImageInfo
 * Method:    setFileName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_ImageInfo_setFileName
   (JNIEnv *env, jclass jclazz, jlong handler, jstring fileName)
{
      ImageInfo * info = (ImageInfo*)handler;
      if(info == NULL)
      {
        return;
      }
      acceptJString(env, fileName, info->filename);
}