#include <stdbool.h> 
#include <stdlib.h>
#include <stdio.h>
#include "automata.h"

int main()
{
	int width;
	int length;

	int rulesetInt;
	bool ruleset[8];

	char filename[255];

	//receive width from user
	printf("Enter the width for the cell generations\n");
	scanf("%d", &width);

	//receive length from user
	printf("Enter the number of generations to produce\n");
	scanf("%d", &length);

	//variables for storing the first generation asa string and as an array of bools
	char fgenStr[width];
	bool fgen[width];

	//get first generation from user
	//needs input validation - can't be more characters than width
	printf("Enter the first generation of cells (x for alive, - for dead)\n");
	scanf("%s", fgenStr);

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
	//needs input validation - rulesets exist from 0 to 255
	printf("Enter the ruleset to use\n");
	scanf("%d", &rulesetInt);

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
	printf("Enter the filename to save the automaton to\n");
	scanf("%s", filename);

	//generate automaton using provided values
	generateAutomata(width, length, fgen, ruleset, filename);
	return 0;
}

