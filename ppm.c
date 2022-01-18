/**************************/
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
/*************************/

#include "ppm.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

header_t processComment(FILE *ppm, header_t header) {
    char c = fgetc(ppm);
    if (c == '#') {
        ungetc(c, ppm);
        header.hasComment = true;
        fgets(header.comment, 80, ppm);
    }
    else ungetc(c, ppm);

    return header;
}

// reads header from .ppm file
header_t readHeader(FILE *ppm) {

    header_t header;
    fscanf(ppm, "%[^ \n]", header.magicNum);
    // consume the newline character, or space before checking for comments
    fgetc(ppm);
    // check for comments after next two fields
    header = processComment(ppm, header);
    fscanf(ppm, "%i", &(header.width));

    header = processComment(ppm, header);
    fscanf(ppm, "%i", &(header.height));

    header = processComment(ppm, header);
    fscanf(ppm, "%i", &(header.maxVal));

    return header;
}

void writeHeader(FILE * output, header_t header) {
    fprintf(output, "%s\n", header.magicNum);
    // uncomment next line if you would like to print comment in output file
    // if (header.hasComment == true) fprintf(output, "%s", header.comment);

    fprintf(output, "%i %i %i\n", header.width, 
        header.height, header.maxVal);

    return;
}

pixel_t **readPixels(FILE *input, header_t header) {
    int rows = header.height;
    int cols = header.width;

    // allocation for 2D array of RGB pixels (3 per column)
    pixel_t **pixelArray = (pixel_t **)malloc(rows * sizeof(pixel_t *));
    for (int i = 0; i < rows; i++) {
        pixelArray[i] = (pixel_t *)malloc(cols * sizeof(pixel_t) );  
    }
    // clear the input stream before scanning
    getc(input);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(input, "%c%c%c", &(pixelArray[i][j].r),
                &(pixelArray[i][j].g), &(pixelArray[i][j].b));        
            }
    }
    return pixelArray;
}

void writePixels(FILE *output, pixel_t **pixelArray, header_t header) {
    
    writeHeader(output, header);
    // prints appropriate values depending on input header 
    if (strcmp(header.magicNum, "P6") == 0) {
        for (int i = 0; i < header.height; i++) {
            for (int j = 0; j < header.width; j++) {
                fprintf(output, "%c%c%c", pixelArray[i][j].r, pixelArray[i][j].g, 
                    pixelArray[i][j].b);    
            }
        }
    }
    else {
        for (int i = 0; i < header.height; i++) {
            for (int j = 0; j < header.width; j++) {
                fprintf(output, "%d %d %d ", pixelArray[i][j].r, pixelArray[i][j].g, 
                    pixelArray[i][j].b);
            }
        }
    }
    return;
}

void freeMemory(pixel_t ** pixelArray, header_t header) {
    for (int i = 0; i < header.height; i++) {
            free(pixelArray[i]);
    }
    free(pixelArray);
}

