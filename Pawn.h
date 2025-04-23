#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"
/**
 * @brief The Pawn class represents a pawn piece in a chess game.
 *
 * This class implements the movement logic specific to pawns,
 * including single-step forward movement, initial double-step,
 * and diagonal capture.
 */

class Pawn : public Figure{

public:

    /**
     * @brief Constructor for the Pawn class.
     * @param kind Character representing the type of figure ('P' for Pawn).
     * @param team The team of the pawn (1 for white, 2 for black).
     */
    Pawn(char kind, int team);

    /**
     * @brief Destructor for the Pawn class.
     */
    ~Pawn();

    /**
     * @brief Determines if the pawn's move is valid.
     *
     * This method checks for the correct forward movement, initial two-square move,
     * and diagonal capture of enemy pieces.
     *
     * @param startX Starting row index.
     * @param startY Starting column index.
     * @param endX Destination row index.
     * @param endY Destination column index.
     * @param board Current state of the board.
     * @return true if the move is valid according to pawn rules, false otherwise.
     */

    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};



#endif // PAWN_H
