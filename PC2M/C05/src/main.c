#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define MAX_WORLD_COUNT 64
#define MAX_WORLD_LENGTH 20

char text[] = "cat dog hen duck goat pig horse rabbit sheep cow lion tiger wolf fox elephant cock hippo reindeer owl eagle sparrow swallow";

struct world
{
	char *start;
	int length;
	int world_num;
};

struct world animal[MAX_WORLD_COUNT]; //sem linej a nechce se mi psát pořádná dynamická alokace

int reedWorldLength(char *start, char *array_end)
{
	if((96<(*start))&&((*start)<123)&&(start<=array_end))
		return (reedWorldLength((start+1),array_end)+1);
	return 0;
}

void printWorld(struct world x)
{
	for(int a = 0; a<x.length; a++)
		printf("%c", *(x.start+a));
	printf("\n");
}

int getWorldsCount(int length)
{
	int word_count = 0;
	for (int b = 0; b < MAX_WORLD_COUNT; b++)
		if(animal[b].length==length) word_count++;
	return word_count;
}

int main()
{
	char *array_end;
	array_end = &text[(int)(sizeof(text)-2)];
	animal[0].start = &text[0];
	animal[0].length = reedWorldLength(animal[0].start, array_end);
	animal[0].world_num = 0;
	*(animal[0].start) -= 32;

	printWorld(animal[0]);

	for(int a = 1; a<MAX_WORLD_COUNT ;a++)
	{
		animal[a].start = animal[a-1].start + animal[a-1].length+1;
		animal[a].length = reedWorldLength(animal[a].start, array_end);
		animal[a].world_num = a;
		*(animal[a].start) -= 32;
		if(animal[a].length==0) 
		{
			printf("\n\nThe total number of words is %d\n\n",animal[a].world_num);
			break;
		}
		printWorld(animal[a]);
	}

	for (int a = 1; a < MAX_WORLD_LENGTH; a++)
	{
		int word_count = getWorldsCount(a);
		if(word_count!=0) printf("The number of words with %d characters is %d\n", a, word_count);
	}
	return (0);
}