//
// Created by hexiufeng on 2022/5/19.
//
#include "headers/pdf_support.h"

#define PNG_EXT ".png"
#define DEFAULT_DENSITY "300"
#define CONVERT_ERROR  -1



MagickBooleanType is_png(const char *out_file);

void setup_image_info(const char *density, ImageInfo *image_info);

MagickBooleanType  apple_image_info_to_image(JNIEnv *env,Image * src_img, ImageInfo * image_info, ExceptionInfo * exception);


size_t convert_to_png(JNIEnv* env,const char *in_file, const char *out_file, const char *density, int out_single) {
    if (!is_png(out_file)) {
        logInfo(env,"convert_to_png.out_file error", out_file);
        return CONVERT_ERROR;
    }

    
    ImageInfo *image_info = CloneImageInfo(NULL);
    if (!image_info) {
        logInfo(env,"convert_to_png.create image_info error", "call CloneImageInfo error");
        return CONVERT_ERROR;
    }
    setup_image_info(density, image_info);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();

    Watcher watcher;
#ifdef _USING_TRACE_MODE_
    start_watcher(&watcher);
#endif
    Image *src_img = ReadImages(image_info,in_file,exception);

    if (!src_img) {
        logException(env,"convert_to_png.ReadImages", exception);
        DestroyExceptionInfo(exception);
        DestroyImageInfo(image_info);
        return CONVERT_ERROR;
    }
#ifdef _USING_TRACE_MODE_
    end_watcher(&watcher);
    logInfoWithCost(env,"convert_to_png.ReadImages",NULL,&watcher);
#endif
    MagickBooleanType ret = apple_image_info_to_image(env,src_img, image_info, exception);
    if(!ret){
        DestroyImageList(src_img);
        DestroyExceptionInfo(exception);
        DestroyImageInfo(image_info);
        return CONVERT_ERROR;
    }

    size_t size = GetImageListLength(src_img);
    if (size == 1 || !out_single) {
#ifdef _USING_TRACE_MODE_
        start_watcher(&watcher);
#endif
        ret = WriteImages(image_info, src_img, out_file, exception);
#ifdef _USING_TRACE_MODE_
        end_watcher(&watcher);
        logInfoWithCost(env,"convert_to_png.WriteImages","write one page or single page",&watcher);
#endif      
        
        DestroyImageList(src_img);
        DestroyExceptionInfo(exception);
        DestroyImageInfo(image_info);
        if (!ret) {
            logException(env,"convert_to_png.WriteImages", exception);
            return CONVERT_ERROR;
        }
        return size;
    }
#ifdef _USING_TRACE_MODE_
    start_watcher(&watcher);
#endif
    Image *composite_image = AppendImages(src_img, MagickTrue, exception);
#ifdef _USING_TRACE_MODE_
    end_watcher(&watcher);
    logInfoWithCost(env,"convert_to_png.AppendImages",NULL, &watcher);
#endif
    CopyMagickString(composite_image->filename, out_file, strlen(out_file) + 1);

#ifdef _USING_TRACE_MODE_
    start_watcher(&watcher);
#endif   
    ret = WriteImage(image_info, composite_image, exception);
#ifdef _USING_TRACE_MODE_
    end_watcher(&watcher);
    logInfoWithCost(env,"convert_to_png.WriteImage","to single file", &watcher);
#endif

   

    DestroyImage(composite_image);
    DestroyExceptionInfo(exception);
    DestroyImageInfo(image_info);
    DestroyImageList(src_img);
     if (!ret) {
        logException(env,"convert_to_png.WriteImage", exception);
        return CONVERT_ERROR;
    }
    return 1;
}

MagickBooleanType is_png(const char *out_file) {
    size_t len = strlen(out_file);
    size_t ext_len = strlen(PNG_EXT);
    if (len <= ext_len) {
        return MagickFalse;
    }

    size_t pos = len - ext_len;

    char *p = out_file + pos;

    if (strcmp(p, PNG_EXT) == 0) {
        return MagickTrue;
    }

    return MagickFalse;
}

void setup_image_info(const char *density, ImageInfo *image_info) {
    image_info->colorspace = sRGBColorspace;
    SetImageOption(image_info,"colorspace","srgb");
    image_info->type = TrueColorType;
    SetImageOption(image_info,"type","truecolor");

    image_info->density = AcquireString(density == NULL ? DEFAULT_DENSITY : density);
    SetImageOption(image_info,"density",image_info->density);
}

MagickBooleanType  apple_image_info_to_image(JNIEnv *env,Image * src_img, ImageInfo * image_info, ExceptionInfo * exception){
    Image * p = GetFirstImageInList(src_img);
    while (p){
        MagickBooleanType ret=SyncImageSettings(image_info,p,exception);
        if(!ret){
            logException(env,"apple_image_info_to_image.SyncImageSettings", exception);
            return ret;
        }
        ret = TransformImageColorspace(p, image_info->colorspace,exception);
        if(!ret){
            logException(env,"apple_image_info_to_image.SyncImageSettings", exception);
            return  ret;
        }
        p->type = UndefinedType;
        ret = SetImageType(p,image_info->type,exception);
        if(!ret){
            logException(env,"apple_image_info_to_image.SetImageType", exception);
            return ret;
        }
        p = GetNextImageInList(p);
    }
    return MagickTrue;
}