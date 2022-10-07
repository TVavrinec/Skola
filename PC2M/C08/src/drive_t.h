#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct drive_t
{
	char name[10];
	int full;
	int km; 
} drive_t;

//private

//int getRecordsNum(drive_t *card[20]);

//public

bool addRec(drive_t *card[20], char name[10], int full, int km);
void delRec(drive_t *card[20], int n);

void printAllDrive(drive_t *card[20]);