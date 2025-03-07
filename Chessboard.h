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
};

#endif // CHESSBOARD_H
