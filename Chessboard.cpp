#include "Chessboard.h"


Chessboard::Chessboard(){
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
            Board[i][j] = new Figure('*',0);

        }
    }
}

Chessboard::~Chessboard(){
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
           delete Board[i][j];
        }
    }
}




void Chessboard::addArmy(){


    for (int i=1;i<2;i++){

        for(int j=0;j<8;j++){
            Board[i][j]= new Pawn('P',2);
        }
        cout<<endl;
    };

    for (int i=6;i<7;i++){
        for(int j=0;j<8;j++){
            Board[i][j] =  new Pawn('P',1);
        }
        cout<<endl;
    };

    Board[0][0] = new Rook('R',2);
    Board[0][7] = new Rook('R',2);
    Board[7][0] = new Rook('R',1);//1-white
    Board[7][7] = new Rook('R',1);

    Board[0][3] = new Queen('Q',2);//2-black
    Board[7][3] = new Queen('Q',1);

    Board[0][4] = new King('K',2);
    Board[7][4] = new King('K',1);

    Board[0][2] = new Bishop('B',2);
    Board[0][5] = new Bishop('B',2);
    Board[7][2] = new Bishop('B',1);
    Board[7][5] = new Bishop('B',1);

    Board[0][1] = new Knight('H',2);
    Board[0][6] = new Knight('H',2);
    Board[7][1] = new Knight('H',1);
    Board[7][6] = new Knight('H',1);

    cout<<"Army added"<<endl;
}

void Chessboard:: showChessboard(){
    for (int i=0;i<8;i++){

        for(int j=0;j<8;j++){
            //Board[i][j]->showKind();//
            cout<<Board[i][j]->showKind();
            cout<<"  ";
        }
        cout<<endl;
    };
}

//void Chessboard::


