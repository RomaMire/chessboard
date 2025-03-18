#ifndef KING_H
#define KING_H

#include "Figure.h"

class King : public Figure
{
private:
     bool wasChecked = false;

public:
    King(char kind, int team);
    ~King();

    // check if king was in check - castling possibility
    bool wasInCheck();
    void setChecked();

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // KING_H
