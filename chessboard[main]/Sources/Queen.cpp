#include "Queen.h"

//Queen::Queen(char kind, int team ): Figure(kind, team){};
//Queen::~Queen(){};


bool Queen::isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) {
    Rook RookMove(kind, team);
    Bishop BishopMove(kind, team);

    // Thanks to inheritance from Rook and Bishop - less code
    return RookMove.isMoveValid(startX, startY, endX, endY, board) ||
           BishopMove.isMoveValid(startX, startY, endX, endY, board);
}
