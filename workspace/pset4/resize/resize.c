/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize factor infile outfile\n");
        return 1;
    }


  // remember filenames
    int factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];
    
    if(factor<1 || factor >100){
        
        printf("factor vlaue be in range between (1-100)");
        return 1;
    }
    
  

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
    BITMAPFILEHEADER bf;
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
        
        
        
	BITMAPFILEHEADER out_bf;
		BITMAPINFOHEADER out_bi;	
		out_bf = bf;
		out_bi = bi;
		out_bi.biWidth = bi.biWidth * factor;
		out_bi.biHeight = bi.biHeight * factor;

		
		
		// determine padding for scanlines
		// Needed for SizeImage calculation
		int in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
		int out_padding =  (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

		
		
		// Calculate file and image size
		// Kudos for the folks at https://code.google.com/p/kupl09/ for suggesting the formula for 
		// biSizeImage calculation.
		
		
		
		out_bf.bfSize = 54 + out_bi.biWidth * abs(out_bi.biHeight) * 3 + abs(out_bi.biHeight) *  out_padding;
		out_bi.biSizeImage = ((((out_bi.biWidth * out_bi.biBitCount) + 31) & ~31) / 8) * abs(out_bi.biHeight);
		
		
		
      // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //changing the file RGB format using for loops 
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++){
        
        for(int n =0 ; n<factor; n++){
        
        // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++){
            
            // temporary storage
                RGBTRIPLE triple;

            // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for(int m = 0; m < factor; m++){
		        	// write RGB triple to outfile
                     fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
				}
            }

        // skip over padding, if any
            fseek(inptr, in_padding, SEEK_CUR);

        // then add it back (to demonstrate how)
            for (int k = 0; k < out_padding; k++){
                fputc(0x00, outptr);
            }
            fseek(inptr, -(bi.biWidth * 3 + in_padding ), SEEK_CUR);
            
        }
        fseek(inptr, bi.biWidth*3+in_padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
