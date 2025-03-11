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
    //blackKingX = 0;
    //blackKingY = 4;


    Board[7][4] = new King('K',1);
    //whiteKingX = 7;
    //whiteKingY = 4;

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


void Chessboard::checkKingPosition(){

    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 8; j++) {
            if (Board[i][j] != nullptr && Board[i][j]->showKind() == 'K') {
                if (Board[i][j]->showTeam() == 1) {  // White king
                    whiteKingX = i;
                    whiteKingY = j;
                } else {  // Black king
                    blackKingX = i;
                    blackKingY = j;
                }
            }
        }
    }

}

bool Chessboard::isKingInCheck(int team) {
    // take king's position

    //int kingX = (team == 2) ?  blackKingX :whiteKingX ;
    //int kingY = (team == 2) ?  blackKingY :whiteKingY ;

    int kingX = (team == 1) ? whiteKingX : blackKingX;
    int kingY = (team == 1) ? whiteKingY : blackKingY;


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (Board[i][j] != nullptr && Board[i][j]->showTeam() != team) {

                if (Board[i][j]->showKind() == 'K') {// avoid check by other king
                    continue;
                };

                // Check if enemy figure King is in range of attack
                if (Board[i][j]->isMoveValid(i, j, kingX, kingY, Board) ) {

                    switch (team){
                    case 1:
                        std::cout<<"White king is on check - isKingOnCheck<<endl "<< Board[i][j]->showKind() << std::endl;
                        return true;
                        break;

                    case 2:
                         std::cout<<"Black king is on check - <<endl "<< Board[i][j]->showKind() << std::endl;
                        return true;
                         break;

                    };
                };
                   // std::cout<<"Protect the King!"<<endl;

            }


            };
        }


      //cout<<"no check"<<endl;

    return false;  // No check
};


bool Chessboard::moveFigure(int startX, int startY, int endX, int endY) {


    Figure* SelectedFigure = Board[startX][startY];  // Selecting figure
    void checKingPosition();



    // check if place is empty before moove
    if (Board[startX][startY] == nullptr) {
        std::cout << "Empty square - no fugure to move (" << startX << ", " << startY << ")" << std::endl;
        return false;
    }



    if (SelectedFigure->showKind() == 'K') {
        if (SelectedFigure->showTeam() == 1) {  // White King
            whiteKingX = endX;
            whiteKingY = endY;
        } else {  // Black King
            blackKingX = endX;
            blackKingY = endY;
            cout<<blackKingX<<endl;
        }
    }


    // is move correct
    if (!SelectedFigure->isMoveValid(startX, startY, endX, endY, Board)) {
        std::cout << "wrong move " << SelectedFigure->showKind() << "!" << std::endl;
        return false;

    }


    //checking if not check



    // attack mode
    if (Board[endX][endY] != nullptr) {

        if (Board[endX][endY]->showKind()=='K'){
            std::cout << "Be honorable! Can not attack King" << std::endl;
            return false;
        }


        if (Board[endX][endY]->showTeam() == SelectedFigure->showTeam()) {
            std::cout << "Be honorable! Can not attack your own team" << std::endl;
            return false;
        }

        std::cout << "Enemy" << Board[endX][endY]->showKind() << " eliminated" << std::endl;
        delete Board[endX][endY];  // deleting figure of second team
    }



    //isKingInCheck(1);
    // Alocating figure to new square check checking for white figure

    if( isKingInCheck(1) && SelectedFigure->showTeam()== 1){
        cout<<"can not move there - White King is on check!!!"<<endl;

        return false;
    };


    // Alocating figure to new square check checking for black figures

    if( isKingInCheck(2) && SelectedFigure->showTeam()== 2){
        cout<<"can not move there - Black King is on check!!!"<<endl;

        return false;
    };

    if( isKingInCheck(2) && SelectedFigure->showTeam()== 2){
        cout<<"can not move there - Black King is on check!!!"<<endl;

        return false;
    };


    /*if( SelectedFigure->showKind() =='K' && SelectedFigure->showTeam()!= Board[endX][endY]->isMoveValid()){
        cout<<"can not move there - Black King would be on check!!!"<<endl;

        return false;
    };*/


    if( SelectedFigure->showKind() =='K' ){


    Figure* PlaceToMove = Board[endX][endY];
    Figure* PlaceBeforeMove = Board[startX][startY];

    Board[endX][endY] = SelectedFigure;//
    Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure



    if( SelectedFigure->showTeam() == 2 && isKingInCheck(2)  ){

        cout<<"Can not access this place by Black King due to check! "<<endl;

        Board[startX][startY] = PlaceBeforeMove;
        Board[endX][endY] = PlaceToMove;

        return false;
    };

    if( SelectedFigure->showTeam() == 1 && isKingInCheck(1)  ){

        cout<<"Can not access this place by White King due to check! "<<endl;

        Board[startX][startY] = PlaceBeforeMove;
        Board[endX][endY] = PlaceToMove;

        return false;
    };

    };


    Board[endX][endY] = SelectedFigure;
    Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure

    std::cout << "Move done: " << SelectedFigure->showKind() << " went (" << endX << ", " << endY << ")" << std::endl;

    return true;

};





//void Chessboard::


