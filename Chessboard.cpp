#include "Chessboard.h"


Chessboard::Chessboard(){
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
           // Board[i][j] = new Figure('*',0);
            Board[i][j] = nullptr;
        }
    }
}

Chessboard::~Chessboard(){
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){
           delete Board[i][j]; //delete all pointers
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

    cout<<"Black and White army added"<<endl;
}

void Chessboard:: showChessboard(){

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (Board[i][j] != nullptr) {
                cout << Board[i][j]->showKind() <<"  ";
            } else {
                cout << "*  ";  // Square without figure
            }
        }
        cout << endl;
    }
}

bool Chessboard::moveFigure(int startX, int startY, int endX, int endY) {
    // check if place is empty before moove
    if (Board[startX][startY] == nullptr) {
        std::cout << "Empty square - no fugure to move (" << startX << ", " << startY << ")" << std::endl;
        return false;
    }

    Figure* SelectedFigure = Board[startX][startY];  // Selecting figure

    // is move correct
    if (!SelectedFigure->isMoveValid(startX, startY, endX, endY, Board)) {
        std::cout << "wrong move" << SelectedFigure->showKind() << "!" << std::endl;
        return false;
    }

    // attack mode
    if (Board[endX][endY] != nullptr) {
        if (Board[endX][endY]->showTeam() == SelectedFigure->showTeam()) {
            std::cout << "Be honorable! Can not attack your own team" << std::endl;
            return false;
        }

        std::cout << "Enemy" << Board[endX][endY]->showKind() << " eliminated" << std::endl;
        delete Board[endX][endY];  // deleting figure of second team
    }

    // Alocating figure to new square
    Board[endX][endY] = SelectedFigure;
    Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure

    std::cout << "Move done: " << SelectedFigure->showKind() << " going to (" << endX << ", " << endY << ")" << std::endl;
    return true;
}





//void Chessboard::


