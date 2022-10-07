int getIntCount(char *file_path)
{
	FILE *file = fopen(file_path, "r");
	int count = 1;
    if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return 0;
    }
	char sim = fgetc(file);
	if(sim == EOF) return 0;
	while (sim != EOF)
	{
		sim = fgetc(file);
		if(sim == '\n') count++; 
	}
	fclose(file);
	return count;
}

int readIntFormFile(FILE *file)
{
	char sim = fgetc(file);
	char sim_num[10] = {'\0'};
	for(int a = 0; (sim != '\n')&&(sim != EOF); a++)
	{
		sim_num[a] = sim;
        sim = fgetc(file);
    }
	return atoi(sim_num);
}

int *loadIntFile(char *file_path)
{
	FILE *file = fopen(file_path, "r");
	if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return 0;
    }
	int int_count = getIntCount(file_path);
	int *first_int = (int *)malloc(int_count * sizeof(int));
	
	for (int a = 0; a < int_count; a++)
	{
		int x = readIntFormFile(file);
		*(first_int+a) = x;
	}
	fclose(file);
	return first_int;
}

int *bubbleSort(int *first_int, int length)
{
	for (int a = 0; a < length-1; a++)	
	{
		for (int a = 0; a < length-1; a++)
		{
			// printf("%d > %d = %d\n",first_int[a], first_int[a+1], first_int[a] > first_int[a+1]);
			if(first_int[a] < first_int[a+1])
			{
				int x = first_int[a];
				first_int[a] = first_int[a+1];
				first_int[a+1] = x;
			}
			// printf("%d > %d = %d\n\n",first_int[a], first_int[a+1], first_int[a] > first_int[a+1]);
		}
	}
	return first_int;
}

int *selectSort(int *first_int, int length)
{
    int min_idx; 
  
    for (int i = 0; i < length-1; i++) 
    { 
        min_idx = i; 
        for (int j = i+1; j < length; j++) 
		{
        	if (first_int[j] < first_int[min_idx]) 
        	    min_idx = j; 
  		}
        int x = first_int[min_idx];
		first_int[min_idx] = first_int[i];
		first_int[i] = x;
    }
	return first_int;
}

int *insertionSort(int *first_int, int length)
{
    int key, j;
    for (int i = 1; i < length; i++)
    {
        key = first_int[i];
        j = i - 1;
 		
		 while (j >= 0 && first_int[j] > key)
        {
            first_int[j + 1] = first_int[j];
            j = j - 1;
        }
        first_int[j + 1] = key;
    }
	return first_int;
}

void printIntList(int *first_int, int length)
{
	for (int a = 0; a < length; a++)
	{
		printf("%d\n", *(first_int+a));
	}
}

int getFileLength(const char *file_path)
{
	int length = 0;
	FILE *file = fopen(file_path, "r");
	if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return 0;
    }
	while (fgetc(file) != EOF)
		length++;

	fclose(file);
	return length;
}

int *cetnost(const char *file_path)
{
	int *cetnost = (int *)malloc(sizeof(int)*128);
	FILE *file = fopen(file_path, "r");
	if (file == NULL)
    {
        printf("AAAAAAAAAAaaaaaaaa konec sveta neotevrel se mi soubor %s  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", file_path);
        return 0;
    }
	for (int a = 0; cetnost[a] != '\0'; a++)
	{
		cetnost[a] = 0;
	}
	char sim = fgetc(file);
	while (sim != EOF)
	{
		cetnost[(int)sim]++;
		sim = fgetc(file);
	}

	return cetnost;
}

// bool jeToSamohlaska(char x)
// {
// 	if((x == 'a')||(x == 'e')||(x == 'i')||(x == 'y')||(x == 'o')||(x == 'u')||
// 	   (x == 'A')||(x == 'E')||(x == 'I')||(x == 'Y')||(x == 'O')||(x == 'U'))
// 		return true;
// 	else 
// 		return false;
// }

// void sifratko(char *text)
// {
// 	for (int a = 0; a < 25; a++)
// 	{
// 		int x = 0;
// 		char word[50] = {0};
// 		for (int b = 0; text[b] != '\0'; b++)
// 		{
// 			word[b] = ((text[b]+a)>90) ? text[b]+a-25 : text[b]+a;
// 			if(!jeToSamohlaska(word[b])) x++;
// 			else x=0;
// 			if(text[b] == '_') 
// 			{
// 				word[b] = '_';
// 				x=0;
// 			}
// 			if(x>2) break;
// 		}
// 		if(x<3) printf("\n%s\n",word);
// 	}
// 	return;
// }


/*
	mat_t *A = (mat_t *)malloc(sizeof(mat_t)*5);;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            A[0].x[b][a] = b;
            A[1].x[b][a] = a;
			A[3].x[b][a] = b+a;
            A[4].x[b][a] = a*b;
        }
    }
	A[2] = *matice(&A[0], &A[1], '*');
	for (int a = 0; a < 3; a++)
	{
		printf("mat%c\n", a+'A');
		printMat(&A[a]);
	}
	printf("-------------------------------->\n");
	writeFile("/home/mtar/Documents/skola/s2/PC2M/C10/output/int.txt", &A[0], &A[1], &A[2], &A[3], &A[4]);
	readFile("/home/mtar/Documents/skola/s2/PC2M/C10/output/int.txt", &A[0], &A[1], &A[2], &A[2], &A[4]);
	for (int a = 0; a < 5; a++)
	{
		printf("mat%c\n", a+'A');
		printMat(&A[a]);
	}
	printf("\n");
	printf("které matice chces secist?\n prvni matice: ");
	char matA;
	char matB;
	char mark;
	scanf("%c", &matA);
	while(!((matA >= 'A')&&(matA <= 'E')))
	{
		printf("takovou matici neznam\n");
		scanf("%c", &matA);
	}
	printf("a druha matice: ");
	scanf("%c\n", &matB);
	while(!((matB >= 'A')&&(matB <= 'E')))
	{
		printf("takovou matici neznam\n");
		scanf("%c", &matB);
	}
	printf("a chces je secist nebo odecist: ");
	scanf("%c\n", &mark);
	while(!((mark == '+')||(mark == '-')))
	{
		printf("takoví operator neznam\n");
		scanf("%c", &mark);
	}
	printf("A\n");
	printMat(&A[matA-'A']);
	printf("B\n");
	printMat(&A[matB-'A']);
	printf("A%cB\n",mark);
	printMat(matice(&A[matA-'A'], &A[matB-'A'], mark));
	free(A);
*/


	// int int_count = getIntCount("/home/mtar/Documents/skola/s2/PC2M/C10/output/int.txt");
	// int *int_list = loadIntFile("/home/mtar/Documents/skola/s2/PC2M/C10/output/int.txt");
	// // printIntList(int_list, int_count);
	// clock_t start = clock();
	// bubbleSort(int_list, int_count); // 		0.3209 	339143
	// //selectSort(int_list, int_count); // 		0.1113 	112826
	// //insertionSort(int_list, int_count); // 	0.0678 	71759
	// clock_t end = clock();
	// printf("\n%8.4f\n", (double)(end - start)/CLOCKS_PER_SEC);
	// // printIntList(int_list, int_count);

	// album_t *album = loadFile("/home/mtar/Documents/skola/s2/PC2M/C10/output/zadani10_databaze.csv");

	// printfAllAlbums(album);
	// addNewAlbum(album, "test", "test", 2022, "test", 10);
	// printfAllAlbums(album);

	// album = sortAlbums(album, albumScore, false);
	// printfAllAlbums(album);
	// // printfAlbum(getAlbum(album, "The Violin Player"));
	// saveAlbumsList(album, "/home/mtar/Documents/skola/s2/PC2M/C10/output/zadani10_databaze_save.csv");
	// // addNewAlbum(alb, char *name, char *interpreter, int year, char *genre, float score);

	// album_compare_prototype_t *x = (album_compare_prototype_t *)malloc(sizeof(album_compare_prototype_t));;
	// strcpy(x->name, "\0");
	// strcpy(x->interpreter, "AC-DC");
	// x->year = -1;
	// strcpy(x->genre, "\0");
	// x->score = -1;

	// album_list_t *list = getAlbumSortedList(album, x);
	// printAlbumList(list);
	// saveFilteredAlbumList(list, "/home/mtar/Documents/skola/s2/PC2M/C10/output/filtered_databaze_save.csv");
