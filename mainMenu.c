#include <stdbool.h> 
#include <stdlib.h>
#include <stdio.h>
#include "automata.h"

void processChoice();

int main()
{
	processChoice();
	return 0;
}

/*
Asks the user for an input and processes their choice
*/
void processChoice()
{
	int choice = -1;//vairable storing the user's choice

	int width = 30;
	int length = 10;

	while (choice != 0)
	{
		//display current settings
		printf("Current settings:\nWidth:%d\nLength:%d\n", width, length);

		//display the options
		printf("Main Menu:\n1. Generate Cellular Automaton\n2. Set Width\n3. Set Length\n0. Exit\n");
		printf("Please enter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1://Generate cellular automata
				generateAutomata(width, length);
				break;
			case 2://Set width
				printf("Enter the width for the cell generations\n");
				scanf("%d", &width);
				break;
			case 3://Set length
				printf("Enter the number of generations to produce\n");
				scanf("%d", &length);
				break;
			case 0://Exit the program
				printf("Goodbye.\n");
				break;
			default://default case, handling invalid user input
				printf("Invalid selection\n");
				break;
		}
	}
}

