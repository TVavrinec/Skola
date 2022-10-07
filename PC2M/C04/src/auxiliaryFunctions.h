#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 16

void fillArray(bool *bin);

int transformToInt(bool *bin);

void conjunctions(bool *a_bin, bool *b_bin, bool *out_bin, int a_dec, int b_dec);

void disjunction(bool *a_bin, bool *b_bin, bool *out_bin, int a_dec, int b_dec);

void inequality(bool *a_bin, bool *b_bin, bool *out_bin, int a_dec, int b_dec);

void complement(bool *a_bin, bool *out_bin, int a_dec);

void printfArrayAndInt(bool *bin, int number);

void randBitShift(bool *a_bin, bool *out_bin, int a_dec);