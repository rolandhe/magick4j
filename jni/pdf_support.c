//
// Created by hexiufeng on 2022/5/19.
//
#include "headers/pdf_support.h"

#define PNG_EXT ".png"
#define DEFAULT_DENSITY "300"
#define MAX_NUM_WIDTH  21

MagickBooleanType is_png(const char *out_file);


Image *read_src_file(JNIEnv* env,const char *in_file, const char *density);

void remove_icc(JNIEnv *env,Image *src_img);

Image *read_multi_images(JNIEnv* env,const char *file_name_patter, int size, ImageInfo *image_info);

void remove_temp_files(JNIEnv *env,const char *file_name_patter, int size);



MagickBooleanType convert_to_png(JNIEnv* env,const char *in_file, const char *out_file, const char *density, int remove_temp) {
    if (!is_png(out_file)) {
        logInfo(env,"convert_to_png.out_file error", out_file);
        return MagickFalse;
    }
    Image *src_img = read_src_file(env,in_file, density);
    if (!src_img) {
        return MagickFalse;
    }

    remove_icc(env,src_img);

    int size = GetImageListLength(src_img);

    ImageInfo *image_info = CloneImageInfo(NULL);

    if (!image_info) {
        DestroyImageList(src_img);
        return MagickFalse;
    }

    image_info->colorspace = sRGBColorspace;
    image_info->type = TrueColorType;

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();

    MagickBooleanType ret = WriteImages(image_info, src_img, out_file, exception);
    if (!ret) {
        logException(env,"convert_to_png.WriteImages", exception);
        DestroyImageInfo(image_info);
        DestroyExceptionInfo(exception);
        DestroyImageList(src_img);
        return MagickFalse;
    }

    if (size == 1) {
        DestroyImageInfo(image_info);
        DestroyExceptionInfo(exception);
        DestroyImageList(src_img);
        return MagickTrue;
    }

    Image *multi_images = read_multi_images(env,out_file, size, image_info);
    if (!multi_images) {
        DestroyImageInfo(image_info);
        DestroyExceptionInfo(exception);
        DestroyImageList(src_img);
        remove_temp_files(env,out_file, size);
        return MagickTrue;
    }

    Image *composite_image = AppendImages(multi_images, MagickTrue, exception);
    CopyMagickString(composite_image->filename, out_file, strlen(out_file) + 1);
    ret = WriteImage(image_info, composite_image, exception);

    if (!ret) {
        logException(env,"convert_to_png.WriteImage", exception);
    }

    DestroyImage(composite_image);
    DestroyImageList(multi_images);
    DestroyExceptionInfo(exception);
    DestroyImageInfo(image_info);
    DestroyImageList(src_img);
    if (remove_temp) {
        remove_temp_files(env,out_file, size);
    }
    return ret;
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

void remove_icc(JNIEnv * env,Image *src_img) {
    StringInfo *removed_profile = RemoveImageProfile(src_img, "icc");
    if (removed_profile) {
        logInfo(env,"rm icc", "icc");
    } else {
        logInfo(env,"rm icc", "current img has not icc");
    }
}

Image *read_src_file(JNIEnv * env,const char *in_file, const char *density) {
    ImageInfo *image_info = CloneImageInfo(NULL);
    if (image_info == NULL) {
        return NULL;
    }
    CopyMagickString(image_info->filename, in_file, strlen(in_file) + 1);
    image_info->density = AcquireString(density == NULL ? DEFAULT_DENSITY : density);
    image_info->colorspace = sRGBColorspace;
    image_info->type = TrueColorType;

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    Image *image = ReadImage(image_info, exception);
    if (!image) {
        logException(env,"gif_support.scaleCore.readGifFile", exception);
        DestroyExceptionInfo(exception);
        DestroyImageInfo(image_info);
        return NULL;
    }

    DestroyExceptionInfo(exception);
    DestroyImageInfo(image_info);
    return GetFirstImageInList(image);
}

Image *read_multi_images(JNIEnv* env,const char *file_name_patter, int size, ImageInfo *image_info) {
    size_t prefix_len = strlen(file_name_patter) - strlen(PNG_EXT);
    char * prefix_name = AcquireMagickMemory(prefix_len + 1);
    CopyMagickString(prefix_name,file_name_patter,prefix_len + 1);


    Image *image_list = NewImageList();

    ExceptionInfo *exception = AcquireExceptionInfo();

    for (int i = 0; i < size; i++) {
        sprintf(image_info->filename, "%s-%d%s", prefix_name, i, PNG_EXT);
        Image *read_img = ReadImage(image_info, exception);
        if (!read_img) {
            logException(env,"read_multi_images", exception);
            DestroyExceptionInfo(exception);
            DestroyImageList(image_list);
            RelinquishMagickMemory(prefix_name);
            return NULL;
        }
        AppendImageToList(&image_list, read_img);
    }

    DestroyExceptionInfo(exception);
    RelinquishMagickMemory(prefix_name);
    return image_list;
}

void remove_temp_files(JNIEnv * env,const char *file_name_patter, int size) {
    size_t cap_size = strlen(file_name_patter) + MAX_NUM_WIDTH;
    char * file_name = AcquireMagickMemory(cap_size);
    int prefix_len = strlen(file_name_patter) - strlen(PNG_EXT);

    for (int i = 0; i < size; i++) {
        CopyMagickString(file_name,file_name_patter,prefix_len + 1);
        sprintf(file_name, "%s-%d%s", file_name, i, PNG_EXT);
        MagickBooleanType ret = RelinquishUniqueFileResource(file_name);
        if (!ret) {
            logInfo(env,"remove_temp_files", file_name);
        }
    }
    RelinquishMagickMemory(file_name);
}