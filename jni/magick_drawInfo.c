#include "headers/com_jkqj_magick_draw_DrawInfo.h"

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_jkqj_magick_draw_DrawInfo_init
  (JNIEnv *env, jclass jclazz)
{
   DrawInfo * drawInfo =  AcquireDrawInfo();
   return (jlong)drawInfo;
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    destroy
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_destroy
  (JNIEnv *env, jclass jclazz, jlong handler)
{
     DrawInfo * drawInfo = (DrawInfo*) handler;
     if(drawInfo == NULL)
     {
        return;
     }

     DestroyDrawInfo(drawInfo);
}



/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setFont
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setFont
  (JNIEnv *env, jclass jclazz, jlong handler, jstring fontName)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->font = allocAndacceptJString(env, fontName);
}


/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setText
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setText
  (JNIEnv *env, jclass jclazz, jlong handler, jstring text)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->text = allocAndacceptJString(env, text);
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setMetrics
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setMetrics
  (JNIEnv *env, jclass jclazz, jlong handler, jstring metrics)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->metrics = allocAndacceptJString(env, metrics);
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setFamily
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setFamily
  (JNIEnv *env, jclass jclazz, jlong handler, jstring family)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->family = allocAndacceptJString(env, family);
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setPointSize
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setPointSize
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble pointSize)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->pointsize = pointSize;
}
/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    annotation
 * Signature: (JDDLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_annotation
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble x, jdouble y, jstring text)
{

    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }
    char* escapedText;
    char * localText =  allocAndacceptJString(env, text);

    escapedText = EscapeString((const char *) localText,'\'');

    RelinquishMagickMemory(localText);
    if(escapedText == NULL)
    {
        return;
    }

    char * maxText = newCharBuff(20 * 4096);

    sprintf(maxText,"text %.20g %.20g '%s'\n", x,y, escapedText);
    DestroyString(escapedText);

    if(drawInfo->primitive != NULL)
    {
        RelinquishMagickMemory(drawInfo->primitive);
    }
    
    drawInfo->primitive = newCharBuff(strlen(maxText));
    strcpy(drawInfo->primitive, maxText);
    RelinquishMagickMemory(maxText);
}


/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setFill
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setFill
  (JNIEnv *env, jclass jclazz, jlong handler, jstring colorStr)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    char color[128];
    acceptJString(env, colorStr, color, 127);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();

    if(!QueryColorCompliance(color,AllCompliance,&(drawInfo->fill),exception))
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return;
    }    
    DestroyExceptionInfo(exception);
   
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setStroke
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setStroke
  (JNIEnv *env, jclass jclazz, jlong handler, jstring colorStr)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    char color[128];
    acceptJString(env, colorStr, color, 127);

    ExceptionInfo *exception;
    exception = AcquireExceptionInfo();
    if(!QueryColorCompliance(color,AllCompliance,&(drawInfo->stroke),exception))
    {
        logException(exception);
        DestroyExceptionInfo(exception);
        return;
    }    
    DestroyExceptionInfo(exception);
}


/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setPrimitive
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setPrimitive
  (JNIEnv *env, jclass jclazz, jlong handler, jstring primitive)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->primitive = allocAndacceptJString(env, primitive);

}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setGravity
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setGravity
  (JNIEnv *env, jclass jclazz, jlong handler, jint gravity)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }

    drawInfo->gravity = gravity;

}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setAlign
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setAlign
  (JNIEnv *env, jclass jclazz, jlong handler, jint align)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }
    drawInfo->align = align;
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setViewBoxRectangle
 * Signature: (JJJII)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setViewBoxRectangle
  (JNIEnv *env, jclass jclazz, jlong handler, jlong x, jlong y, jint w, jint h)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }
    drawInfo->viewbox.x = x;
    drawInfo->viewbox.y = y;
    drawInfo->viewbox.width = w;
    drawInfo->viewbox.height = h;
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setStrokeWidth
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setStrokeWidth
  (JNIEnv *env, jclass jclazz, jlong handler, jdouble w)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }
    drawInfo->stroke_width = w;
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setGeometry
 * Signature: (JDD)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setGeometry
  (JNIEnv *env, jclass jclazz, jlong handler , jdouble x, jdouble y)
{
    DrawInfo * drawInfo = (DrawInfo*) handler;
    if(drawInfo == NULL)
    {
        return;
    }
    char geometry[MagickPathExtent];
    (void) FormatLocaleString(geometry,MagickPathExtent,"%+f%+f",x,y);
    (void) CloneString(&(drawInfo->geometry),geometry);
}

/*
 * Class:     com_jkqj_magick_draw_DrawInfo
 * Method:    setEncoding
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jkqj_magick_draw_DrawInfo_setEncoding
  (JNIEnv *env, jclass jclazz, jlong handler, jstring encoding)
{
      DrawInfo * drawInfo = (DrawInfo*) handler;
      if(drawInfo == NULL)
      {
          return;
      }
      const char * cstr =  (*env)->GetStringUTFChars(env,encoding,NULL);
     (void) CloneString(&(drawInfo->encoding),cstr);
     (*env)->ReleaseStringUTFChars(env,encoding,cstr);
}