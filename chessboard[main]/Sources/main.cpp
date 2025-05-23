#include "mainwindow.h"

#include <QApplication>
using namespace std;
#include <iostream>

#include "Chessboard.h"
#include "Pawn.h"

int main(int argc, char *argv[])
{

    Chessboard Board;

    Board.addArmy();

    Board.showChessboard();
//checking move
    Board.moveFigure(1,4,3,4);
    Board.showChessboard();
    Board.moveFigure(0,4,1,4);
    Board.moveFigure(1,4,2,4);


   Board.moveFigure(6,3,4,3);//white pawn before attack

   Board.moveFigure(4,3,3,3);//check by white pawn
   Board.moveFigure(1,0,2,0);// move other black figure?//******** working!
  // Board.moveFigure(3,3,2,4);  //pawn attack on king

   Board.moveFigure(2,4,1,4); //king one back
   Board.moveFigure(1,4,2,4); //king one forward

  //Board.moveFigure(7,6,5,5);//horse white
  /*  Board.moveFigure(5,5,3,6);

    Board.moveFigure(3,6,2,4);

*/

    Board.showChessboard();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
