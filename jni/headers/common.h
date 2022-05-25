#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <MagickCore/MagickCore.h>

#include <jni.h>

#define DEFAULT_MAX_LEN 2048

#ifndef _COMMON_H_
#define _COMMON_H_

typedef struct _Watcher{
    struct timeval start;
    struct timeval end;
} Watcher;

void start_watcher(Watcher * watcher);
void end_watcher(Watcher * watcher);
long long get_cost_time(Watcher * watcher);

void logInfo(JNIEnv * env,const char * src, const char * message);

void logInfoWithCost(JNIEnv * env,const char *src, const char *message,Watcher * watcher);


void logException(JNIEnv * env, const char * src,ExceptionInfo *exception);

void acceptJString(JNIEnv * env, jstring value, char * buff);

jstring toJstring(JNIEnv * env, const char * buff);

char * allocAndacceptJString(JNIEnv * env, jstring value);
   
#endif