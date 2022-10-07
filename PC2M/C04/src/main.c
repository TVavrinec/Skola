#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "auxiliaryFunctions.h"
#include "game.h"

bool a_bin[ARRAY_SIZE], b_bin[ARRAY_SIZE], c_bin[ARRAY_SIZE];
u_int16_t a_dec, b_dec, c_dec;

int main()
{
	srand(time(NULL));

	fillArray(a_bin);
	fillArray(b_bin);
	a_dec = transformToInt(a_bin);
	b_dec = transformToInt(b_bin);

	printf("a_bin:  ");
	for(int a = 0; a < ARRAY_SIZE; a++)
		((a%4==0)&&(a>0)) ? (printf(" %d",a_bin[a])) : printf("%d",a_bin[a]);
	printf("   a_dec:  %6d\n", transformToInt(a_bin));

	printf("b_bin:  ");
	for(int a = 0; a < ARRAY_SIZE; a++)
		((a%4==0)&&(a>0)) ? (printf(" %d",b_bin[a])) : printf("%d",b_bin[a]);
	printf("   b_dec:  %6d\n\n", transformToInt(b_bin));

	conjunctions(a_bin, b_bin, c_bin, a_dec, b_dec);

	disjunction(a_bin, b_bin, c_bin, a_dec, b_dec);

	inequality(a_bin, b_bin, c_bin, a_dec, b_dec);
	
	complement(a_bin, c_bin, a_dec);

	randBitShift(a_bin, c_bin, a_dec);

	game();

	return (0);
}