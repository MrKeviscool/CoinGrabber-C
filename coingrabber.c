#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 
#include <string.h>
int bg[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int screen[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int guy = 7;
int coin = 6;
char keypress = ' ';
int points = 0;
int gameover = 0;
float timetaken;
float high;
void delay(int second)
{
	clock_t secondtimer = clock();
	while (clock() < (secondtimer + second *1000));
}
int main()
{
 	coin = rand() % 9;
	FILE * file;
	file = fopen("C:\\ProgramData\\coingrabberhighC.txt", "a");
	fclose(file);
	file = fopen("C:\\ProgramData\\coingrabberhighC.txt", "r");
	fscanf(file, "%f", &high);
	if (high == 0.000000)
	{
		high = 999.99;
	}
	printf("Coin Grabber by Daniel.S \n");
	printf("do you want to know how to play the game? (y/n): ");
	scanf(" %c", &keypress);
	if (tolower(keypress) == 'y')
	{
		printf("\nyou are the eight (8), your goal is to collect the coins that are zeroes (0) in the fastest time possible."
			"to move you press either 'a' or 'd' and press enter. any other combonations will not move you."
			"if the coin dosent show up than it is under you and you can press enter for a free coin."
			"your points are shown above the map."
			"Good Luck Have Fun!\n");
	}
	start:
	printf("Time to beat: %.3f\n", high);
	printf("Enter to ready: ");
	if(getc(stdin) == '\0' || getc(stdin) =='\n'){}
	printf("\n3");
	delay(1);
	printf("\n2");
	delay(1);
	printf("\n1");
	delay(1);
	printf("\nGOOOO!");
	for (int i = 0; i < 50; i++)
	{
		printf("\n");
	}
	for (int x = 0; x < 9; x++)
	{
		screen[x] = bg[x];
		screen[coin] = 0;
		screen[guy] = 8;
 		printf("%d", screen[x]);
}
 	printf("\n");
	clock_t starttime = clock();
	while (1 == 1)
	{
		if (points != 5)
		{
			scanf(" %c", &keypress);
 			if (tolower(keypress) == 'd' && guy != 8)
			{
				guy++;
			}
 			if (tolower(keypress) == 'a' && guy != 0)
			{
				guy--;
			}
 			if (guy == coin)
			{
				points++;
				coin = rand() % 9;
 			}
			for (int x = 0; x < 9; x++)
			{
				screen[x] = bg[x];
				screen[coin] = 0;
				screen[guy] = 8;
				printf("%d", screen[x]);
			}
			printf("\n");
		}
		else if (gameover != 1)
		{
			clock_t endtime = clock();
			printf("game over!");
			gameover = 1;
			timetaken = endtime - starttime;
			printf("\nTime: %.3f", timetaken / 1000);
			if(timetaken / 1000 < high){
				high = timetaken / 1000; 
				fclose(file);
				file = fopen("C:\\ProgramData\\coingrabberhighC.txt", "w");
				fprintf(file, "%.3f", timetaken / 1000);
			}
			printf("\nHigh: %.3f", high);
			fclose(file);
			/*
			HELP PLS:
			printf("\nPlay again? (y/n): ");
			scanf(" %c", &keypress);
			
			if(tolower(keypress) == 'y'){
				file = fopen("C:\\ProgramData\\coingrabberhighC.txt", "r");
				goto start;
			}
			else{
				return 0;
			}
			*/
	   }
 	}
}
