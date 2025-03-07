#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"

class Knight: public Figure
{
public:
    Knight(char kind, int team);
    ~Knight();
};

#endif // KNIGHT_H
