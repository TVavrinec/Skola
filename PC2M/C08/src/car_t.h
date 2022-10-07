#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct car_t
{
    char brand[20];
    int manufacture_year;
} car_t;

//private

//int getRecordsNum(car_t *card[20]);

//public

car_t *addCar(car_t *card[20], char brand[20], int manufacture_year);

void delCar(car_t *card[20], int n);

void printAllCar(car_t *card[20]);

void showCar(car_t *card[20],int car);