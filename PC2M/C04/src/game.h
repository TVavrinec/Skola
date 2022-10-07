#define PI 3.14159265		// predefined pi
#define G 9.81				// predefined acceleration of gravity

void game()
{
	char disp[31][76];
	char c;
	float y[76];
	int ele;				// angle of elevation in degrees
	int vel;				// velocity in m/s
	int x, m, n, yv, tar[2], test=0, count=0;

	srand(time(NULL));
	tar[0]=rand()%10+60;
	tar[1]=rand()%16+10;
	ele=rand()%30+40;
	vel=rand()%30+15;

	while (test==0)
	{

		do
		{
			printf("\rAngle: %3d deg., velocity: %3dm/s  ",ele, vel);
			c=getchar();
			switch(c)
			{
				case 'q': ele++; break;
				case 'a': ele--; break;
				case 'w': vel++; break;
				case 's': vel--; break;
			}
			if (ele>80) ele=80;
			if (ele<5) ele=5;
			if (vel>100) vel=100;
			if (vel<1)	vel=1;
		}
		while (c!='c');
		for (n=0; n<76; n++)
				printf("-");
		system ("cls");
		printf("\rAngle: %3d deg., velocity: %3dm/s  \n",ele, vel);
		count++;
		for (m=0; m<31; m++)
			for (n=0; n<76; n++)
				disp[m][n]=' ';
		disp[tar[1]][tar[0]]='X';

		for (x=0; x<76; x++)
		{
			y[x] = x*(tan(ele*(PI/180)))-G*pow(x,2)*pow((1/(vel*cos(ele*(PI/180)))),2)/2;
			yv=(float)((int)(y[x]+0.5));
			if ((yv>=0)&&(yv<=30))
			{
				disp[30-yv][x]='O';
				if ((x==tar[0])&&((30-yv)==tar[1]))
						test=1;
			}
		}
		printf("\n");
		for (n=0; n<76; n++)
			printf("-");
		if (test==1)
		{
			printf("\n!!!BLACK HOWK DONE - URRRAAA!!! YOU NEEDED %d SHOTS\n", count);
			for (n=-2;n<=2;n++)
			{
				disp[tar[1]+n][tar[0]]='+';
				disp[tar[1]][tar[0]+n]='+';
				disp[tar[1]+n][tar[0]+n]='+';
				disp[tar[1]+n][tar[0]-n]='+';
			}
			for (n=0; n<76; n++)
			printf("-");
		}
		printf("\n");
		for (m=0; m<31; m++)
		{
			for (n=0; n<76; n++)
				printf("%c", disp[m][n]);
			printf("\n");
		}
		for (n=0; n<76; n++)
			printf("-");
		printf("\n");
	}
	printf("\nPress SPACE + ENTER\n");
	do
		c=getchar();
	while (c!=' ');
}