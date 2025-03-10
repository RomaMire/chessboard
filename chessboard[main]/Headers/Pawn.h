#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"


class Pawn : public Figure{

public:
    Pawn(char kind, int team);
    ~Pawn();

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};



#endif // PAWN_H
