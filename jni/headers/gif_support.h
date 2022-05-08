#ifndef __W_C__
#define __W_C__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <MagickCore/MagickCore.h>
#include "common.h"


Image * readGifFile(const char * filename);


Image* coalesceImages(const Image * srcImage);

Image * scaleGif(const Image* srcImage, const size_t rows, const size_t columns);

MagickBooleanType store2File(Image * gifImage,const char * toFile);

MagickBooleanType scaleCore(const char * srcFileName, const char * toFileName, size_t rows, size_t columns);


#endif
