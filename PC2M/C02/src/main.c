#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isPrime(int number)
{
    for(int a = 2; a<number;a++)
    {
        if(number % a == 0) return 0;
    }
    return 1;
}


int det(int matrix[3][3])
{
    int out = 0;
    for(int a=0; a<3; a++)
    {
        int x = matrix[a][0];
        for(int b = 1; b<3; b++)    
		{
			x *= matrix[(a+b)%3][b];
		}
        out += x;
		// printf("%d - ", out);
        x = matrix[2-a][0];
        for(int b = 1; b<3; b++)
		{
			x *= matrix[(5-b-a)%3][b];
        }
		out -= x;
		// printf("\n");
    }
    return out;
}

int pointerDet(const int *firet_matrix_member)
{
    int out = 0;
    for(int a=0; a<3; a++)
    {
        int x = *(firet_matrix_member+a);
        for(int b = 1; b<3; b++)    
		{
			x *= *(firet_matrix_member+((a+b)%3)+(3*b));
		}
        out += x;
        x = *(firet_matrix_member+(2-a));
        for(int b = 1; b<3; b++)   
		{
			x *= *(firet_matrix_member+((5-b-a)%3)+(3*b));
        }
		out -= x;
    }
	return out;
}

int main() 
{
	int t = time(NULL);
			srand (t);
    int Matrix[3][3] = {{ 7, 5, 8},
						{ 9, 4, 2},
						{ 1, 1, 1}};
	int *matrix = &Matrix[0][0];
    for(int a = 0; a < 3; a++)
    {
        for(int b = 0; b <3; b++) 
        {
            *(matrix+b+3*a) = (rand()%198)-99;
            printf("%4d; ", *(matrix+b+3*a));
        }
        printf("\n");
    }

    printf("%4d\n",pointerDet(matrix));
    printf("%4d\n",det(Matrix));
}