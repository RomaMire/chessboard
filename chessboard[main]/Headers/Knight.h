#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"

class Knight: public Figure
{
public:
    Knight(char kind, int team);
    ~Knight();

     bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};



#endif // KNIGHT_H
