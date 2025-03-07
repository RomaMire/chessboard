#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"


class Pawn : public Figure{

public:
    Pawn(char kind, int team);
    ~Pawn();
};


#endif // PAWN_H
