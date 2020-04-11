// Copies a BMP file
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
   if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    float a = atof(argv[1]);
    printf("value of a: %f\n",a );
    int f=0;

    if((f>100 )||(f<0))
    {
        fprintf(stderr, "Usage: argv[1] is out of bound\n");
        return 1;
    }
    if (a > 0 && a < 1)
    {
        printf("if (a > 0 && a < 1) \n" );
        //float a = atof(argv[1]); // need to add one more for int for 1 - 100 input
        f = (int) (1.0/a);
        printf("value of f: %d\n",f );


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
   // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf; // int newbf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    printf("Line 63: fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);\n");

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    printf("Line 68: reached\n");

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    printf("Line 79: reached\n");

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("Line 83: reached\n");
    printf("bi.biWidth = %d\n", bi.biWidth); printf("f = %d\n", f);


    int newPadding = (4 - ((bi.biWidth/f) * sizeof(RGBTRIPLE)) % 4) % 4; // Not Sure - UPDATED AS PER NEW WIDTH PADDING

    printf("Line 86: reached\n");

    BITMAPFILEHEADER newBf;
    BITMAPINFOHEADER newBi;

    newBf = bf;
    newBi = bi;

    if (bi.biWidth % f != 0)
    {
        bi.biWidth = bi.biWidth - (bi.biWidth % f);
        newBi.biWidth = (bi.biWidth/f);

        bi.biHeight = bi.biHeight - (bi.biHeight % f);
        newBi.biHeight = (bi.biHeight/f);
    }
    else
    {
        newBi.biWidth = (bi.biWidth/f);
        newBi.biHeight = (bi.biHeight/f);
    }

    printf("newBi.biWidth = %d\n", newBi.biWidth);
    newBi.biSizeImage = ((sizeof(RGBTRIPLE) * newBi.biWidth) + newPadding) * abs(newBi.biHeight);
    newBf.bfSize = newBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&newBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE scanline[newBi.biWidth];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            if((j%f == 0) && (i%f == 0))
            {
                // write RGB triple to outfile
                scanline[j/f] = triple;
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        if((i%f == 0))
        {
            fwrite(scanline, sizeof(scanline), 1, outptr);

            // then add it back (to demonstrate how)
            for (int k = 0; k < newPadding; k++)
            {
                BYTE zero = 0x00;
                fwrite(&zero,1,1,outptr);
                //fputc(0x00, outptr);
            }
        }
    }
     // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
    }

    else if (a >= 1 && a < 100)
    {
        int n = (int) a;
        printf("if (a >= 1 || a < 100)\n");

             // remember filenames
        char *infile = argv[2];
        char *outfile = argv[3];

        // open input file
        FILE *inptr = fopen(infile, "r");
        if (inptr == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", infile);
            return 2;
        }

        // open output file
        FILE *outptr = fopen(outfile, "w");
        if (outptr == NULL)
        {
            fclose(inptr);
            fprintf(stderr, "Could not create %s.\n", outfile);
            return 3;
        }

        // read infile's BITMAPFILEHEADER
        BITMAPFILEHEADER bf; // int newbf;
        fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

        // read infile's BITMAPINFOHEADER
        BITMAPINFOHEADER bi;
        fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

        // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
        if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
            bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fclose(outptr);
            fclose(inptr);
            fprintf(stderr, "Unsupported file format.\n");
            return 4;
        }
        // determine padding for scanlines
        int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
        int newPadding = (4 - ((bi.biWidth*n) * sizeof(RGBTRIPLE)) % 4) % 4;

        BITMAPFILEHEADER newBf;
        BITMAPINFOHEADER newBi;

        newBf = bf;
        newBi = bi;
        newBi.biWidth = (bi.biWidth*n);
        newBi.biHeight = bi.biHeight *n;
        newBi.biSizeImage = ((sizeof(RGBTRIPLE) * newBi.biWidth) + newPadding) * abs(newBi.biHeight);
        newBf.bfSize = newBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        // write outfile's BITMAPFILEHEADER
        fwrite(&newBf, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);

         RGBTRIPLE scanline[newBi.biWidth];

        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for(int k=0; k<n; k++)
                {            // write RGB triple to outfile
                    scanline[( j * n) + k] = triple;

                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            for(int b=0; b<n; b++)
            {
                fwrite(scanline, sizeof(scanline), 1, outptr);

                // then add it back (to demonstrate how)
                 for (int k = 0; k < newPadding; k++)
                {
                    BYTE zero = 0x00;
                    fwrite(&zero,1,1,outptr);
                //fputc(0x00, outptr);
            }
        }
    }
     // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
    }


}
