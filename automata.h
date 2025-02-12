//header file for automata.c
#ifndef AUTOMATA_H_
#define AUTOMATA_H_

bool determineNewCell(bool left, bool mid, bool right, bool ruleset[]);

int printCells(bool cells[], int width);

int saveCells(bool cells[], int width, char filename[]);

void generateAutomata(int width, int length, bool fgen[], bool ruleset[], char filename[]);

#endif