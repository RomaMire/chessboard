#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"

#include "Rook.h"
#include "Bishop.h"

/**
 * @brief The Queen class represents the queen piece in a chess game.
 *
 * This class combines the movement logic of both the rook and the bishop,
 * allowing the queen to move in straight lines (horizontally and vertically)
 * and diagonally without limitation in distance, as long as the path is clear.
 */

/*



//***************************  version with composition

//class Queen : public Figure
//{

//public:

    /**
     * @brief Constructor for the Queen class.
     * @param kind Character representing the type of figure ('Q' for Queen).
     * @param team The team of the queen (1 for white, 2 for black).
     */
  //  Queen(char kind, int team) : Figure(kind, team) {}
    /**
     * @brief Destructor for the Queen class.
     */
    //~Queen() override {}

    /**
     * @brief Determines if the queen's move is valid.
     *
     * The move is considered valid if it matches either a rook's or bishop's movement pattern,
     * and if the path to the destination is not blocked by other figure.
     *
     * @param startX Starting row index.
     * @param startY Starting column index.
     * @param endX Destination row index.
     * @param endY Destination column index.
     * @param board The current state of the board.
     * @return true if the move is valid, false otherwise.
     */

  // bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
//};

//***************************  version with inheritance


class Queen : public Rook, Bishop{


public:
    Queen (char kind, int team);

    ~Queen() override;


    bool isMoveValid(int startX, int startY, int endX, int endY, Figure * board[8][8]) override;


};


#endif // QUEEN_H
