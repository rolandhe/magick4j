#ifndef __W_C__
#define __W_C__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <MagickCore/MagickCore.h>
#include "common.h"


typedef Image* (* ImageResizeOp)(Image*,size_t,size_t,ExceptionInfo*);

Image * readGifFile(JNIEnv * env,const char * filename);

Image* coalesceImages(JNIEnv * env,const Image * srcImage);

Image * scaleGif(JNIEnv * env,const Image* srcImage, const size_t rows, const size_t columns, ImageResizeOp op);

MagickBooleanType store2File(JNIEnv * env,Image * gifImage,const char * toFile);

MagickBooleanType scaleCore(JNIEnv * env,const char * srcFileName, const char * toFileName, size_t rows, size_t columns,ImageResizeOp op);


#endif
