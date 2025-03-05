#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "board.h"

void fillCells(Board *board)
{
    unsigned int num = 1;
    for (int i = 0; i < board->size; ++i)
    {
        board->cells[i] = num;
        if (num >= 9)
        {
            num = 1;
            continue;
        }

        num += 1;
    }
}

void fillCell(Board *board, unsigned int column, unsigned int row);

bool isValidCellPosition(Board *board, unsigned int column, unsigned int row);

bool isValidCellIndex(Board *board, unsigned int index)
{
    if (index > sizeof(board->size))
    {
        return false;
    }

    return true;
}

void drawBoard(Board *board)
{
    for (int i = 0; i < board->size; ++i)
    {
        if (i % 9 == 0 && i > 0)
        {
            printf("\n");
        }

        if (board->cells[i] == 0)
        {
            printf(" - ");
        }
        else
        {
            printf(" %d ", board->cells[i]);
        }
    }
    printf("\n");
}

void shuffleCells(Board *board)
{
    unsigned int seed = time(0);

    for (int i = 0; i < board->size; ++i)
    {
        int max = board->size;
        int min = 0;
        int ind = rand_r(&seed) % (max - min + 1) + min;

        if (!isValidCellIndex(board, ind))
        {
            printf("Invalid random index: %d\n", ind);

            exit(-1);
        }

        if (!isValidCellIndex(board, i))
        {
            printf("Invalid index: %d\n", i);

            exit(-1);
        }

        swapCells(board, ind, i);
        // int cellNum = board->cells[ind];

        // board->cells[ind] = board->cells[i];

        // board->cells[ind] = cellNum;
    }
}

void swapCells(Board *board, unsigned int indOne, unsigned int indTwo)
{
    int cellNum = board->cells[indOne];
    board->cells[indOne] = board->cells[indTwo];
    board->cells[indOne] = cellNum;
}