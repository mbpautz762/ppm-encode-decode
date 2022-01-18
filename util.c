/**************************/
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
/*************************/
#include <stdlib.h>
#include "utils.h"

void checkArgs(int supplied, int expected) {
    if (supplied != expected) {
        fprintf(stderr, "Please re-run program with the proper format:\n");
        fprintf(stderr, "program inputfile.ppm outputfile.ppm\nExiting.\n");
        
        exit(1);
    }
    else return;
}

void checkFile(FILE *file, char *name) {
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s.  Exiting.\n", name);
        exit(1);
    }
}