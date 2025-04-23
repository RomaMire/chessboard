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

//info bar
#include <QTextEdit>



QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


/**
 * @brief The MainWindow class handles the graphical user interface for the chess game.
 *
 * It is responsible for rendering the board, handling user input, updating the view,
 * and communicating with the core game logic encapsulated in the Chessboard class.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window with the provided chessboard.
     * @param board Pointer to the Chessboard logic object.
     * @param parent Optional parent widget.
     */


    MainWindow(Chessboard* board, QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();
    /**
     * @brief Logs a message to the on-screen text console.
     * @param msg The message to display.
     */
     void log(const QString& msg);//textConsole GUI

    /**
     * @brief Prompts the user for confirmation before exiting the game.
     */


    void confirmExit();//ask obout permision when exit the game

     /**
     * @brief Prompts the user for confirmation before resetting the board.
     */
     void confirmReset();

    /**
     * @brief Draws the visual chessboard with tiles.
     */

     void drawBoard();//chessboard of tailes

     // void addPictures(); // pictures of Figures

     /**
     * @brief Places figure images on the board based on current game state.
     */


     void addFigures(); //taking figures from Chessboard.cpp

     /**
     * @brief Updates the graphics to match the current state of the logic board.
     */
     void updateBoard(); //grapghic actualization
protected:

     /**
     * @brief Handles mouse clicks for selecting and moving pieces.
     * @param event The mouse press event.
     */
    void mousePressEvent(QMouseEvent *event) override;  // mouse eventhandler


private slots:
    /**
     * @brief Slot triggered when the close button is clicked.
     */

   // void on_pushButton_clicked();

    void on_closeBtn_clicked();
    /**
     * @brief Slot triggered when the about button is clicked.
     */


    void on_aboutBtn_clicked();

    /**
     * @brief Slot triggered when the reset button is clicked.
     */
    void on_resetBtn_clicked();

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
    bool pieceSelected = false; ///< Flag indicating if a piece is selected.

    //light selected figure
    int highlightedRow = -1;///< Row of the last highlighted move.
    int highlightedCol = -1;

    QVector<QPoint> possibleMoves;///< List of valid move positions for the selected piece.



    //info bar
    QTextEdit* textConsole;///< Console used to display game messages/logs.
};
#endif // MAINWINDOW_H
