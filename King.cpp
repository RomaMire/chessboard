#include "King.h"

King::King(char kind, int team ): Figure(kind, team){};
King::~King(){};



bool King::isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) {
    int distanceX = abs(endX - startX);
    int distanceY = abs(endY - startY);

    // Only one field to move
    if (distanceX > 1 || distanceY > 1) {
        return false;
    }

    // Target field can be empty or occupied by the enemy figure
    if (board[endX][endY] != nullptr && board[endX][endY]->showTeam() == team) {
        return false;
    }

    return true;
}
