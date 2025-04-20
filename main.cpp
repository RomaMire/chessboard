#include "mainwindow.h"
#include "startwindows.h" //start menu


#include <QApplication>
using namespace std;
#include <iostream>

#include "Chessboard.h"

/*
int main(int argc, char *argv[])
{
QApplication a(argc, argv);


    Chessboard Board;
    Board.addArmy();
    Board.showChessboard();



    MainWindow w(&Board);

    Board.setLogger([&w](const QString& msg) {
        w.log(msg);               // send logs to GUI
    });

    w.show();

   return a.exec();
}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindows startMenu;
    startMenu.show();

    return a.exec();

}
