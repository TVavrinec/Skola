#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define MAX_WORLD_COUNT 64
#define MAX_WORLD_LENGTH 20

char stext1[20]="AKEQYHUQOTTSQT";
char stext2[]="TQJHKSHYMMTTSR";	

int main()
{
	// 00000000000000000000000000000000000000000000000000000
	strcat(stext1,stext2);
	printf("concatenation: \n %s\n\n", stext1);
	// 11111111111111111111111111-22222222222222222222222222
	for (int a = 0; a < (int)strlen(stext1); a++)
		switch (stext1[a])
		{
			case 'Q':	stext1[a]='D';	break;
			case 'T':	stext1[a]='C';	break;
			case 'Z':	stext1[a]='A';	break;		
			default:	stext1[a]++	 ;	break;
		}
	printf("Replacement 'Q'=>'C', 'T'=>'B' and shift up in ASCII table: \n%s\n\n", stext1);
	// 33333333333333333333333333333333333333333333333333333
	while(strstr(stext1,"CC"))
		strncpy(strstr(stext1,"CC"),"RM",2);
	printf("Replacement \"CC\"=>\"RM\" %s\n\n", stext1);	
	// 44444444444444444444444444444444444444444444444444444
	for (int a = 0; a < (int)strlen(stext1); a++)
		stext1[a] += 25-2*((int) stext1[a]-65);
	printf("Rotation in ASCII table:\n %s\n\n", stext1);
	// 55555555555555555555555555555555555555555555555555555
	for (int a = 1; a < (int)strlen(stext1); a++)
		stext1[a] += 32;
	printf("Replacement CAPITAL=>smal\n %s\n\n", stext1);
	// 66666666666666666666666666666666666666666666666666666
	for (int a = 0; a < (int)strlen(stext1); a++)
		switch (stext1[a])
		{
			case 'w':	stext1[a]=' ';	break;
			case 'h':	stext1[a]='.';	break;
			default:	break;
		}
	printf("Replacement 'w'=>' ' and 'h'=>',' \n%s\n", stext1);

	// +++++++++++++++++++++++++++++++++++++++++++++++++++++
	printf("********************************************************************\nGet text to encrypt\n");
	char *text = malloc(256);
	fgets(text, 256, stdin);
	printf("\nI go to encrypt text:\n%s\n", text);
	for (int a = 0; a < (int)strlen(text)-1; a++)
	{
		switch (text[a])
		{
			case ' ':	text[a]='w';	break;
			case '.':	text[a]='h';	break;
			default:	break;
		}
		if(a!=0)	text[a] -= 32;
		text[a] -= 25+2*((int) text[a]-90);
		if((text[a-1]=='Q')&&(text[a]=='M'))	strncpy(&text[a-1],"TC",2);
		switch (text[a])
		{
			case 'D':	text[a]='Q';	break;
			case 'C':	text[a]='T';	break;
			case 'A':	text[a]='Z';	break;		
			default:	text[a]--  ;	break;
		}
	}
	printf("\nEncrypt text is:\n%s\n", text);


	return (0);
}