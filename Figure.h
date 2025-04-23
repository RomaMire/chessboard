#ifndef FIGURE_H
#define FIGURE_H


#include<iostream>
using namespace std;
/**
 * @class Figure
 * @brief Abstract base class representing a chess figure.
 *
 * Provides a generic interface for all chess pieces, including
 * shared properties like team and movement status. Derived classes must implement
 * their own movement logic using the pure virtual method `isMoveValid`.
 */
class Figure
{
protected:
    /**
     * @brief Character symbol representing the type of the figure (e.g., 'P' for Pawn, 'K' for King).
     */
    char kind {'*'};


    /**
     * @brief Team to which the figure belongs: 1 for white, 2 for black.
     */
    int team {0};// 1-white 2-black


    /**
     * @brief Indicates whether the figure has already moved (used for castling and pawn logic).
     */
    bool wasMoved = false;


public:

    /**
     * @brief Constructor for initializing a figure.
     * @param kind Character symbol representing the figure.
     * @param team Team of the figure (1 = white, 2 = black).
     */
    Figure(char kind, int team);
    /**
     * @brief Virtual destructor.
     */
    virtual ~Figure();
    /**
     * @brief Returns the character representing the kind of figure.
     * @return The figure's kind symbol (e.g., 'P', 'K').
     */

    char showKind();
    /**
     * @brief Returns the team the figure belongs to.
     * @return The team number (1 = white, 2 = black).
     */
    int showTeam();



    //void move();

    //castling

    /**
     * @brief Checks whether the figure has already moved.
     * @return True if the figure has moved at least once, false otherwise.
     */
    bool hasMoved();
    /**
     * @brief Marks the figure as having moved.
     */
    void setMove();

   // bool isMoveValid();
    /**
     * @brief Pure virtual method to validate movement for specific figure types.
     *
     * Each subclass must implement this method to define its own movement rules.
     *
     * @param startX Start row
     * @param startY Start column
     * @param endX End row
     * @param endY End column
     * @param board Current state of the chessboard
     * @return True if the move is valid, false otherwise
     */
    virtual bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) = 0;  // abstract - own rules for each figure

   /* virtual bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]){
        return false;
   }; */




};

#endif // FIGURE_H
