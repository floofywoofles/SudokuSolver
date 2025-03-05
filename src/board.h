#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define HEIGHT 9
#define WIDTH 9

typedef struct
{
    unsigned int cells[HEIGHT * WIDTH];
    unsigned int size;
} Board;

void fillCells(Board *board);
void fillCell(Board *board, unsigned int column, unsigned int row);
bool isValidCellPosition(Board *board, unsigned int column, unsigned int row);
bool isValidCellIndex(Board *board, unsigned int index);
void drawBoard(Board *board);
void shuffleCells(Board *board);
void swapCells(Board *board, unsigned int indOne, unsigned int indTwo);

#endif