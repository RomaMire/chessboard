#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"

class Rook : public Figure
{
public:
    Rook(char kind, int team);
    ~Rook();
};

#endif // ROOK_H
