#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <MagickCore/MagickCore.h>

#include <jni.h>

#define DEFAULT_MAX_LEN 2048

#ifndef _COMMON_H_
#define _COMMON_H_

void logInfo(JNIEnv * env,const char * src, const char * message);
void logException(JNIEnv * env, const char * src,ExceptionInfo *exception);

void acceptJString(JNIEnv * env, jstring value, char * buff, size_t maxLen);

jstring toJstring(JNIEnv * env, const char * buff);

char * allocAndacceptJString(JNIEnv * env, jstring value);

// char * newCharBuff(size_t len);
   
#endif