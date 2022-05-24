#include "headers/common.h"


void logInfo(JNIEnv * env,const char * src, const char * message)
{
    jclass logClazz = (*env)->FindClass(env,"com/jkqj/magick/log/MagickLog");
    if(logClazz == NULL)
    {
        return;
    }

    jmethodID methodId =  (*env)->GetStaticMethodID(env,logClazz,"logMagickInfo","(Ljava/lang/String;Ljava/lang/String;)V");
    if(methodId == NULL)
    {
        (*env)->DeleteLocalRef(env, logClazz);
        return;
    }
    jstring msg = message == NULL? NULL : (*env)->NewStringUTF(env, message);
    jstring from = (*env)->NewStringUTF(env, src);
    (*env)->CallStaticVoidMethod(env, logClazz,methodId,msg,from);
    (*env)->DeleteLocalRef(env, logClazz);
    if(msg != NULL)
    {
        (*env)->DeleteLocalRef(env, msg);
    }
    
    (*env)->DeleteLocalRef(env, from);
}

void logException(JNIEnv * env, const char * src,ExceptionInfo *exception)
{
    jclass logClazz = (*env)->FindClass(env,"com/jkqj/magick/log/MagickLog");
    if(logClazz == NULL)
    {
        return;
    }
    jmethodID methodId =  (*env)->GetStaticMethodID(env,logClazz,"logMagickException","(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    if(methodId == NULL)
    {
        (*env)->DeleteLocalRef(env, logClazz);
        return;
    }
    jstring reason = exception->reason == NULL? NULL : (*env)->NewStringUTF(env, exception->reason);
    jstring desc = exception->description == NULL? NULL : (*env)->NewStringUTF(env, exception->description);
    jstring from = (*env)->NewStringUTF(env, src);
    (*env)->CallStaticVoidMethod(env, logClazz,methodId,exception->error_number, reason,desc,from);
    (*env)->DeleteLocalRef(env, logClazz);
    if(reason != NULL)
    {
        (*env)->DeleteLocalRef(env, reason);
    }
    if(desc != NULL)
    {
        (*env)->DeleteLocalRef(env, desc);
    }
    (*env)->DeleteLocalRef(env, from);
}

void acceptJString(JNIEnv * env, jstring value, char * buff)
{
     const char * cstr =  (*env)->GetStringUTFChars(env,value,NULL);
     CopyMagickString(buff,cstr,strlen(cstr) + 1);
     (*env)->ReleaseStringUTFChars(env,value,cstr);
} 

jstring toJstring(JNIEnv * env, const char * buff)
 {
     return (*env)->NewStringUTF(env, buff);
 }

 char * allocAndacceptJString(JNIEnv * env, jstring value)
 {
     const char * cstr =  (*env)->GetStringUTFChars(env,value,NULL);
     char * buff = AcquireString(cstr);
     (*env)->ReleaseStringUTFChars(env,value,cstr);
     return buff;
 }
