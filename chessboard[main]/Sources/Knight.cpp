#include "Knight.h"

Knight::Knight(char kind, int team ): Figure(kind, team) {}
Knight::~Knight(){};


bool Knight::isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) {

    int distanceX = abs(endX - startX);
    int distanceY = abs(endY - startY);

    // Check if L shape movement
    if (!((distanceX == 2 && distanceY == 1) || (distanceX == 1 && distanceY == 2))) {
        return false;
    }

    // Check if target field is empty or occupied by enemy
    return (board[endX][endY] == nullptr || board[endX][endY]->showTeam() != team);
}
