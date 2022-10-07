#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "auxiliaryFunctions.h"

int getFibonacciNum(int number)
{
    if(number <= 0) return 0;
    if(number == 1) return 1;
    return getFibonacciNum(number-1)+getFibonacciNum(number-2);
}

int getDistance(struct point point_A,struct point point_B)
{
    int distance = 0;
    for (int c = 0; c < BU_DIMENSION; c++)
    {
        distance += pow(point_A.coordinate[c]-point_B.coordinate[c],2);
    }
    return pow(distance, 1.0/BU_DIMENSION);
}

void printfVector(struct point printing_point)
{
    printf("(");
    for (int b = 0; b < BU_DIMENSION; b++)
    {
        printf("%8.2f",printing_point.coordinate[b]);
        if(b<BU_DIMENSION-1) printf(",");
    }
    printf(") \n");
}
