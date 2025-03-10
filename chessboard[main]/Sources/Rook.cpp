#include "Rook.h"
//#include "Figure.h"

//#include<iostream>
//using namespace std;

Rook::Rook(char kind, int team ): Figure(kind, team){};
Rook::~Rook(){};


bool Rook::isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) {
    // Move is correct if is vertical or horizontal, never both
    if (startX != endX && startY != endY) {
        return false;
    }

    // Check if there is only empty fields on the way
    if (startX == endX) {  // vertical move
        int direction = (endY > startY) ? 1 : -1;
        for (int j = startY + direction; j != endY; j += direction) {
            if (board[startX][j] != nullptr) {
                return false;  // An obstacle on the way
            }
        }
    } else {  // horizontal move
        int direction = (endX > startX) ? 1 : -1;
        for (int i = startX + direction; i != endX; i += direction) {
            if (board[i][startY] != nullptr) {
                return false;  // An obstacle on the way
            }
        }
    }

    // Target field can be empty or ocuppied by enemy
    return board[endX][endY] == nullptr || board[endX][endY]->showTeam() != team;
}
