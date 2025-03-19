#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"

class Bishop: public Figure
{
public:
    Bishop(char kind, int team);
    ~Bishop();

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // BISHOP_H
