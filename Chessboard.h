#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include <functional>//send message to the textConsole GUI
#include <Qstring> // comunication Qt

#include "Figure.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"

/**
 * @class Chessboard
 * @brief Manages the state and logic of the chessboard.
 *
 * The Chessboard class handles all game logic including moving figures,
 * detecting check and checkmate conditions, castling, and communication with the GUI information bar.
 */

using namespace std;


class Chessboard
{
private:


    int currentTurn = 1; //switch the turn
    /**
     * @brief 2D array representing the chessboard (8x8).
     */

    Figure* Board [8][8];

    /**
     * @brief Current position of the white king.
     */

    int whiteKingX, whiteKingY; //white king position
    int blackKingX, blackKingY; //black king position

protected:

    /**
     * @brief Type definition for logging lext function used by the GUI.
     */

    using LoggerFunc = std::function<void(const QString&)>;
    LoggerFunc logger = nullptr;  // default nullptr

    /**
     * @brief Sends a log message to the GUI or console.
     * @param msg The message to be logged.
     */
    void log(const QString& msg);//



public:

    /**
     * @brief Constructs the chessboard and initializes the board.
     */

    Chessboard();

    /**
     * @brief Destructor for cleaning up allocated figures.
     */

    ~Chessboard();

    /**
     * @brief Displays the current state of the board in the console.
     */
    void showChessboard();
    /**
     * @brief Adds the default white and black figures to the board.
     */

    void addArmy();
    /**
     * @brief Attempts to move a figure from one position to another.
     * @param startX The starting row of the figure.
     * @param startY The starting column of the figure.
     * @param endX The destination row.
     * @param endY The destination column.
     * @return True if the move was successful, false otherwise.
     */
    bool moveFigure(int startX, int startY, int endX, int endY);
    /**
     * @brief Updates the current positions of both kings.
     */
    void checkKingPosition();// Search king's position
    /**
     * @brief Checks if a given team's king is in check.
     * @param team The team to check (1 for white, 2 for black).
     * @param silent If true, suppress logging.
     * @return True if the king is in check, false otherwise.
     */

    bool isKingInCheck(int team, bool silent = false) ;//Check if the king is in check

    /**
     * @brief Checks whether the specified team is in checkmate.
     * @param team The team to check (1 for white, 2 for black).
     * @return True if the team is checkmated, false otherwise.
     */
    bool isCheckmate(int team);


    //method for castling move

    /**
     * @brief Determines if castling is allowed between the given king and rook positions.
     * @param kingX Row position of the king.
     * @param kingY Column position of the king.
     * @param rookX Row position of the rook.
     * @param rookY Column position of the rook.
     * @return True if castling is allowed, false otherwise.
     */
    bool isToCastle(int kingX, int kingY, int rookX, int rookY);
   //method for GUI

    /**
     * @brief Returns a pointer to the board for GUI rendering.
     * @return A pointer to the 2D array of figures.
     */
   Figure* (*getBoard())[8];// GUI will take and assign the figure png thanks to this


   /**
     * @brief Sets the logger callback to allow messages to be passed to the GUI.
     * @param func The function used to send log messages.
     */

   // set logger with GUI (MainWindow)
   void setLogger(LoggerFunc func);

};

#endif // CHESSBOARD_H
