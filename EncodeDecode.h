/**************************/
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
/*************************/

#ifndef ENCODEDECODE_H
#define ENCODEDECODE_H

#include <stdio.h>
#include "ppm.h"

// arguments - takes an array of pixel_t holding a PPM image's pixel data
// and its associated header data.  Function resets the least significant
// digit of each color channel (RGB) to zero in preparation of
// message encoding.
void removeDigit(pixel_t **pixelArray, header_t header);

// arguments - takes file pointers for an input and output PPM file, and
// a character array holding the message to encode.  Function converts the
// message to its binary representation, and encodes each binary digit into
// a single color channel (R, G, and B) in the pixel array.
void encodeMsg(FILE* in, FILE* out, char* msg);

// arguments - takes a file pointer for an encoded PPM image file.  Function 
// reads the least significant digit of each color channel at each position in
// the file's pixel data, and converts them to char values that correspond to
// the letters in the hidden message
void decodeMsg(FILE *input);

// arguments - takes an int and a pointer to an int array of size 9
// and returns a pointer to an int array that holds the binary
// digits of the passed in value.
int *decToBin(int val, int *bin);

// arguments - takes a pointer to an int array of size 9 holding binary digits
// and retruns the decimal value of the binary array.
int binToDec(int *bin);

#endif
