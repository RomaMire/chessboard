#include "Chessboard.h"



void Chessboard:: showChessboard(){
    for (int i=0;i<8;i++){

        for(int j=0;j<8;j++){
             cout<<Chessboard[i][j].showKind()<<"  ";
            // cout<<Chessboard[i][j].showTeam()<<"  ";
        }
        cout<<endl;
    };
}

void Chessboard::addArmy(){

    King WhiteKing;
    WhiteKing.setKind('K');
    WhiteKing.setTeam(1);

    Queen WhiteQueen;
    WhiteQueen.setKind('Q');
    WhiteQueen.setTeam(1);

    Bishop WhiteBishop;
    WhiteBishop.setKind('B');
    WhiteBishop.setTeam(1);

    Knight WhiteKnight;
    WhiteKnight.setKind('K');
    WhiteKnight.setTeam(1);

    Rook WhiteRook;
    WhiteRook.setKind('R');
    WhiteRook.setTeam(1);

    Pawn WhitePawn;
    WhitePawn.setKind('P');
    WhitePawn.setTeam(1);

//*************************Black

    King BlackKing;
    BlackKing.setKind('K');
    BlackKing.setTeam(2);

    Queen BlackQueen;
    BlackQueen.setKind('Q');
    BlackQueen.setTeam(2);

    Bishop BlackBishop;
    BlackBishop.setKind('B');
    BlackBishop.setTeam(2);

    Knight BlackKnight;
    BlackKnight.setKind('K');
    BlackKnight.setTeam(2);

    Rook BlackRook;
    BlackRook.setKind('R');
    BlackRook.setTeam(2);

    Pawn BlackPawn;
    BlackPawn.setKind('P');
    BlackPawn.setTeam(2);


    for (int i=1;i<2;i++){

        for(int j=0;j<8;j++){
            Chessboard[i][j]= BlackPawn;

            //cout<<Chessboard[i][j].showTeam()<<"  ";
        }
        cout<<endl;
    };

    for (int i=6;i<7;i++){

        for(int j=0;j<8;j++){
            Chessboard[i][j] =  WhitePawn;

            //cout<<Chessboard[i][j].showTeam()<<"  ";
        }
        cout<<endl;


    };

    Chessboard[0][0] = BlackRook;
    Chessboard[0][7] = BlackRook;
    Chessboard[7][0] = WhiteRook;
    Chessboard[7][7] = WhiteRook;

    Chessboard[0][3] =  BlackQueen;
    Chessboard[7][3] =  WhiteQueen;

    Chessboard[0][4] =  BlackKing;
    Chessboard[7][4] =  WhiteKing;

    Chessboard[0][2] = BlackBishop;
    Chessboard[0][5] = BlackBishop;
    Chessboard[7][2] = WhiteBishop;
    Chessboard[7][5] = WhiteBishop;

    Chessboard[0][1] = BlackKnight;
    Chessboard[0][6] = BlackKnight;
    Chessboard[7][1] = WhiteKnight;
    Chessboard[7][6] = WhiteKnight;


}
//void Chessboard::


