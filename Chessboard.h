#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>

#include "Figure.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"

using namespace std;


class Chessboard
{
protected:
    Figure* Board [8][8];

public:
    Chessboard();
    ~Chessboard();

    void showChessboard();
    void addArmy();

    bool moveFigure(int startX, int startY, int endX, int endY);

    bool isCheck(int kingX, int kingY, Figure* board[8][8], int team);
};

#endif // CHESSBOARD_H
