#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"

/**
 * @brief The Rook class represents a rook piece in a chess game.
 *
 * The rook can move any number of squares along a row or column,
 * as long as the path is not blocked by another piece.
 */

class Rook : public Figure

/**
     * @brief Constructor for the Rook class.
     * @param kind Character representing the type of figure ('R' for Rook).
     * @param team The team of the rook (1 for white, 2 for black).
     */
{
public:

    /**
     * @brief Constructor for the Rook class.
     * @param kind Character representing the type of figure ('R' for Rook).
     * @param team The team of the rook (1 for white, 2 for black).
     */

    Rook(char kind, int team);

    /**
     * @brief Destructor for the Rook class.
     */
    ~Rook();



    /**
     * @brief Checks whether a rook's move is valid.
     *
     * The rook can move only in straight lines (horizontal or vertical)
     * and cannot jump over other pieces.
     *
     * @param startX Starting row index.
     * @param startY Starting column index.
     * @param endX Destination row index.
     * @param endY Destination column index.
     * @param board The current state of the board.
     * @return true if the move is valid, false otherwise.
     */
    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // ROOK_H
