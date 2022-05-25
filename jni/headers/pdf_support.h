//
// Created by hexiufeng on 2022/5/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <MagickCore/MagickCore.h>

#include "common.h"

#ifndef PDF2IMG_PDF_SUPPORT_H
#define PDF2IMG_PDF_SUPPORT_H

size_t convert_to_png(JNIEnv *env,const char * in_file,const char * out_file,const char* density,int out_single);

#endif //PDF2IMG_PDF_SUPPORT_H
