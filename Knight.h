#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"

/**
 * @brief The Knight class represents the Knight (Horse) chess piece.
 *
 * Inherits from the Figure base class and implements the unique L-shaped movement rules.
 */

class Knight: public Figure
{
public:

    /**
     * @brief Constructs a Knight object with the given kind and team.
     * @param kind Character representing the figure kind ('H').
     * @param team The team number (1 for white, 2 for black).
     */
    Knight(char kind, int team);

    /**
     * @brief Destructor for Knight.
     */
    ~Knight();

    /**
     * @brief Validates whether the Knight can legally move to the specified position.
     *
     * The Knight moves in an L-shape: two squares in one direction and one square perpendicular.
     * It can jump over other pieces and can attack enemy pieces at the destination.
     *
     * @param startX Current row of the Knight.
     * @param startY Current column of the Knight.
     * @param endX Target row.
     * @param endY Target column.
     * @param board The current state of the chessboard.
     * @return True if the move is valid; otherwise false.
     */

     bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};



#endif // KNIGHT_H
