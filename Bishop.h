#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"

class Bishop: public Figure
{
public:
    Bishop(char kind, int team);
    ~Bishop();
};

#endif // BISHOP_H
