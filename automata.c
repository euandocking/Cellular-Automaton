#include <stdbool.h> 
#include <stdlib.h>
#include <stdio.h>

/**
 * determines wheather a new cell is true or false based on the previous generation of cells
 * a lot of the elses are redundant just now but they'll be necessary if we want to extend 
 * the method to cover different rules later
 */
bool determineNewCell(bool left, bool mid, bool right)
{
    //if the value to the top left is true
    if (left == true)
    {
        //if the value to the top middle is true
        if (mid == true)
        {
            //if the value to the top right is true
            if (right == true)
            {
                return false;
            }
            //if the value to the top right is false
            else
            {
                return false;
            }
        }
        //if the value to the top middle is false
        else
        {
            //if the value to the top right is true
            if (right == true)
            {
                return false;
            }
            //if the value to the top right is false
            else
            {
                return true;
            }
        }
    }
    //if the value to the top left is false
    else
    {
        //if the value to the top middle is true
        if (mid == true)
        {
            //if the value to the top right is true
            if (right == true)
            {
                return true;
            }
            //if the value to the top right is false
            else
            {
                return true;
            }
        }
        //if the value to the top middle is false
        else
        {
            //if the value to the top right is true
            if (right == true)
            {
                return true;
            }
            //if the value to the top right is false
            else
            {
                return false;
            }
        }
    }
}

/**
 * prints out a generation of cells
 */
int printCells(bool cells[], int width)
{
    //for every cell
    for (int i = 0; i < width; i++)
    {
        //if the cell is true
        if (cells[i] == true)
        {
            //print x
            printf("x");
        }
        //if the cell is false
        else
        {
            //print -
            printf("-");
        }
    }
    //print a new line
    printf("\n");

    return 0;
}

/**
 * main method
 */
void generateAutomata()
{
    //set the width of cell generations
    int width = 31;

    //create the initial generation of cells
    bool cells[width];

    //set every cell to false
    for (int i = 0; i < width; i++)
    {
        cells[i] = false;
    }

    //set one cell to true
    cells[16] = true;

    //print the cells
    printCells(cells, width);

    //create an array for the next generation of cells
    bool newCells[width];

    //repeat 10 times
    for (int i = 0; i < 15; i++)
    {
        //As a note - we probably want to make a function for determining every cell in a generation
        //but I had trouble passing an array by reference

        //determine the first cell
        //the cell to the top left wraps to be the last cell in the generation
        newCells[0] = determineNewCell(cells[width-1], cells[0], cells[1]);

        //determine the cells inbetween the first and last
        for (int i = 1; i < width-1; i++)
        {
            newCells[i] = determineNewCell(cells[i-1], cells[i], cells[i+1]);
        }
      
        //determine the last cell
        //the cell to the top right wraps to be the first cell in the generation
        newCells[width-1] = determineNewCell(cells[width-2], cells[width-1], cells[0]);
        

        //for every cell in the generation
        for (int i = 0; i < width; i++)
        {
            //make the current cell the new cell
            cells[i] = newCells[i];
        }
        //print the cells
        printCells(cells, width);
    }
}