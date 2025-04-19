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



using namespace std;


class Chessboard
{
protected:
    Figure* Board [8][8];

    int whiteKingX, whiteKingY; //white king position
    int blackKingX, blackKingY; //black king position

    using LoggerFunc = std::function<void(const QString&)>;
    LoggerFunc logger = nullptr;  // domyślnie brak
    void log(const QString& msg);//

public:
    Chessboard();
    ~Chessboard();

    void showChessboard();
    void addArmy();
    bool moveFigure(int startX, int startY, int endX, int endY);
    void checkKingPosition();// Search king's position
    bool isKingInCheck(int team, bool silent = false) ;//Check if the king is in check
    bool isCheckmate(int team);
    //method for castling move
   bool isToCastle(int kingX, int kingY, int rookX, int rookY);
   //method for GUI
   Figure* (*getBoard())[8];// GUI will take and assign the figure png thanks to this




   // set logger with GUI (MainWindow)
   void setLogger(LoggerFunc func);

};

#endif // CHESSBOARD_H
