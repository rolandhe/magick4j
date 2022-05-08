package com.jkqj.magick.image;

public interface CompressType {
    int UndefinedCompression = 0;
    int B44ACompression = 1;
    int B44Compression = 2;
    int BZipCompression = 3;
    int DXT1Compression = 4;
    int DXT3Compression = 5;
    int DXT5Compression = 6;
    int FaxCompression = 7;
    int Group4Compression = 8;
    int JBIG1Compression = 9;        /* ISO/IEC std 11544 / ITU-T rec T.82 */
    int JBIG2Compression = 10;        /* ISO/IEC std 14492 / ITU-T rec T.88 */
    int JPEG2000Compression = 11;     /* ISO/IEC std 15444-1 */
    int JPEGCompression = 12;
    int LosslessJPEGCompression = 13;
    int LZMACompression = 14;         /* Lempel-Ziv-Markov chain algorithm */
    int LZWCompression = 15;
    int NoCompression = 16;
    int PizCompression = 17;
    int Pxr24Compression = 18;
    int RLECompression = 19;
    int ZipCompression = 20;
    int ZipSCompression = 21;
    int ZstdCompression = 22;
    int WebPCompression = 23;
    int DWAACompression = 24;
    int DWABCompression = 25;
    int BC7Compression = 26;
}
