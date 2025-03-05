#include "mainwindow.h"

#include <QApplication>
using namespace std;
#include <iostream>

#include "Chessboard.h"
#include "Pawn.h"

int main(int argc, char *argv[])
{

    Chessboard Chessboard;

    Chessboard.addArmy();

    Chessboard.showChessboard();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
