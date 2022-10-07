#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int convert2_10(char bite[8])
{
	int out = 0;
	for(int a = 7; a >= 0; a--)
	{
		out += (bite[a]-48)<<(7-a);
	}
	return out;
}

int main()
{
	printf("%4d\n", convert2_10("00001001"));
	srand (time(NULL));
	char arr[1000];
	int sam[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
	float p = 0;
	for(int a = 0; a < 1000; a++)
	{
		arr[a] = rand()%10;
		p += arr[a];
	}
	for(int a = 0; a <1000;a++)
	{
		sam[arr[a]]++;
	}
	printf("\n");
	for(int a = 0; a < 10;a++)
	{
		printf("%d - ", sam[a]);
	}
	p = p/1000;
	printf("\n%4.2f\n", p);
	return (0);
}