#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "car.h"
#include "rec.h"

rec_t *race_card[20] = {0};
car_t *car_card[20] = {0};

int main( void)
{
	addRec(race_card, "test 0", 10, 100);
	addRec(race_card, "test 1", 11, 101);
	addRec(race_card, "test 2", 12, 102);
	delRec(race_card, 0);
	printfAllRec(race_card);

	char *file_in = "/home/mtar/Documents/skola/s2/PC2M/C8/output/vstup.txt";
	char *file_out = "/home/mtar/Documents/skola/s2/PC2M/C8/output/vystup.txt";
	FILE *fp_in = fopen(file_in, "r");
	FILE *fp_out = fopen(file_out, "w");

    if (fp_in == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s", file_in);
        return 1;
    }

	for(int a = 0; a < 10; a++)
	{
		printf("%c", fgetc(fp_in));
		fp_in--;
	}

	// char sim = fgetc(fp_in);
	// while((sim != EOF))
	// {
	// 	char nam[20] = {0};
	// 	int a = 0;
	// 	while((((sim > 47)&&(sim < 58))||(sim == 46)))
	// 	{
	// 		nam[a] = sim;
	// 		a++;
	// 		sim = fgetc(fp_in);
	// 	}
			
	// 	double sam = atof(nam);
	// 	while(sim != '\n')
	// 	{
	// 		a = 0;
	// 		sim = fgetc(fp_in);
	// 		while((((sim > 47)&&(sim < 58))||(sim == 46)))
	// 		{
	// 			nam[a] = sim;
	// 			a++;
	// 			sim = fgetc(fp_in);
	// 		}
	// 		sam += atof(nam);
	// 	}	
	// 	sim = fgetc(fp_in);
	// 	fprintf(fp_out,"%f\n",sam);
	// }

	fclose(fp_in);
	fclose(fp_out);
  	return 0;
}