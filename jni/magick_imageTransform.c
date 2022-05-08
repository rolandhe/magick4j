#include "headers/com_jkqj_magick_image_ImageTransform.h"


/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    autoOrientImage
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_autoOrientImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint orientation)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = AutoOrientImage(image,orientation,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    chopImage
 * Signature: (JJJII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_chopImage
  (JNIEnv * env, jclass jclazz, jlong handler, jlong x, jlong y, jint w, jint h)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }

    RectangleInfo chopInfo;

    chopInfo.x = x;
    chopInfo.y = y;
    chopInfo.width = w;
    chopInfo.height = h;
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = ChopImage(image,&chopInfo,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    cropImage
 * Signature: (JJJII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_cropImage
  (JNIEnv * env, jclass jclazz, jlong handler, jlong x, jlong y, jint w, jint h)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }

    RectangleInfo cropInfo;

    cropInfo.x = x;
    cropInfo.y = y;
    cropInfo.width = w;
    cropInfo.height = h;
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = CropImage(image,&cropInfo,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    flipImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_flipImage
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = FlipImage(image,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    flopImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_flopImage
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = FlopImage(image,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    transposeImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_transposeImage
   (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = TransposeImage(image,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    transverseImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_transverseImage
   (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = TransverseImage(image,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_ImageTransform
 * Method:    trimImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_ImageTransform_trimImage
   (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = TrimImage(image,exception);
    if(newImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}