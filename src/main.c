#include <stdio.h>
#include "board.h"

int main(void)
{
    Board board;
    board.size = HEIGHT * WIDTH;

    fillCells(&board);
    shuffleCells(&board);
    drawBoard(&board);

    return 0;
}