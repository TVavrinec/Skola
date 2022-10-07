#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#include "ComplexNumbers.h"

struct array_t
{
	int max;
	int min;
	int sum;
	int array[3][3];
};

struct array_t maxNumber(int array[][4], int radek)
{
	struct array_t x;
	x.max = array[0][0];
	for(int a = 0; a < 4*radek; a++)
	{
		*(&x.array[0][0]) = *(&array[0][0]);
		if((*(&array[0][0]+a))>x.max) 
			x.max = *(&array[0][0]+a);
	}
	return x;
}

struct array_t minNumber(int array[][4], int radek)
{
	struct array_t x;
	x.min = array[0][0];
	for(int a = 0; a < 4*radek; a++)
	{
		*(&x.array[0][0]) = *(&array[0][0]);
		if((*(&array[0][0]+a))<x.min) 
			x.min = *(&array[0][0]+a);
	}
	return x;
}

struct array_t sumNumber(int array[][4], int radek)
{
	struct array_t x;
	x.min = array[0][0];
	x.sum = 0;
	for(int a = 4*(radek-1); a < 4*radek; a++)
	{
		x.sum += *(&array[0][0]+a);
	}
	return x;
}

int main()
{
	struct Complex_num_t a, b;
	a.Re = 2; a.Im = -3;
	b.Re = 5; b.Im = 4;

	printf("%4.2f+%4.2fj\n",complexSum(a,b).Re			, complexSum(a,b).Im         );
	printf("%4.2f+%4.2fj\n",complexDifference(a,b).Re	, complexDifference(a,b).Im  );
	printf("%4.2f+%4.2fj\n",complexMultiple(a,b).Re		, complexMultiple(a,b).Im    );
	printf("%4.2f+%4.2fj\n",complexShare(a,b).Re		, complexShare(a,b).Im       );

	int array[3][4] = {	{2,	5,	3,	2},
						{3,	5,	1,	5},
						{3, 42,	0,	3},
						};
	printf("%d\n",maxNumber(array,3).max);
	printf("%d\n",minNumber(array,3).min);
	printf("%d\n",sumNumber(array,1).sum);
	printf("%d\n",sumNumber(array,2).sum);
	printf("%d\n",sumNumber(array,3).sum);


	return (0);
}
