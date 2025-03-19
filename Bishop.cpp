#include "Bishop.h"

Bishop::Bishop(char kind, int team ): Figure(kind, team){};
Bishop::~Bishop(){};


bool Bishop::isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) {
    int diagonalX = abs(endX - startX);
    int diagonalY = abs(endY - startY);

    // Check if the amount of fields in both diagonals are equal
    if (diagonalX != diagonalY) {
        return false;
    }

    // Check if there is other figure on the way
    int directionX = (endX < startX) ? -1 : 1; //move up or down
    int directionY = (endY < startY) ? -1 : 1; //move left or right

    for (int i = startX + directionX, j = startY + directionY; i != endX; i += directionX, j += directionY) {
        if (board[i][j] != nullptr) {
            return false;  // There is other figure on the way
        }
    }


    return board[endX][endY] == nullptr || board[endX][endY]->showTeam() != team;// The target field can be empty or occupied by enemy
}
