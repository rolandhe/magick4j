package com.jkqj.magick.image;

public interface PixelInterpolateMethod {
    int UndefinedInterpolatePixel = 0;
    int AverageInterpolatePixel = 1;    /* Average 4 nearest neighbours */
    int Average9InterpolatePixel = 2;  /* Average 9 nearest neighbours */
    int Average16InterpolatePixel = 3;  /* Average 16 nearest neighbours */
    int BackgroundInterpolatePixel = 4; /* Just return background color */
    int BilinearInterpolatePixel = 5;  /* Triangular filter interpolation */
    int BlendInterpolatePixel = 6;     /* blend of nearest 1, 2 or 4 pixels */
    int CatromInterpolatePixel = 7;    /* Catmull-Rom interpolation */
    int IntegerInterpolatePixel = 8;    /* Integer (floor) interpolation */
    int MeshInterpolatePixel = 9;    /* Triangular Mesh interpolation */
    int NearestInterpolatePixel = 10;    /* Nearest Neighbour Only */
    int SplineInterpolatePixel = 11;    /* Cubic Spline (blurred) interpolation */
}
