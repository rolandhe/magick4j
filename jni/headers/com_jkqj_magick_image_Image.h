/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

#include "common.h"

/* Header for class com_jkqj_magick_image_Image */

#ifndef _Included_com_jkqj_magick_image_Image
#define _Included_com_jkqj_magick_image_Image
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    destroyHandler
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_destroyHandler
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    strip
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_strip
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageMask
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageMask
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getImageMask
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_getImageMask
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageExtent
 * Signature: (JII)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageExtent
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageAlpha
 * Signature: (JF)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageAlpha
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getImageAlphaChannel
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_getImageAlphaChannel
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    separateImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_separateImage
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getImageProperty
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_image_Image_getImageProperty
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getNextImageProperty
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_image_Image_getNextImageProperty
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageProperty
 * Signature: (JLjava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageProperty
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    removeImageProperty
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_image_Image_removeImageProperty
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    readImage
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_readImage
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    writeImage
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_writeImage
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    pingImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_pingImage
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    compositeImage
 * Signature: (JJIZJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_compositeImage
  (JNIEnv *, jclass, jlong, jlong, jint, jboolean, jlong, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    textureImage
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_textureImage
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    rotateImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_rotateImage
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    scaleImage
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_scaleImage
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getColumns
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_image_Image_getColumns
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getRows
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_image_Image_getRows
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getDelay
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_image_Image_getDelay
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setColumns
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setColumns
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setRows
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setRows
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setDelay
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setDelay
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    thumbnailImage
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_thumbnailImage
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBackgroundColor
 * Signature: (JDDD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBackgroundColor
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBorderColor
 * Signature: (JDDD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBorderColor
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble);


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    annotateImage
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_annotateImage
  (JNIEnv *, jclass, jlong, jlong);


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBackgroundColorString
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBackgroundColorString
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBorderColorString
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBorderColorString
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    drawImage
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_drawImage
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setMagick
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setMagick
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setFileName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setFileName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getTypeMetrics
 * Signature: (JJ)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_jkqj_magick_image_Image_getTypeMetrics
  (JNIEnv *, jclass, jlong, jlong);


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    shearImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_shearImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    integralRotateImage
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_integralRotateImage
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    shearRotateImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_shearRotateImage
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    deskewImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_deskewImage
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    adaptiveResizeImage
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_adaptiveResizeImage
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    autoOrientImage
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_autoOrientImage
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    blurImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_blurImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    adaptiveBlurImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_adaptiveBlurImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    adaptiveSharpenImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_adaptiveSharpenImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    embossImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_embossImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    gaussianBlurImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_gaussianBlurImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    kuwaharaImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_kuwaharaImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    sharpenImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_sharpenImage
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    spreadImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_spreadImage
  (JNIEnv *, jclass, jlong, jint,jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    bilateralBlurImage
 * Signature: (JIIDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_bilateralBlurImage
  (JNIEnv *, jclass, jlong, jint, jint, jdouble, jdouble);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    despeckleImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_despeckleImage
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    edgeImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_edgeImage
  (JNIEnv *, jclass, jlong, jdouble);

#ifdef __cplusplus
}
#endif
#endif