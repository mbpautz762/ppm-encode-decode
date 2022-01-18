/**************************/
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
/*************************/

#ifndef PPM_H
#define PPM_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdbool.h>

// pixel_t holds the RGB pixel values from a .PPM file
typedef struct
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel_t;

// header_t holds the PPM image header file data.
typedef struct
{
    char magicNum[3];
    int width;
    int height;
    int maxVal;
    char comment[81];
    bool hasComment;

}header_t;

// function takes in a file * for an input .ppm file and 
// returns the appropriate PPM image header.
header_t readHeader(FILE *input);

// arguments: pointer for an input .ppm file, and a header_t containing
// the file's .PPM image header data.
// function returns the 2D array of RGB pixel data for encoding.
pixel_t** readPixels(FILE *input, header_t header);

// arguments: pointer to an output .ppm file, and a header_t containing the
// input file's header data.  Function writes the header to the empty 
// output file.
void writeHeader(FILE *output, header_t header);

// arguments: pointer to an output .ppm file, an array of the input file's
// pixel data, and a header_t containing the input file's header data.
// function outputs the encoded pixel data to the output file.
void writePixels(FILE *output, pixel_t **pixelArray, header_t header);

// arguments: pointer to a .ppm file and a header holding the file's PPM
// header data.  Function checks the next character, and if it matches the 
// start of a comment, stores the comment in the header.
header_t processComment(FILE *ppm, header_t header);

// arguments: takes an array of pixel data and the header data.  
//  Function deletes the pointers and frees the associated memory.
void freeMemory(pixel_t **pixelArray, header_t header);

#endif
