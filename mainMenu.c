#include <stdbool.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "automata.h"


//function used to receive an integer input  from the user
int getInt(char prompt[])
{
	int input;
	printf("%s", prompt);
	scanf("%d", &input);
	return input;
}

//function to find the length of a string
int findLength(char str[])
{
	int n;
	//increment n until the nth char is the null character
	while (str[n] != '\0')
		n++;

	return n;
}

int main()
{
	int width;
	int length;

	int rulesetInt = -1;
	bool ruleset[8];

	char filename[255];

	//receive width from user
	while (width < 10 || width > 30)
	{
		width = getInt("Enter the width for the cell generations (between 10-30)\n");
		if (width < 10 || width >30)
		{
			printf("Please enter a valid number\n");
		}
	}

	//receive length from user
	while (length < 5 || length > 30)
	{
		length = getInt("Enter the number of generations to produce (between 5-30)\n");
		if (length < 5 || length >30)
		{
			printf("Please enter a valid number\n");
		}
	}

	//variables for storing the first generation asa string and as an array of bools
	char fgenStr[width];
	bool fgen[width];
	//variables to check if the input is valid
	bool isValidStr = false;
	bool isValidLength = false;


	//get first generation from user
	//needs input validation - can't be more characters than width
	do
	{
		do
		{
			printf("Enter the first generation of cells (x for alive, - for dead)\n");
			scanf("%s", fgenStr);
			//check length of string matches the specified length
			char strLength = findLength(fgenStr);
			if (strLength != width)
			{
				printf("Your input did not match the width you gave\n");
				//reset the while loop and ask the user for input again
				continue;
			}	

			isValidLength = true;	
		} while (!isValidLength);

		
			//check if input string is valid
			//Convert first generation from string to bool array
			for (int i = 0; i < width; i++)
			{
				if (fgenStr[i] == 'x')
				{
					//fgen[i] = true;
					isValidStr = true;

				}
				else if (fgenStr[i] == '-')
				{
					//fgen[i] = false;
					isValidStr = true;
				}
				else
				{
					printf("Your input contained an invalid character\n");
					isValidStr = false;
				}

				//break from the loop if there was an invalid character
				if(!isValidStr)
					break;
			}

	} while (!isValidStr);

	//Convert first generation from string to bool array
	for (int i = 0; i < width; i++)
	{
		if (fgenStr[i] == 'x')
		{
			fgen[i] = true;
		}
		else
		{
			fgen[i] = false;
		}
	}

	//Get ruleset from user as a decimal
	while (rulesetInt < 0 || rulesetInt > 255)
	{
		rulesetInt = getInt("Enter the ruleset to use(between 0-255)\n");
		if (rulesetInt < 0 || rulesetInt > 255)
		{
			printf("Please enter a valid number\n");
		}
	}

	//Convert to binary
	int temp = rulesetInt;
	int start = 128;
	for (int i = 0; i < 8; i++)
	{
		if (temp >= start)
		{
			temp -= start;
			ruleset[i] = true;
		}
		else
		{
			ruleset[i] = false;
		}
		start /= 2;
	}

	//Get filename from user
	printf("Enter the filename to save the automaton to, DO NOT INCLUDE A FILE EXTENSION\n");
	scanf("%s", filename);
	strcpy(filename, strcat(filename, ".txt"));

	//generate automaton using provided values
	generateAutomata(width, length, fgen, ruleset, filename);
	return 0;
}

