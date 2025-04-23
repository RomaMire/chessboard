#ifndef KING_H
#define KING_H

#include "Figure.h"
/**
 * @brief The King class represents the King piece in chess.
 *
 * Inherits from the abstract Figure class and implements
 * its own movement logic and additional rules such as castling.
 */


class King : public Figure
{
private:

    /**
     * @brief Flag indicating if the King has ever been in check.
     *
     * Used to determine eligibility for castling.
     */


     bool wasChecked = false;
  //  bool wasMoved = false;

public:

     /**
     * @brief Constructs a King object with specified kind and team.
     * @param kind The character representing the kind ('K').
     * @param team The team number (1 for white, 2 for black).
     */
    King(char kind, int team);
    /**
     * @brief Destructor for King.
     */
    ~King();

    // check if king was in check - castling possibility

    /**
     * @brief Checks if the King has previously been in check.
     * @return True if the King was in check; otherwise false.
     */

    bool wasInCheck();
    /**
     * @brief Marks the King as having been in check.
     */


    void setChecked();


   // void setWasMoved();

    /**
     * @brief Validates whether the King can legally move to the specified position.
     *
     * The King can move one square in any direction, provided the target is empty
     * or occupied by an opponent's piece. Castling is handled separately.
     *
     * @param startX Current row position.
     * @param startY Current column position.
     * @param endX Target row position.
     * @param endY Target column position.
     * @param board The current state of the board.
     * @return True if the move is valid; otherwise false.
     */
    bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) override;
};

#endif // KING_H
