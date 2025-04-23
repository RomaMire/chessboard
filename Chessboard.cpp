#include "Chessboard.h"

#include <QRandomGenerator>
#include <QInputDialog>

#include "FigureCreation.h"

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




//GUI console
void Chessboard::setLogger(LoggerFunc func) {
    logger = func;
}

void Chessboard::log(const QString& msg) {
    if (logger) {
        logger(msg);  // przekazujemy komunikat do GUI
    } else {
        std::cout << "[Chessboard] " << msg.toStdString() << std::endl;
    }
}



//add figures
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

bool Chessboard::isKingInCheck(int team , bool silent) {
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
                        std::cout<<"White king is in check"<<endl << Board[i][j]->showKind() << std::endl;
                        if (!silent) {
                        log(" 🔥 White king is in check - protect the King!");
                        };
                        return true;
                        break;

                    case 2:
                         std::cout<<"Black king is in check - protect the King!" << endl << Board[i][j]->showKind() << std::endl;
                        if (!silent) {
                        log(" 🔥 Black king is in check - protect the King! " );
                        };
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


    int oldKingX = kingX;
    int oldKingY = kingY;

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

                if (team == 1) { //new kings position
                    whiteKingX = newX;
                    whiteKingY = newY;
                } else {
                    blackKingX = newX;
                    blackKingY = newY;
                }

                bool stillInCheck = isKingInCheck(team, false); // if King is still on check

                // move back
                Board[kingX][kingY] = Board[newX][newY];
                Board[newX][newY] = PlaceToMove;

                if (team == 1) {
                    whiteKingX = oldKingX;
                    whiteKingY = oldKingY;
                } else {
                    blackKingX = oldKingX;
                    blackKingY = oldKingY;
                }

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

                        Board[x][y] = Board[i][j]; // check the move
                        Board[i][j] = nullptr;


                        bool stillInCheck = isKingInCheck(team, false); // if the move can save the king

                        // move back
                        Board[i][j] = Board[x][y];
                        Board[x][y] = PlaceToMove;

                        if (!stillInCheck) {
                            return false; // no mate - there is a option for your other figure
                        } else{
                            std::cout<<"Check Mate"<<endl;
                            log(" 👑 Check Mate");
                        }
                    }
                }
            }
        }
    }
}



std::cout<<"Check Mate  this time"<<endl;
log(" 👑 Check Mate this time");

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


 currentTurn = (currentTurn == 1) ? 2 : 1;
    return true;  // castle is possible ******************************
};




bool Chessboard::moveFigure(int startX, int startY, int endX, int endY) {


    Figure* SelectedFigure = Board[startX][startY];  // Selecting figure
    void checKingPosition();



    // check if place is empty before moove
    if (Board[startX][startY] == nullptr) {
        std::cout << "Empty square - no fugure to move (" << startX << ", " << startY << ")" << std::endl;
        return false;
    }

    if (Board[startX][startY]->showTeam() != currentTurn) { //switch the turn
        log(currentTurn == 1 ? "White's turn!" : "Black's turn!");
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




    // is move correct?
    if (!SelectedFigure->isMoveValid(startX, startY, endX, endY, Board)) {
        std::cout << "Wrong move " << SelectedFigure->showKind() << "!" << std::endl; //not here
        return false;

    }

    if (SelectedFigure->showKind() == 'K') {
        if (SelectedFigure->showTeam() == 1) {  // new king position after move
            whiteKingX = endX;
            whiteKingY = endY;
        } else {  // Black King
            blackKingX = endX;
            blackKingY = endY;

        }

        SelectedFigure->setMove();
    }


    //checking if not check




    if( SelectedFigure->showKind() =='K' ){ // if no check


        Figure* PlaceToMove = Board[endX][endY];
        Figure* PlaceBeforeMove = Board[startX][startY];

        Board[endX][endY] = SelectedFigure;//
        Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure



        if( SelectedFigure->showTeam() == 2 && isKingInCheck(2)  ){

            cout<<"Black King can not stay on this place - check!"<<endl;
            log("Black King can not stay on this place - check!");

            Board[startX][startY] = PlaceBeforeMove;
            Board[endX][endY] = PlaceToMove;



            return false;
        };

        if( SelectedFigure->showTeam() == 1 && isKingInCheck(1)  ){

            cout<<"White King can not stay in this place - check! "<<endl;
            log("White King can not stay in this place - check!");

            Board[startX][startY] = PlaceBeforeMove;
            Board[endX][endY] = PlaceToMove;


            return false;
        };



         currentTurn = (currentTurn == 1) ? 2 : 1; //switch the turn --- Kings move problem solved !!!

    };




    // Alocating figure to new square check checking for white figure
    // Solving problem with potential move due to block the check

    Figure* PlaceToMove = Board[endX][endY];
    Figure* PlaceBeforeMove = Board[startX][startY];

    Board[endX][endY] = SelectedFigure;
    Board[startX][startY] = nullptr;

    int oldKingX = (SelectedFigure->showTeam() == 1) ? whiteKingX : blackKingX;
    int oldKingY = (SelectedFigure->showTeam() == 1) ? whiteKingY : blackKingY;





    // take the kings position
    checkKingPosition();



    bool stillInCheck = isKingInCheck(SelectedFigure->showTeam());

    // revers the move
    Board[startX][startY] = PlaceBeforeMove;
    Board[endX][endY] = PlaceToMove;

    // get back king's position
    if (SelectedFigure->showTeam() == 1) {
        whiteKingX = oldKingX;
        whiteKingY = oldKingY;

    } else {
        blackKingX = oldKingX;
        blackKingY = oldKingY;


    }

    if (stillInCheck) {
        cout << "Can not move there - King would still be in check!" << endl;
        log("Can not move there - King would still be in check");

        return false;
    }
/////

    // attack mode
    if (Board[endX][endY] != nullptr) {


        checkKingPosition();






        if (Board[endX][endY]->showKind()=='K'){
            std::cout << "Be honorable! Can not attack King" << std::endl;
            log("Be honorable! Can not kill the King ");
            return false;
        }


        if (Board[endX][endY]->showTeam() == SelectedFigure->showTeam()) {
            std::cout << "Be honorable! Can not attack your own team" << std::endl;
            log("Be honorable! Can not attack your own team! ");
            return false;
        }

        std::cout << "Enemy" << Board[endX][endY]->showKind() << " eliminated" << std::endl;
        log(" 🗡️ Enemy eliminated! ");



        delete Board[endX][endY];  // deleting figure of second team
        //to eliminate problem from GUI when enemy figure is destroyed
        Board[endX][endY] = nullptr;
    }


    Board[endX][endY] = SelectedFigure;
    Board[startX][startY] = nullptr;  // Assign the nullptr to the old place of moved figure

    //change pawn for Queen after reaching the last line
    if (SelectedFigure->showKind() == 'P') {
        if ((SelectedFigure->showTeam() == 1 && endX == 0) ||
            (SelectedFigure->showTeam() == 2 && endX == 7)) {

            // delete Pawn
            delete SelectedFigure;

            /*
            // create a new Queen
            Board[endX][endY] = new Queen('Q', currentTurn);
            log("A new Figure on the board!");
            cout<<"A new Figure on the board!"<<endl;
            */

            QStringList options;
            options << "Queen" << "Rook" << "Bishop" << "Knight";
            bool ok;


            QString choice = QInputDialog::getItem(
                nullptr,
                "Chose your ally",
                "Choose a new Figure:",
                options,
                0,
                false,
                &ok
                );

            if (!ok || choice.isEmpty()) {
                choice = "Queen";  // if no choice then Queen
            }

            // Make a choice with a new figure


            if (choice == "Queen") {
                  Board[endX][endY] = createFigure<Queen>('Q', currentTurn);
            } else if (choice == "Rook") {
                Board[endX][endY] = createFigure<Rook>('R', currentTurn);
            } else if (choice == "Bishop") {
                Board[endX][endY] = createFigure<Bishop>('B', currentTurn);
            } else if (choice == "Knight") {
                Board[endX][endY] = createFigure<Knight>('H', currentTurn);
            }

        }
    }


    std::cout << "Move done: " << SelectedFigure->showKind() << " went (" << endX << ", " << endY << ")" << std::endl;
    log(" 🛡️ Move done");

    isKingInCheck(2,true);
    isKingInCheck(1,true);
    isCheckmate(1);
    isCheckmate(2);

    // castling mode - when the move is done, switch the bool value
    SelectedFigure->setMove();


    currentTurn = (currentTurn == 1) ? 2 : 1; //switch the turn

    return true;
};


//method for GUI

Figure* (*Chessboard::getBoard())[8] {

    return Board;
};


//void Chessboard::


