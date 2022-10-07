#include <stdio.h>
#include <stdlib.h>
#include "auxiliaryFunctions.h"

void P1A()
{
    int arr[AX];

    for(int a = 0; a < AX; a++)
    {
        arr[a] = a;
    }
    for (int a = 0; a < AX-1; a++)
    {
        printf("%d\t", arr[a]);
    }
    printf("%d\n", arr[AX-1]);

    for (int a = AX-1; a > 0; a--)
    {
        printf("%d\t", arr[a]);
    }
    printf("%d\n", arr[0]);
}

void P1B()
{
    int arr[BX][BY][BZ];
    int d=1;
    int sum=0;

    for(int a=0; a<BX;a++)
    {
        for(int b=0; b<BY; b++)
        {
            for(int c=0; c<BZ; c++)
            {
                arr[a][b][c]=(float)((a+b*c)%d);
                d++;
            }
        }
    }

    printf("sum of all items in array \n");
    for(int a=0; a<BX;a++)
    {
        for(int b=0; b<BY; b++)
        {
            for(int c=0; c<BZ; c++) printf("%5d ",arr[b][a][c]);;
            if(b<BY-1) printf(" |");
        }
        printf("\n");
    }

    for(int a=0; a<BX;a++)
    {
        for(int b=0; b<BY; b++)
        {
            for(int c=0; c<BZ; c++) sum += arr[b][a][c];
        }
    }
    printf("is %d \n", sum);
}

void P1C()
{
    int matrix_A[CX][CY];
    int matrix_B[CY][CX];
    int d = 0;

    for(int a=0; a<CX;a++)
    {
        for(int b=0; b<CY; b++)
        {
            matrix_A[a][b] = rand()%100;
            d++;
        }
    }

    for(int a=0; a<CX;a++)
    {
        for(int b=0; b<CY; b++) matrix_B[b][a] = matrix_A[a][b];
    }
    for(int a=0; a<NUM_LENGTH*CX-3;a++) printf(" ");
    printf("T\n");

    for(int a=0; (a<CX)||(a<CY); a++)
    {
        if((a<CX))
            for (int b = 0; b < CY; b++)        printf("%5d",matrix_A[b][a]);
        else
            for(int a=0; a<5*CX;a++)   printf(" ");

        if  (a == (CX/2)-1)             printf("  =  ");
        else printf("     ");

        for (int b = 0; b < 2; b++)     printf(" ");
        
        if((a<CY))
            for (int b = 0; b < CX; b++)        printf("%5d",matrix_B[a][b]);
        else
            for(int a=0; a<NUM_LENGTH*CY;a++)   printf(" ");
        
        printf("\n");
    }
}

void P1D()
{
    int a;
    printf("enter an integer -  ");
    scanf("%d", &a);
    printf("%d -", a);
    printf("%d\n", getFibonacciNum(a));
}

void P1BU()
{
    struct point point_position[BU_POINT];
    float point_distance[BU_POINT][BU_POINT];

    for(int a = 0; a < 8; a++)
    {
        for (int b = 0; b < BU_DIMENSION; b++)
        {
            point_position[a].coordinate[b] = (rand()%200)-100;
        }
        printf("P%d ",a); printfVector(point_position[a]);
        
    }
    for(int a = 0; a<BU_POINT ;a++)
    {
        for(int b = 0; b < BU_POINT; b++)    point_distance[a][b] = getDistance(point_position[a], point_position[b]);
    }
    printf("\n");
    for(int d=0; d < 6; d++) printf(" ");
    for(int a = 0; a < BU_POINT; a++)
    {
        printf("P%4d",a);
    }
    printf("\n");
    for(int a = 0; a < BU_POINT; a++)
    {
        printf("P%4d",a);
        for(int b = 0; b < BU_POINT; b++)
        {
            printf("%8.2f",point_distance[a][b]);
        }
        printf("\n");
    }
}

int main()
{   
    P1B(); 
    return 0;
}
