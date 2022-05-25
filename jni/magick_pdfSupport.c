#include "headers/com_jkqj_magick_support_PdfSupport.h"
#include "headers/pdf_support.h"

/*
 * Class:     com_jkqj_magick_support_PdfSupport
 * Method:    convertPdfToPng
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)Z
 */
JNIEXPORT jint JNICALL Java_com_jkqj_magick_support_PdfSupport_convertPdfToPng
  (JNIEnv *env, jclass jclazz, jstring pdfFile, jstring pngFile, jstring jsDensity, jboolean outSingleFile)
  {
        const char * in_file = allocAndAcceptJString(env , pdfFile);
        const char * out_file = allocAndAcceptJString(env , pngFile);
        char * density = NULL;
        if(jsDensity){
            density = allocAndAcceptJString(env, jsDensity);
        }

        size_t ret = convert_to_png(env,in_file,out_file,density,outSingleFile);

        DestroyString(in_file);
        DestroyString(out_file);
        if(density){
            DestroyString(density);
        }
        return ret;
  }