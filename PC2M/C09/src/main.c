#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct array_t
{
	float t[16][12];
}array_t;

typedef struct zlomek_t
{
	int up;
	int down;
} zlomek_t;

double readNumFromFile(FILE *file, int read_out_space)
{
	char nam[20] = {0}; 
	int a = 0;
	char sim = fgetc(file);
	fpos_t position;
	while((((sim > 47)&&(sim < 58))||(sim == '.')||(sim == '-')))
	{
		nam[a] = sim;
		a++;
		fgetpos (file, &position);
		sim = fgetc(file);
	}
	if(!read_out_space)	fsetpos (file, &position);
	return atof(nam);
}

void goSim(FILE *file)
{
	char sim = fgetc(file);
	fpos_t position;
	while((sim == ' ')||(sim == '/'))
	{
		fgetpos (file, &position);
		sim = fgetc(file);
	}
	fsetpos (file, &position);
}

array_t readFile(FILE *file)
{
	array_t out_data;
	for (int a = 0; a < 16; a++)
	{
		for (int b = 0; b < 12; b++)
		{
			out_data.t[a][b] =  readNumFromFile(file, 1);
		}
	}
	return out_data;
}

void printFile(array_t file_data)
{
	for (int a = 0; a < 16; a++)
	{
		printf("\n%d: ", a + 1995);
		for (int b = 0; b < 12; b++)
		{
			printf("%6.1f °C,", file_data.t[a][b]);
		}
	}
	printf("\n");
}

float getYearAverage(array_t file_data, int year)
{
	double sum = 0;
	for (int a = 0; a < 12; a++)
	{
		sum += file_data.t[year-1995][a];
	}
	return sum / 12;
}

float getMonthAverage(array_t file_data, int month)
{
	double sum = 0;
	for (int a = 0; a < 16; a++)
	{
		sum += file_data.t[a][month];
	}
	return sum / 16;
}

void writeFile(FILE *file, array_t file_data)
{
	fprintf(file, "        January, February,    March,    April,      May,     June,     July,  August, September,  October, November, December, \n");
	for (int a = 0; a < 16; a++)
	{
		fprintf(file,"%d: ", a + 1995);
		for (int b = 0; b < 12; b++)
		{
			fprintf(file, "%6.1f °C,", file_data.t[a][b]);
		}
		fprintf(file,"%6.1f\n", getYearAverage(file_data, a+1995));
	}
	fprintf(file,"      ");
	for (int a = 0; a < 12; a++)
	{
		fprintf(file, "%6.1f °C,", getMonthAverage(file_data,a));
	}
}

int gcd(zlomek_t zl)
{
	int t;
    while(zl.up != 0)
    {
	    t = zl.down%zl.up;
        zl.down = zl.up;
        zl.up = t;
	}
    return zl.down;
}

int main( void)
{
	char *file_in = "/home/mtar/Documents/skola/s2/PC2M/C9/output/vstup.txt";
	char *file_in2 = "/home/mtar/Documents/skola/s2/PC2M/C9/output/vstup2.txt";
	char *file_out = "/home/mtar/Documents/skola/s2/PC2M/C9/output/vystup.txt";
	FILE *fp_in = fopen(file_in, "r");

    if (fp_in == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_in);
        return 1;
    }
	array_t file_data = readFile(fp_in);
	fclose(fp_in);

	printFile(file_data);
	printf("\nGive a year to calculate the temperature average\n");
	int average_argument;
	scanf("%d", &average_argument);
	printf("temperature average of the year is %6.2f °C\n", getYearAverage(file_data, average_argument));

	printf("\nGive a month to calculate the temperature average\n");
	scanf("%d", &average_argument);
	printf("temperature average of the month is %6.2f °C\n\n", getMonthAverage(file_data, average_argument));

	FILE *fp_out = fopen(file_out, "w");
	writeFile(fp_out, file_data);
	fclose(fp_out);

	FILE *fp_in2 = fopen(file_in2, "r");
	if (fp_in2 == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_in2);
        return 1;
    }
	zlomek_t zl[4], out;
	for (int a = 0; a < 4; a++)
	{
		zl[a].up = readNumFromFile(fp_in2, 0);
		goSim(fp_in2);
		zl[a].down = readNumFromFile(fp_in2, 1);
		printf("Zlomek %d  je %d  / %d\n",a, zl[a].up, zl[a].down);
	}
	out.up = zl[0].up*zl[1].down + zl[1].up*zl[0].down;
	out.down = zl[0].down*zl[1].down;
	out.up = out.up*zl[2].down + zl[2].up*out.down;
	out.down = zl[2].down*out.down;
	out.up = out.up*zl[3].down + zl[3].up*out.down;
	out.down = zl[3].down*out.down;
	printf("3  - %d  / %d --- %d\n", out.up, out.down, gcd(out));
	printf("3  - %d  / %d --- %d\n", out.up/gcd(out), out.down/gcd(out));

  	return 0;
}