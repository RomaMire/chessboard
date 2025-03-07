#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"

class Queen : public Figure
{

public:
    Queen(char kind, int team);
    ~Queen();
};

#endif // QUEEN_H
