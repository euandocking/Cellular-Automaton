#include <stdbool.h> 
#include <stdlib.h>
#include <stdio.h>
#include "automata.h"

/*
Declaring functions
*/
void displayMenu();

void processChoice();


int main()
{
	displayMenu();
	return 0;
}

/*
Displays the menu to the user
*/
void displayMenu()
{
	//display the options
	printf("Main Menu:\n1. Generate Cellular Automaton\n2. option 2\n3. option 3\n4. Exit\n");
	//call the function to process user input
	processChoice();
}

/*
Asks the user for an input and processes their choice
*/
void processChoice()
{
	int choice;//vairable storing the user's choice

	printf("Please enter your choice\n");
	scanf("%d", &choice);
		
	switch(choice)
	{
		case 1://Generate cellular automata
			generateAutomata();
			displayMenu();
			break;
		case 2://placeholder option
			printf("Not implemented\n");
			displayMenu();
			break;
		case 3://placeholder option
			printf("Not implemented\n");
			displayMenu();
			break;
		case 4://Exit the program
			printf("Goodbye.\n");
			break;
		default://default case, handling invalid user input
			printf("Invalid selection\n");
			displayMenu();
			break;
		}
	
}

