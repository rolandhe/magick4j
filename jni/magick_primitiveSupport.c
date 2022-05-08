#include "headers/com_jkqj_magick_draw_PrimitiveSupport.h"


/*
 * Class:     com_jkqj_magick_draw_PrimitiveSupport
 * Method:    escapeString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_jkqj_magick_draw_PrimitiveSupport_escapeString
  (JNIEnv *env, jclass jclazz, jstring text)
{
    char* escapedText;
    const char * cstr =  (*env)->GetStringUTFChars(env,text,NULL);
    escapedText = EscapeString( cstr,'\'');
    (*env)->ReleaseStringUTFChars(env,text,cstr);

    if(escapedText == NULL)
    {
        return NULL;
    }

    jstring ret = toJstring(env,escapedText);

    DestroyString(escapedText);

    return ret;
}