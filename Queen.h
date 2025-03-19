#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"

#include "Rook.h"
#include "Bishop.h"

class Queen : public Figure
{

public:
    Queen(char kind, int team) : Figure(kind, team) {}  // Konstruktor królowej

    ~Queen() override {}

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // QUEEN_H
