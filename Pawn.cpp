#include "Pawn.h"
#include "Figure.h"

//#include<iostream>
//using namespace std;

Pawn::Pawn(char kind, int team): Figure(kind, team) {};
Pawn::~Pawn(){};


bool Pawn::isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) {
    int direction = (team == 0) ? 1 : -1; //direction up or down

    // one forward
    if (startY == endY && endX == startX + direction && board[endX][endY] == nullptr) {//move on the same column (startY == endY)
        return true;
    }

    // two forward - only first move //(team == 0 ? 1 : 6) define the rows of pawns, then thanks to direction make correct move
    if (startY == endY && startX == (team == 0 ? 1 : 6) && endX == startX + 2 * direction && board[endX][endY] == nullptr) {
        return true;
    }
    //diagonal attack
    if (abs(startY - endY) == 1 && endX == startX + direction && board[endX][endY] != nullptr && board[endX][endY]->showTeam() != team) {
        return true;
    }

    return false;

}
