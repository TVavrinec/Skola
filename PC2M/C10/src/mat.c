#include "mat.h"

mat_t* matice (mat_t *A, mat_t *B, char mark)
{
    mat_t *C = (mat_t *)malloc(sizeof(mat_t));
    for (int a = 0; a < 9; a++)
        C->x[a%3][a/3] = 0;
    
    switch(mark)
    {
    case '+':
        for (int a = 0; a < 9; a++)
        {
            C->x[a%3][a/3] = A->x[a%3][a/3]+B->x[a%3][a/3];
        }
        return C;
        break;
    case '-':
        for (int a = 0; a < 9; a++)
        {
            C->x[a%3][a/3] = A->x[a%3][a/3]-B->x[a%3][a/3];
        }
        return C;
    case '*':
        for (int a = 0; a < 9; a++)
        {
            for (int b = 0; b < 3; b++)
            {
                C->x[a%3][a/3] += A->x[b%3][a%3]*B->x[a%3][b];
            }
        }
        return C;
    default:
        break;
    }
    return NULL;
}

void printMat(mat_t *x)
{
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            printf("%4.1f ", x->x[b][a]);
        }
        printf("\n");
    }
}

void writeFile(char *file_path, mat_t *A, mat_t *B, mat_t *C, mat_t *D, mat_t *E)
{
    FILE *file = fopen(file_path, "w");
	if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return;
    }
    fwrite(A, sizeof(mat_t), 1, file);
    fwrite(B, sizeof(mat_t), 1, file);
    fwrite(C, sizeof(mat_t), 1, file);
    fwrite(D, sizeof(mat_t), 1, file);
    fwrite(E, sizeof(mat_t), 1, file);
    fclose(file);
}

void readFile(char *file_path, mat_t *A, mat_t *B, mat_t *C, mat_t *D, mat_t *E)
{
    FILE *file = fopen(file_path, "r");
	if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return;
    }
    fread(A, sizeof(mat_t), 1, file);
    fread(B, sizeof(mat_t), 1, file);
    fread(C, sizeof(mat_t), 1, file);
    fread(D, sizeof(mat_t), 1, file);
    fread(E, sizeof(mat_t), 1, file);
    fclose(file);
}