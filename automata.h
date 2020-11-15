//header file for automata.c
#ifndef AUTOMATA_H_
#define AUTOMATA_H_

bool determineNewCell(bool left, bool mid, bool right, bool ruleset[]);

int printCells(bool cells[], int width);

void generateAutomata();

#endif