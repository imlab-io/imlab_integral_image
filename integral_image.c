#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "imcore.h"
#include "cvcore.h"
#include "iocore.h"
#include "alcore.h"

void compute_integral_image(matrix_t *I, matrix_t *T)
{
    uint32_t x, y, c;

    // handle the x=0,y=0 case
    for(c = 0; c < channels(I); c++)
    {
        atf(T, 0, 0, c) = atui8(I, 0, 0, c);
    }
    
    /* compute the table completely */
    for (y = 1; y < height(I); y++)
    {
        // handle the zero case
        for (c = 0; c < channels(I); c++)
        {
            atf(T, y, 0, c) = atui8(I, y, 0, c);
        }
        
        // do the calculation for x > 0
        for (x = 1; x < width(I); x++)
        {
            for (c = 0; c < channels(I); c++)
            {
                atf(T, y, x, c) = atui8(I, y, x, c) + atf(T, y, x - 1, c) + atf(T, y - 1, x, c) - atf(T, y - 1, x - 1, c);
            }
        }
    }
}

float get_integral(matrix_t *integral, int x0, int y0, int x1, int y1, int c)
{
    float summation = atf(integral, y1, x1, c);

    // extract T(y1,x0-1)
    summation -= (x0 > 0) ? atf(integral, y1, x0 - 1, c) : 0;
    // extract T(y0-1,x1)
    summation -= (y0 > 0) ? atf(integral, y0 - 1, x1, c) : 0;
    // add T(y0-1,x0-1)
    summation += (x0 > 0 && y0 > 0) ? atf(integral, y0 - 1, x0 - 1, c) : 0;

    // return the summation
    return summation;
}

int main(int argc, char *argv[]) 
{
    int k,m,n;

    // maximum half filter size
    int hfilterSize = 30;

    // read the source image and its mask
    matrix_t *img = imread("../data//filtered.bmp");
    matrix_t *mask = imread("../data//ev_mask.bmp");

    // allocate space for filtered and integral images
    matrix_t *filtered = matrix_create(uint8_t, rows(img), cols(img), 3);
    matrix_t *integral = matrix_create(float, rows(img), cols(img), 3);

    // compute the integral image
    compute_integral_image(img, integral);

    // run over the image and compute the box blur
    for (n = hfilterSize; n < height(img) - hfilterSize; n++)
    {
        for (m = hfilterSize; m < width(img) - hfilterSize; m++)
        {
            // estimate the filter size wrt mask value
            int filterSize = map(atui8(mask, n, m, 0), 0,255, 1,hfilterSize);

            // pre calculate the normalizer for the box
            float areaInv = 1.0f / ((2 * filterSize + 1) * (2 * filterSize + 1));

            // filter the channels seperately
            for (k = 0; k < channels(img); k++)
            {
                atui8(filtered, n, m, k) = clamp(areaInv * get_integral(integral, m - filterSize, n - filterSize, m + filterSize, n + filterSize, k), 0, 255);
            }
        }
    }

    // write the filtered image
    imwrite(filtered, "filtered.bmp");

    return 0;
}