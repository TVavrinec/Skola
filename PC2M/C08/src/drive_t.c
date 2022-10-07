#include "drive_t.h"

//private

int getDriveRecordsNum(drive_t *card[20])
{
	int position = 0;
	while(card[position] != NULL)
	{
		if(position<19) position++;
		else 	 
		{
			printf("Drive card is full");
			return -1;
		}
	}
	return position;
}

void sortDriveCard(drive_t *card[20])
{
    int x = getDriveRecordsNum(card);
    if(card[x+1]!=NULL)
    {
        card[x]=card[x+1];
        card[x+1]=NULL;
        sortDriveCard(card);
    }
}

//public

bool addRec(drive_t *card[20], char name[10], int full, int km)
{
	int position = getDriveRecordsNum(card);
	if(position<0) return false;

	drive_t *new_drive = (drive_t *)malloc(sizeof(drive_t));
	card[position] = new_drive;
	
	for(int a = 0; a < 10; a++)
		new_drive->name[a] = name[a];
	new_drive->full = full;
	new_drive->km = km;

	return true;
}

void delRec(drive_t *card[20], int n)
{
	free(card[n]);
    card[n] = NULL;
    sortDriveCard(card);
}

void printAllDrive(drive_t *card[20])
{
    for(int a = 0; a<getDriveRecordsNum(card) ; a++)
	{
		printf("%s - %d - %d\n", card[a]->name, card[a]->full, card[a]->km);
	}
}