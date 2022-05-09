#include "headers/com_jkqj_magick_image_Image.h"

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    init
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_init
  (JNIEnv * env, jclass jclazz, jlong imageInfoHandler)
{
    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();

    ImageInfo * imageInfo = (ImageInfo *) imageInfoHandler;

    if(imageInfo == NULL)
    {
      return NULL;
    }

    Image * image = AcquireImage(imageInfo,exception);

    if(image == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_init",exception);
    }
    

    DestroyExceptionInfo(exception);

    return image;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    destroyHandler
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_destroyHandler
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image* image = (Image*)handler;
    if(image == NULL)
    {
      return;
    }
    DestroyImageList(image);
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    strip
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_strip
  (JNIEnv *env, jclass jclazz, jlong handler)
{
  Image* image = (Image*)handler;
    if(image == NULL)
    {
      return;
    }
    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();
    MagickBooleanType ret = StripImage(image, exception);
    if(MagickFalse == ret)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_strip",exception);
    }
        

    DestroyExceptionInfo(exception);

}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageMask
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageMask
  (JNIEnv * env, jclass jclazz, jlong handler, jint pixelMask, jlong maskImageHandler)
{
    Image * image;
    Image* mask;
    image = (Image*)handler;
    mask = (Image*) maskImageHandler;

    if(image == NULL || mask == NULL)
    {
      return JNI_FALSE;
    }

    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();
    MagickBooleanType ret = SetImageMask(image, pixelMask, mask,exception);
    if(MagickFalse == ret)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_setImageMask",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }
        

    DestroyExceptionInfo(exception);

    return JNI_TRUE;

}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getImageMask
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_getImageMask
    (JNIEnv *env, jclass jclazz, jlong handler, jint pixelMask)
{
    Image * image;
    Image* mask;
    image = (Image*)handler;
  

    if(image == NULL)
    {
      return JNI_FALSE;
    }

    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();
    mask = GetImageMask(image, pixelMask, exception);
    if(mask == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_getImageMask",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
        

    DestroyExceptionInfo(exception);

    return (jlong)mask;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageExtent
 * Signature: (JII)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageExtent
  (JNIEnv *env, jclass jclazz, jlong handler, jint columns, jint rows)
{
    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return JNI_FALSE;
    }

    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();
    MagickBooleanType ret = SetImageExtent(image,columns,rows,exception);
    if(MagickFalse == ret)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_setImageExtent",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }

    DestroyExceptionInfo(exception);
    return JNI_TRUE;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageAlpha
 * Signature: (JF)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageAlpha
  (JNIEnv *env, jclass jclazz, jlong handler, jfloat alpha)
{
    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return JNI_FALSE;
    }

    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();

    MagickBooleanType ret = SetImageAlpha(image,alpha,exception);
    if(MagickFalse == ret)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_setImageAlpha",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }

    DestroyExceptionInfo(exception);
    return JNI_TRUE;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getImageAlphaChannel
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_getImageAlphaChannel
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return JNI_FALSE;
    }
    MagickBooleanType ret =  GetImageAlphaChannel(image);
  
    if(ret == MagickFalse){
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    separateImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_separateImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint channelType)
{
    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return NULL;
    }

    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();

    Image * newImage = SeparateImage(image,channelType,exception);

    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_separateImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getImageProperty
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_image_Image_getImageProperty
  (JNIEnv *env, jclass jclazz, jlong handler, jstring propName)
{
    char key[DEFAULT_MAX_LEN];

    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return NULL;
    }

    acceptJString(env, propName,key,DEFAULT_MAX_LEN - 1);


    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();


    const char * prop = GetImageProperty(image,key,exception);
    if(prop == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_getImageProperty",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);

    return toJstring(env, prop);
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getNextImageProperty
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_image_Image_getNextImageProperty
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return NULL;
    }

    const char * prop =  GetNextImageProperty(image);
    if(prop == NULL)
    {
        return NULL;
    }

    return toJstring(env, prop);
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setImageProperty
 * Signature: (JLjava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_setImageProperty
  (JNIEnv *env, jclass jclazz, jlong handler, jstring propName, jstring propValue)
{
    char key[DEFAULT_MAX_LEN];
    char value[DEFAULT_MAX_LEN];

    Image * image;
    image = (Image*)handler;


    if(image == NULL)
    {
        return JNI_FALSE;
    }

    acceptJString(env, propName,key,DEFAULT_MAX_LEN - 1);
    acceptJString(env, propValue,value,DEFAULT_MAX_LEN - 1);



    ExceptionInfo *exception;
    exception=AcquireExceptionInfo();


    MagickBooleanType ret = SetImageProperty(image,key,value,exception);
    if(ret == MagickFalse)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_setImageProperty",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }
    DestroyExceptionInfo(exception);

    return JNI_TRUE;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    removeImageProperty
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_image_Image_removeImageProperty
  (JNIEnv *env, jclass jclazz, jlong handler, jstring propName)
{
    char key[DEFAULT_MAX_LEN];
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return JNI_FALSE;
    }

    acceptJString(env, propName,key,DEFAULT_MAX_LEN - 1);

    char * old = RemoveImageProperty(image,key);

    if(old == NULL)
    {
        return NULL;
    }

    return toJstring(env, old);
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    readImage
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_readImage
  (JNIEnv *env, jclass jclazz, jstring path)
{
    ImageInfo * imageInfo =  CloneImageInfo(NULL);
    if(imageInfo == NULL)
    {
        return NULL;
    }
    acceptJString(env, path, imageInfo->filename, MagickPathExtent - 1);
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * image = ReadImage(imageInfo,exception);

    DestroyImageInfo(imageInfo);

    if(image == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_readImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)image;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    writeImage
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_writeImage
  (JNIEnv *env, jclass jclazz, jlong handler, jstring toFile)
{
    Image * image;
    ImageInfo* imageInfo;
    image = (Image*)handler;
    
    if(image == NULL)
    {
      return JNI_FALSE;
    }

    imageInfo = CloneImageInfo(NULL);

    

    acceptJString(env,toFile,image->filename,MagickPathExtent - 1);

#ifdef _USING_TRACE_MODE_
    logInfo(env,"Java_com_jkqj_magick_image_Image_writeImage", image->filename);
#endif


    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    MagickBooleanType ret =  WriteImage(imageInfo,image,exception);
    DestroyImageInfo(imageInfo);
    if(ret == MagickFalse)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_writeImage",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }
    DestroyExceptionInfo(exception);
    return JNI_TRUE;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    pingImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_pingImage
  (JNIEnv *env, jclass jclazz, jlong imageInfoHandler)
{
    ImageInfo* imageInfo;
    
    imageInfo = (ImageInfo*) imageInfoHandler;

    if(imageInfo == NULL)
    {
      return NULL;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image *image = PingImage(imageInfo, exception);
    if(image == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_pingImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)image;
}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    compositeImage
 * Signature: (JJIZJJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_compositeImage
  (JNIEnv *env, jclass jclazz, jlong handler, jlong srcImageHandler, jint compositeOp, jboolean clipToSelf, jlong x, jlong y)
{
    Image * image;
    image = (Image*)handler;
    Image * srcImage = (Image*) srcImageHandler;

    if(image == NULL || srcImage == NULL)
    {
        return JNI_FALSE;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    MagickBooleanType ret = CompositeImage(image, srcImage, compositeOp,clipToSelf, x, y, exception);

    if(!ret)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_compositeImage",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }
     DestroyExceptionInfo(exception);
     return JNI_TRUE;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    textureImage
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_textureImage
  (JNIEnv *env, jclass jclzaa, jlong handler, jlong srcImageHandler)
{
    Image * image;
    image = (Image*)handler;
    Image * srcImage = (Image*) srcImageHandler;

    if(image == NULL || srcImage == NULL)
    {
        return JNI_FALSE;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    MagickBooleanType ret =  TextureImage(image, srcImage,exception);
    if(!ret)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_textureImage",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }
    DestroyExceptionInfo(exception);
    return JNI_TRUE;
}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    rotateImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_rotateImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble degrees)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = RotateImage(image, degrees,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_rotateImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    scaleImage
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_scaleImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint columns, jint rows)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = ScaleImage(image,columns,rows,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_scaleImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getColumns
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_image_Image_getColumns
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return 0;
    }

    return image->columns;

}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getRows
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_image_Image_getRows
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return 0;
    }

    return image->rows;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getDelay
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_image_Image_getDelay
  (JNIEnv *env, jclass jclazz, jlong handler)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return 0;
    }

    return image->delay;
}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setColumns
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setColumns
  (JNIEnv *env, jclass jclazz, jlong handler, jint columns)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }

     image->columns = columns;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setRows
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setRows
 (JNIEnv *env, jclass jclazz, jlong handler, jint rows)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }

     image->rows = rows;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setDelay
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setDelay
 (JNIEnv *env, jclass jclazz, jlong handler, jint delay)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }

     image->delay = delay;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    thumbnailImage
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_thumbnailImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint columns, jint rows)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = ThumbnailImage(image,columns,rows,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_thumbnailImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return (jlong)newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBackgroundColor
 * Signature: (JDDD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBackgroundColor
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble r, jdouble g, jdouble b)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }
    
    image->background_color.red = r;
    image->background_color.green = g;
    image->background_color.blue = b;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBorderColor
 * Signature: (JDDD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBorderColor
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble r, jdouble g, jdouble b)
{ 
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }
    
    image->border_color.red = r;
    image->border_color.green = g;
    image->border_color.blue = b;

}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    annotateImage
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_jkqj_magick_image_Image_annotateImage
  (JNIEnv *env, jclass jclazz, jlong handler, jlong drawHandler)
{

    Image * image;
    image = (Image*)handler;
    DrawInfo * drawInfo = (DrawInfo*)drawHandler;

    if(image == NULL || drawInfo == NULL)
    {
        return JNI_FALSE;
    }

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    MagickBooleanType ret  = AnnotateImage(image,drawInfo,exception);
    if(ret == MagickFalse)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_annotateImage",exception);
        DestroyExceptionInfo(exception);
        return JNI_FALSE;
    }
    DestroyExceptionInfo(exception);
    
    return JNI_TRUE;
}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBackgroundColorString
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBackgroundColorString
  (JNIEnv *env, jclass jclazz, jlong handler, jstring colorStr)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }
    char color[128];
    acceptJString(env, colorStr, color, 127);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    if(!QueryColorCompliance(color,AllCompliance,&(image->background_color),exception))
    {
        logException(env,"Java_com_jkqj_magick_image_Image_setBackgroundColorString",exception);
        DestroyExceptionInfo(exception);
        return;
    }    
    DestroyExceptionInfo(exception);
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setBorderColorString
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setBorderColorString
  (JNIEnv *env, jclass jclazz, jlong handler, jstring colorStr)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }
    char color[128];
    acceptJString(env, colorStr, color, 127);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    if(!QueryColorCompliance(color,AllCompliance,&(image->border_color),exception))
    {
        logException(env,"Java_com_jkqj_magick_image_Image_setBorderColorString",exception);
        DestroyExceptionInfo(exception);
        return;
    }    
    DestroyExceptionInfo(exception);
}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    drawImage
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_drawImage
  (JNIEnv *env, jclass jclazz, jlong handler, jlong drawHandler)
{
    Image * image;
    image = (Image*)handler;
    DrawInfo * drawInfo = (DrawInfo*)drawHandler;

    if(image == NULL || drawInfo == NULL)
    {
        return;
    }

#ifdef _USING_TRACE_MODE_
    logInfo(env,"Java_com_jkqj_magick_image_Image_drawImage.primitive", drawInfo->primitive);
#endif
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    MagickBooleanType ret =  DrawImage(image,drawInfo,exception);
    if(ret == MagickFalse)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_drawImage",exception);
        DestroyExceptionInfo(exception);
        return;
    }    
    DestroyExceptionInfo(exception);
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setMagick
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setMagick
  (JNIEnv *env, jclass jclazz, jlong handler, jstring magick)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }

    acceptJString(env, magick, image->magick, MagickPathExtent - 1);


}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    setFileName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_image_Image_setFileName
  (JNIEnv *env, jclass jclazz, jlong handler, jstring fileName)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return;
    }

    acceptJString(env, fileName, image->filename, MagickPathExtent - 1);

}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    getTypeMetrics
 * Signature: (JJ)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_jkqj_magick_image_Image_getTypeMetrics
  (JNIEnv *env, jclass jclazz, jlong handler,  jlong drawInfoHandler)
{
    Image * image = (Image*) handler;
    DrawInfo * drawInfo = (DrawInfo*) drawInfoHandler;
    if(image == NULL || drawInfo == NULL)
    {
        return NULL;
    }

    TypeMetric metric;
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    MagickBooleanType ret =  GetTypeMetrics(image,drawInfo,&metric,exception);
    if(!ret){
        logException(env,"Java_com_jkqj_magick_image_Image_getTypeMetrics",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);

    jdoubleArray array =  (*env)->NewDoubleArray(env,4);

    (*env)->SetDoubleArrayRegion(env,array, 0,1,&(metric.ascent));
    (*env)->SetDoubleArrayRegion(env,array, 1,1,&(metric.descent));
    (*env)->SetDoubleArrayRegion(env,array, 2,1,&(metric.width));
    (*env)->SetDoubleArrayRegion(env,array, 3,1,&(metric.height));
    return array;
}


/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    shearImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_shearImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble x, jdouble y)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = ShearImage(image,x,y,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_shearImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    integralRotateImage
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_integralRotateImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint rotations)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = IntegralRotateImage(image,rotations,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_integralRotateImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    shearRotateImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_shearRotateImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble degrees)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = ShearRotateImage(image,degrees,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_shearRotateImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    deskewImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_deskewImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble threshold)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = DeskewImage(image,threshold,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_deskewImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    adaptiveResizeImage
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_adaptiveResizeImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint columns, jint rows)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = AdaptiveResizeImage(image,columns, rows,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_adaptiveResizeImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    autoOrientImage
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_autoOrientImage
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
        logException(env,"Java_com_jkqj_magick_image_Image_autoOrientImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    blurImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_blurImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = BlurImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_blurImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    adaptiveBlurImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_adaptiveBlurImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = AdaptiveBlurImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_adaptiveBlurImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    adaptiveSharpenImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_adaptiveSharpenImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = AdaptiveSharpenImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_adaptiveSharpenImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}
/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    embossImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_embossImage
   (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = EmbossImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_embossImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}
/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    gaussianBlurImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_gaussianBlurImage
   (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = GaussianBlurImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_gaussianBlurImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    kuwaharaImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_kuwaharaImage
   (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = KuwaharaImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_kuwaharaImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    sharpenImage
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_sharpenImage
   (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius, jdouble sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = SharpenImage(image,radius,sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_sharpenImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    spreadImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_spreadImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint method, jdouble radius)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = SpreadImage(image,method,radius,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_spreadImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    bilateralBlurImage
 * Signature: (JIIDD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_bilateralBlurImage
  (JNIEnv *env, jclass jclazz, jlong handler, jint w, jint h, jdouble intensity_sigma, jdouble spatial_sigma)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = BilateralBlurImage(image,w,h,intensity_sigma,spatial_sigma,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_bilateralBlurImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    despeckleImage
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_despeckleImage
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
    Image * newImage = DespeckleImage(image,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_despeckleImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}

/*
 * Class:     com_jkqj_magick_image_Image
 * Method:    edgeImage
 * Signature: (JD)J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_image_Image_edgeImage
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble radius)
{
    Image * image;
    image = (Image*)handler;

    if(image == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * newImage = EdgeImage(image,radius,exception);
    if(newImage == NULL)
    {
        logException(env,"Java_com_jkqj_magick_image_Image_edgeImage",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    return newImage;
}