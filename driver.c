// ************************
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
// ************************

#include <stdio.h>
#include <stdlib.h>
#include "EncodeDecode.h"
#include "ppm.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    char *message = "Mr. big, fat, Colby Jack! (My Corgi's nickname)";

    checkArgs(argc, 3);
    FILE* input = fopen(argv[1], "r");
    checkFile(input, argv[1]);
    FILE* output = fopen(argv[2], "w");
    checkFile(output, argv[2]);

    encodeMsg(input, output, message);

    fclose(output);

    FILE *decode;
    decode = fopen("output.ppm", "r");

    decodeMsg(decode);
        
    fclose(input);
    fclose(decode);

    return EXIT_SUCCESS;
}



