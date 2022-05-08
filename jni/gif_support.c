#include "headers/gif_support.h"

 

MagickBooleanType scaleCore(const char * srcFileName, const char * toFileName, size_t rows, size_t columns)
{
    Image * srcImage = readGifFile(srcFileName);
    if(srcImage == NULL)
    {
        return MagickFalse;
    }

    Image * coalImage = coalesceImages(srcImage);
    DestroyImageList(srcImage);
    if(coalImage == NULL)
    {
        return MagickFalse;
    }

    Image * gifImage = scaleGif(coalImage,rows,columns);
    DestroyImageList(coalImage);
    if(gifImage == NULL)
    {
        return MagickFalse;
    }

   MagickBooleanType ret =  store2File(gifImage,toFileName);
   DestroyImageList(gifImage);
   return ret;
}

Image * readGifFile(const char * filename)
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
        logException(exception);
        DestroyExceptionInfo(exception);
        DestroyImageInfo(imageInfo);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    DestroyImageInfo(imageInfo);
    // RelinquishUniqueFileResource(filename);
    return GetFirstImageInList(image);
}

Image* coalesceImages(const Image * srcImage)
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
        logException(exception);
        DestroyExceptionInfo(exception);
        return NULL;
    }
    DestroyExceptionInfo(exception);
    
    return image;
}

Image * scaleGif(const Image* srcImage, const size_t rows, const size_t columns)
{
    Image* scaleGifImage;
    // Image * p;
    const Image * first =  GetFirstImageInList(srcImage);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image* scaleImage = ScaleImage(first, columns,rows,exception);
    if(scaleImage == NULL)
    {
        logException(exception);
        DestroyExceptionInfo(exception);

        return NULL;
    }

    DestroyExceptionInfo(exception);
    
    scaleGifImage=NewImageList();
//    fprintf(stdout,"%s \n.", "before add to iamge list");
    AppendImageToList(&scaleGifImage,scaleImage);



    Image * next  = first->next;
    while(next != NULL)
    {
        exception = AcquireExceptionInfo();
        scaleImage = ScaleImage(next,columns,rows,exception);
        if(scaleImage == NULL)
        {
            logException(exception);
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


MagickBooleanType store2File(Image * gifImage,const char * toFile)
{
    MagickBooleanType retVal;

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    retVal = StripImage(gifImage, exception);
    if(retVal == MagickFalse)
    {
        logException(exception);
        fprintf(stdout,"Occur error when StripImage in store gif,but continue, toFile: %s \n.", toFile);
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
        logException(exception);
        fprintf(stdout,"Occur error when StripImage in store gif,but continue, toFile: %s \n.", toFile);
    }
    DestroyExceptionInfo(exception);
    DestroyImageInfo(imageInfo);
    return retVal;

}





