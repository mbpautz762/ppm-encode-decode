/**************************/
//  Matthew pautz                                
//  CPSC2310 PA1                         
//  mpautz                                
//  Section: 002
/*************************/

#ifndef UTILS_H
#define UTIL_H

#include <stdio.h>

// functions check to make sure the proper terminal arguments are in place
// before running the program, to ensure proper operation.
void checkArgs(int, int);

// function checks to make sure all file pointers opened successfully.
void checkFile(FILE*, char *);

#endif
