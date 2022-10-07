#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct mat_t
{
    double x[3][3];
}mat_t;

mat_t* matice(mat_t *A, mat_t *B, char mark);

void printMat(mat_t *x);

void writeFile(char *file_path, mat_t *A, mat_t *B, mat_t *C, mat_t *D, mat_t *E);
void readFile(char *file_path, mat_t *A, mat_t *B, mat_t *C, mat_t *D, mat_t *E);