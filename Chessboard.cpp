#include "Chessboard.h"


Chessboard::Chessboard(){
    for(int i =0;i<8;i++){
        for(int j=0;j<8;j++){

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

bool Chessboard:: isCheckmate(int team){



    if (!isKingInCheck(team)){
        return false;

    }

    int kingX = (team == 1) ? whiteKingX : blackKingX;
    int kingY = (team == 1) ? whiteKingY : blackKingY;


    int possibleKingMoves[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
        {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };


    //possible moves in loop

    for (int i = 0; i < 8; i++) {

        int newX = kingX + possibleKingMoves[i][0];  // change in  X
        int newY = kingY + possibleKingMoves[i][1];  // change in  Y

        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            // if there is way to move


            Figure* PlaceToMove = Board[newX][newY];

            if (PlaceToMove == nullptr || PlaceToMove->showTeam() != team) { // Only to empty place or attack mode
                Board[newX][newY] = Board[kingX][kingY]; // Try to move
                Board[kingX][kingY] = nullptr;

                bool stillInCheck = isKingInCheck(team); // if King is still on check

                // move back
                Board[kingX][kingY] = Board[newX][newY];
                Board[newX][newY] = PlaceToMove;

                if (!stillInCheck) {
                    return false; // no mate
                }


        }
    }
}



    ////////////////if any other figure can block the check
for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
        if (Board[i][j] != nullptr && Board[i][j]->showTeam() == team) {
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    if (Board[i][j]->isMoveValid(i, j, x, y, Board)) {
                        Figure* PlaceToMove = Board[x][y];

                        Board[x][y] = Board[i][j]; // checking the move
                        Board[i][j] = nullptr;

                        bool stillInCheck = isKingInCheck(team); // if the move can save the king

                        // move back
                        Board[i][j] = Board[x][y];
                        Board[x][y] = PlaceToMove;

                        if (!stillInCheck) {
                            return false; // no mate - there is a option for your other figure
                        }
                    }
                }
            }
        }
    }
}

            std::cout<<"Check Mate"<<endl;
            return true;
    /// ///////////
};

bool Chessboard::isToCastle(int kingX, int kingY, int rookX, int rookY){

    Figure* king = Board[kingX][kingY];
    Figure* rook = Board[rookX][rookY];

    // check the kind of selected figures
    if (king == nullptr || rook == nullptr) return false;
    if (king->showKind() != 'K' || rook->showKind() != 'R') return false;

    // check if king or rook has moved
    if (king->hasMoved() || rook->hasMoved()) return false;

    // check if there is no other figure between
    int step = (rookY > kingY) ? 1 : -1;
    for (int y = kingY + step; y != rookY; y += step) {
        if (Board[kingX][y] != nullptr) return false;
    }

    // check if there is no check on the castle way
    for (int y = kingY; y != rookY; y += step) {
        if (isKingInCheck(king->showTeam())) return false;
    }

    return true;  // castle is possible
};

bool Chessboard::moveFigure(int startX, int startY, int endX, int endY) {


    Figure* SelectedFigure = Board[startX][startY];  // Selecting figure
    void checKingPosition();



    // check if place is empty before moove
    if (Board[startX][startY] == nullptr) {
        std::cout << "Empty square - no fugure to move (" << startX << ", " << startY << ")" << std::endl;
        return false;
    }


    if (SelectedFigure->showKind() == 'K' && abs(startY - endY) == 2) {
        int rookY = (endY > startY) ? 7 : 0;//define the catling version
        if (isToCastle(startX, startY, startX, rookY)) {
            // move the king
            Board[endX][endY] = SelectedFigure;
            Board[startX][startY] = nullptr;
            SelectedFigure->setMove();  // king moved

            // move the rook
            Figure* rook = Board[startX][rookY];
            int newRookY = (endY > startY) ? endY - 1 : endY + 1;
            Board[startX][newRookY] = rook;
            Board[startX][rookY] = nullptr;
            rook->setMove();  //rook moved

            return true;
        }
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
        //to eliminate problem from GUI when enemy figure is destroyed
        Board[endX][endY] = nullptr;
    }



    //isKingInCheck(1);

    if( SelectedFigure->showKind() =='K' ){


        Figure* PlaceToMove = Board[endX][endY];
        Figure* PlaceBeforeMove = Board[startX][startY];

        Board[endX][endY] = SelectedFigure;//
        Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure



        if( SelectedFigure->showTeam() == 2 && isKingInCheck(2)  ){

            cout<<"Black King can not stay on this place - check!"<<endl;

            Board[startX][startY] = PlaceBeforeMove;
            Board[endX][endY] = PlaceToMove;

            return false;
        };

        if( SelectedFigure->showTeam() == 1 && isKingInCheck(1)  ){

            cout<<"White King can not stay on this place - check! "<<endl;

            Board[startX][startY] = PlaceBeforeMove;
            Board[endX][endY] = PlaceToMove;

            return false;
        };

    };
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

    /*if( SelectedFigure->showKind() =='K' && SelectedFigure->showTeam()!= Board[endX][endY]->isMoveValid()){
        cout<<"can not move there - Black King would be on check!!!"<<endl;

        return false;
    };*/






    Board[endX][endY] = SelectedFigure;
    Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure

    std::cout << "Move done: " << SelectedFigure->showKind() << " went (" << endX << ", " << endY << ")" << std::endl;

    isKingInCheck(2);
    isKingInCheck(1);
    isCheckmate(1);
    isCheckmate(2);


    // castling mode - when the move is done, switch the bool value
    SelectedFigure->setMove();



    return true;
};


//method for GUI

Figure* (*Chessboard::getBoard())[8] {

    return Board;
};


//void Chessboard::


