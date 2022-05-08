#include "headers/common.h"


void logException(ExceptionInfo *exception)
{
    fprintf(stdout,"%s,reason is: %s\n",exception->description,exception->reason);
}

void acceptJString(JNIEnv * env, jstring value, char * buff, size_t maxLen)
{
     const char * cstr =  (*env)->GetStringUTFChars(env,value,NULL);
     strncpy(buff,cstr,maxLen);
     (*env)->ReleaseStringUTFChars(env,value,cstr);
} 

jstring toJstring(JNIEnv * env, const char * buff)
 {
     return (*env)->NewStringUTF(env, buff);
 }

 char * newCharBuff(size_t len)
 {
   return (char*)AcquireMagickMemory(len  + 1);
 }

 char * allocAndacceptJString(JNIEnv * env, jstring value)
 {
     const char * cstr =  (*env)->GetStringUTFChars(env,value,NULL);
     char* buff = newCharBuff(strlen(cstr));
     strcpy(buff,cstr);
     (*env)->ReleaseStringUTFChars(env,value,cstr);
     return buff;
 }
