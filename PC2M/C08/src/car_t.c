#include "car_t.h"

//private

int getCarRecordsNum(car_t *card[20])
{
	int position = 0;
	while(card[position] != NULL)
	{
		if(position<19) position++;
		else 	 
		{
			printf("Car card is full");
			return -1;
		}
	}
	return position;
}

void sortCarCard(car_t *card[20])
{
    int x = getCarRecordsNum(card);
    if(card[x+1]!=NULL)
    {
        card[x]=card[x+1];
        card[x+1]=NULL;
        sortCarCard(card);
    }
}

//public

car_t *addCar(car_t *card[20], char brand[20], int manufacture_year)
{
   	int position = getCarRecordsNum(card);
	if(position<0) return NULL;

	car_t *new_car = (car_t *)malloc(sizeof(car_t));
	card[position] = new_car;
	
	for(int a = 0; a < 10; a++)
		new_car->brand[a] = brand[a];
	new_car->manufacture_year = manufacture_year;

	return new_car;
}

void delCar(struct car_t *card[20], int n)
{
	free(card[n]);
    card[n] = NULL;
    sortCarCard(card);
}

void printAllCar(car_t *card[20])
{
    for(int a = 0; a<getCarRecordsNum(card); a++)
	{
		printf("%s - %d\n", card[a]->brand, card[a]->manufacture_year);
	}
}

void showCar(car_t *card[20],int car)
{
	printf("%s - %d\n", card[car]->brand, card[car]->manufacture_year);
}
