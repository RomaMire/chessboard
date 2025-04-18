#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

///////////////
#include <QGraphicsScene>
#include <QGraphicsView>
///////////////
/// logic implementation and mouse eventhandler
#include <QMouseEvent>

#include "Chessboard.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Chessboard* board, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;  // mouse eventhandler


private:
    Ui::MainWindow *ui;

    ////////////////////
    QGraphicsScene *scene;  //initialization of chessboard scene

    ///eventhadler
    Chessboard *chessboard;  // pointer to chessboard object... mainwindow has access to chessboard

    //try to combine with the logic ********************
    //ChessFigure *selectedFigure = nullptr;

    QGraphicsPixmapItem *selectedPiece = nullptr;
    QPoint selectedPiecePos;

    // a logic for moving figure - if "-" means figure is not selected
    int selectedRow = -1;
    int selectedCol = -1;
    bool pieceSelected = false;





    void drawBoard();//chessboard of tailes

   // void addPictures(); // pictures of Figures

    void addFigures(); //taking figures from Chessboard.cpp

    void updateBoard(); //grapghic actualization
};
#endif // MAINWINDOW_H
