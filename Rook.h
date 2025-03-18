#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"

class Rook : public Figure
{
public:
    Rook(char kind, int team);
    ~Rook();

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // ROOK_H
