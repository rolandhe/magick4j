#include "headers/gif_support.h"



MagickBooleanType scaleCore(JNIEnv * env, const char * srcFileName, const char * toFileName, size_t rows, size_t columns, ImageResizeOp op)
{
    Image * srcImage = readGifFile(env,srcFileName);
    if(srcImage == NULL)
    {
        return MagickFalse;
    }

    Image * coalImage = coalesceImages(env,srcImage);
    DestroyImageList(srcImage);
    if(coalImage == NULL)
    {
        return MagickFalse;
    }

    Image * gifImage = scaleGif(env,coalImage,rows,columns,op);
    DestroyImageList(coalImage);
    if(gifImage == NULL)
    {
        return MagickFalse;
    }

   MagickBooleanType ret =  store2File(env,gifImage,toFileName);
   DestroyImageList(gifImage);
   return ret;
}

Image * readGifFile(JNIEnv * env,const char * filename)
{
    ImageInfo * imageInfo = AcquireMagickMemory(sizeof(ImageInfo));
    if(imageInfo == NULL){
        return NULL;
    }
    GetImageInfo(imageInfo);
    CopyMagickString(imageInfo->filename, filename,strlen(filename) + 1);
    
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image * image = ReadImage(imageInfo, exception);
    if(image == NULL){
        logException(env,"gif_support.scaleCore.readGifFile",exception);
        DestroyExceptionInfo(exception);
        DestroyImageInfo(imageInfo);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    DestroyImageInfo(imageInfo);
    // RelinquishUniqueFileResource(filename);
    return GetFirstImageInList(image);
}

Image* coalesceImages(JNIEnv * env,const Image * srcImage)
{
    if(srcImage == NULL)
    {
        return NULL;
    }
    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image* image = CoalesceImages(srcImage , exception);
    if(image == NULL)
    {
        logException(env,"gif_support.scaleCore.coalesceImages",exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    
    return image;
}

Image * scaleGif(JNIEnv * env,const Image* srcImage, const size_t rows, const size_t columns, ImageResizeOp op)
{
    Image* scaleGifImage;
    // Image * p;
    const Image * first =  GetFirstImageInList(srcImage);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image* scaleImage = op(first, columns,rows,exception);
    if(scaleImage == NULL)
    {
        logException(env,"gif_support.scaleCore.scaleGif",exception);
        DestroyExceptionInfo(exception);

        return NULL;
    }

    DestroyExceptionInfo(exception);
    
    scaleGifImage=NewImageList();

    AppendImageToList(&scaleGifImage,scaleImage);



    Image * next  = first->next;
    while(next != NULL)
    {
        exception = AcquireExceptionInfo();
        scaleImage = op(next,columns,rows,exception);
        if(scaleImage == NULL)
        {
            logException(env,"gif_support.scaleCore.scaleGif.loop",exception);
            DestroyExceptionInfo(exception);
            DestroyImageList(scaleGifImage);
            return NULL;
        }
        DestroyExceptionInfo(exception);
        AppendImageToList(&scaleGifImage,scaleImage);

        next  = next->next;
    }

    return scaleGifImage;
}


MagickBooleanType store2File(JNIEnv * env,Image * gifImage,const char * toFile)
{
    MagickBooleanType retVal;

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    retVal = StripImage(gifImage, exception);
    char messageBuff[MaxTextExtent];
    if(retVal == MagickFalse)
    {
        logException(env,"gif_support.scaleCore.store2File.strip",exception);
        sprintf(messageBuff,"Occur error when StripImage in store gif,but continue, toFile: %s.", toFile);
        logInfo(env,"gif_support.scaleCore.store2File.strip", messageBuff);
    }
    DestroyExceptionInfo(exception);

    ImageInfo * imageInfo = AcquireMagickMemory(sizeof(ImageInfo));
    if(imageInfo == NULL){
        return MagickFalse;
    }
    GetImageInfo(imageInfo);

    CopyMagickString(gifImage->filename, toFile,strlen(toFile) + 1);
    
    exception = AcquireExceptionInfo();
    retVal = WriteImage(imageInfo,gifImage,exception);

    if(retVal == MagickFalse)
    {
        logException(env,"gif_support.scaleCore.store2File.write",exception);
        sprintf(messageBuff,"Occur error when StripImage in store gif,but continue, toFile: %s.", toFile);
        logInfo(env,"gif_support.scaleCore.store2File.write", messageBuff);
    }
    DestroyExceptionInfo(exception);
    DestroyImageInfo(imageInfo);
    return retVal;

}





