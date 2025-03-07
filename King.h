#ifndef KING_H
#define KING_H

#include "Figure.h"

class King : public Figure
{
public:
    King(char kind, int team);
    ~King();
};

#endif // KING_H
