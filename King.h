#ifndef KING_H
#define KING_H

#include "Figure.h"

class King : public Figure
{
public:
    King(char kind, int team);
    ~King();

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // KING_H
