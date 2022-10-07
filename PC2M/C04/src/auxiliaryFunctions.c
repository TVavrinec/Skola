#include "auxiliaryFunctions.h"

void fillArray(bool *bin)
{
	for(int a = 0; a < ARRAY_SIZE; a++) 
		*(bin + a) = rand()%2;
}

int transformToInt(bool *bin)
{
	int out = 0;
	for(int a = 0; a < ARRAY_SIZE; a++) 
		out += *(bin + a)<<(ARRAY_SIZE-(a+1));
	return out;
}

void conjunctions(bool *a_bin, bool *b_bin, bool *out_bin, int a_dec, int b_dec)
{
    printf("Bit-wise conjunction\n");
	for(int a = 0; a < ARRAY_SIZE; a++)
		*(out_bin+a) = *(a_bin+a) & *(b_bin+a);
    printfArrayAndInt(out_bin, a_dec&b_dec);
}

void disjunction(bool *a_bin, bool *b_bin, bool *out_bin, int a_dec, int b_dec)
{
    printf("Bit-wise disjunction\n");
	for(int a = 0; a < ARRAY_SIZE; a++)
		*(out_bin+a) = *(a_bin+a) | *(b_bin+a);
    printfArrayAndInt(out_bin, a_dec|b_dec);
}

void inequality(bool *a_bin, bool *b_bin, bool *out_bin, int a_dec, int b_dec)
{
    printf("Bit-wise inequality\n");
	for(int a = 0; a < ARRAY_SIZE; a++)
		*(out_bin+a) = *(a_bin+a) ^ *(b_bin+a);
    printfArrayAndInt(out_bin, a_dec^b_dec);
}

void complement(bool *a_bin, bool *out_bin, int a_dec)
{
    printf("Bit-wise complement\n");
	for(int a = 0; a < ARRAY_SIZE; a++)
		*(out_bin+a) = !(*(a_bin+a));
    printfArrayAndInt(out_bin, ~a_dec);
}

void randBitShift(bool *a_bin, bool *out_bin, int a_dec)
{
    int x = (rand()%7)+1;
    printf("Bit shift to right: %d bits\n", x);
    for(int a = 0; a < ARRAY_SIZE; a++)
        *(out_bin+(ARRAY_SIZE-a-1)) = (a<=(ARRAY_SIZE-x)) ? *(a_bin+(ARRAY_SIZE-a-x-1)) : (0);
    printfArrayAndInt(out_bin, a_dec>>x);
}

void printfArrayAndInt(bool *bin, int number)
{
	printf("c_bin:  ");
	for(int a = 0; a < ARRAY_SIZE; a++)
		((a%4==0)&&(a>0)) ? (printf(" %d",*(bin+a))) : printf("%d",*(bin+a));
	printf("   c_dec:  %6d   d_dec: %6d\n\n", transformToInt(bin), number);
}
