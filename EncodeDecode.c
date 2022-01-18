/**************************/
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
/*************************/

#include "EncodeDecode.h"
#include "ppm.h"
#include <string.h>
#include <memory.h>
#include <stdlib.h>

void removeDigit(pixel_t ** pixelArray, header_t header) {
    for (int i = 0; i < header.height; i++) {
        for (int j = 0; j < header.width; j++) {
            pixelArray[i][j].r -= ((pixelArray[i][j].r) % 10);
            pixelArray[i][j].g -= ((pixelArray[i][j].g) % 10);
            pixelArray[i][j].b -= ((pixelArray[i][j].b) % 10);
        }
    }
    return;
}

int *decToBin(int val, int *bin) {
    int i = 8;
    while (val > 0) {
        // least significant byte is always 0, since characters
        // must be coded in groups of 9 (3 color channels)
        if (i == 0) {
            bin[i] = 0;
        }
        else {
            bin[i] = val % 2;
            val /= 2;        
        }
        i--;
    }
    return bin;
}

int binToDec(int *bin) {
    int val = 0;
    int msb = 1;
    for (int i = 8; i >= 0; i--) {
        val = val + (bin[i] * msb);
        msb *= 2;
    }
    return val;
}

void encodeMsg(FILE *in, FILE *out, char *message) { 
    header_t header = readHeader(in);
    // checks to make sure message will fit in image file.
    // each letter requires 3 pixels to encode.
    if (strlen(message) > (header.height * header.width) / 3) {
        printf("Error.  Message is too long to encode in supplied PPM file.  Exiting\n");
        EXIT_FAILURE;
    }    

    pixel_t **pixelArray = readPixels(in, header);
    removeDigit(pixelArray, header);

    int rowCounter = 0;
    int colCounter = 0;

    for (int i = 0; i < strlen(message); i++) {
        // resets only digit counter at each new character in message
        int bitCounter = 0;
        int *bin = (int *)malloc(9 * sizeof(int));
        decToBin(message[i], bin);
        // now that we have the binary data to represent the character, 
        // update pixelArray to hold that data in each color channel
        bitCounter = 0;
        for (int j = 0; j < 3; j++) {
            pixelArray[rowCounter][colCounter].r += bin[bitCounter];
            bitCounter++;
            pixelArray[rowCounter][colCounter].g += bin[bitCounter];
            bitCounter++;
            pixelArray[rowCounter][colCounter].b += bin[bitCounter];
            bitCounter++;

            colCounter++;
            // check if the row needs to be incremented
            if (colCounter % (header.width) == 0) rowCounter++;
        }
        free(bin);
    }
    writePixels(out, pixelArray, header);
    freeMemory(pixelArray, header);

    return;
}

void decodeMsg(FILE * input) {
    header_t header = readHeader(input);
    pixel_t **pixelArray = readPixels(input, header);

    int character = 1;
    // every character requires 9 pixels to read
    int *bin = malloc(9 * sizeof(int));
    int rowCount = 0;
    int colCount = 0;

    printf("message: \n");
    
    // message ends when it reads in a terminating null
    while (character != 0) {
        // character = 0;
        int digitCount = 0;
        while (digitCount < 9) {
            bin[digitCount] = pixelArray[rowCount][colCount].r % 10;
            digitCount++;        

            bin[digitCount] = pixelArray[rowCount][colCount].g % 10;
            digitCount++;

            bin[digitCount] = pixelArray[rowCount][colCount].b % 10;
            digitCount++;

            colCount++;
            if (colCount % header.width == 0) rowCount++;
        }
        // after all 9 binary bin are stripped, calculate the int value of the array
        character = binToDec(bin);

        printf("%c", character);
    }
    printf("\n");
    freeMemory(pixelArray, header);
    free(bin);

    return;
}