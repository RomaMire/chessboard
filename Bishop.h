#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"

/**
 * @class Bishop
 * @brief Represents a Bishop chess figure.
 *
 * The Bishop class defines the movement rules and behavior for the bishop figure
 * in a chess game. It inherits from the abstract Figure class.
 */

/**
     * @brief "virtaual" was added because of the mltiple inheritane in Queen class

     */


class Bishop: public virtual Figure
{
public:
    /**
     * @brief Constructs a Bishop object.
     *
     * @param kind The character symbol representing the piece ( 'B').
     * @param team The team the piece belongs to (1 for white, 2 for black).
     */
    Bishop(char kind, int team);


    /**
     * @brief Destroys the Bishop object.
     */

    ~Bishop();

    /**
     * @brief Validates the bishop's move according to chess rules.
     *
     * @param startX The starting row of the bishop.
     * @param startY The starting column of the bishop.
     * @param endX The destination row of the bishop.
     * @param endY The destination column of the bishop.
     * @param board The current state of the chessboard.
     * @return true if the move is valid, false otherwise.
     */

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // BISHOP_H
