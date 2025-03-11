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

    int whiteKingX, whiteKingY; //white king position
    int blackKingX, blackKingY; //black king position

public:
    Chessboard();
    ~Chessboard();

    void showChessboard();
    void addArmy();

    bool moveFigure(int startX, int startY, int endX, int endY);


    void checkKingPosition();// Search king's position


    bool isKingInCheck(int team) ;//Check if the king is in check

    bool isCheckmate(int team);
};

#endif // CHESSBOARD_H
