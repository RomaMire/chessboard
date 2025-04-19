#include "mainwindow.h"
#include "ui_mainwindow.h"
///////////////////////////
#include <QGraphicsRectItem>
///// load images
#include <QDebug>


MainWindow::MainWindow(Chessboard* board, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    /////////////////////////////scene initialization
    ,scene(new QGraphicsScene(this))
    ,chessboard(board)//
{
    ui->setupUi(this);
    ///////assign scene to QGraphicsView
    int tileSize = 60;
    int boardSize = tileSize * 8;



    ui->graphicsView->setFixedSize(boardSize + 40, boardSize + 40);// extra 40 pxx to width and hight
    scene->setSceneRect(0, 0, boardSize, boardSize);//starting points: left then upper, nect the end points -> dimension of the chessboard


    ui->graphicsView->setScene(scene);


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//deactivation of scroll bar
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//deactivation of scroll bar

    ui->graphicsView->setAlignment(Qt::AlignCenter);//set the middle of the view

    this->setFixedSize(ui->graphicsView->width() + 5, ui->graphicsView->height() + 30);//constant (fixed) dimention of app window



     drawBoard(); //
     addFigures(); //correct now!
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::drawBoard() {// creating visual chessboard - tiles of white and black color
    int tileSize = 60;



    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            QGraphicsRectItem *tile = new QGraphicsRectItem(col * tileSize, row * tileSize, tileSize, tileSize);
            tile->setBrush((row + col) % 2 == 0 ? Qt::white : Qt::gray);
            scene->addItem(tile);
        }
    }
}








//addFigures from the logic

void MainWindow::addFigures() {

        int tileSize = 60;  // The field size



        Figure* (*board)[8] = chessboard->getBoard();  // taking the chessboard


        //if (!board) return;

        if (!board) return;

        for (QGraphicsItem* item : scene->items()) {//every graphic objects iteration
            if (item->type() == QGraphicsPixmapItem::Type) {//check if the object is a image of the figure type
                scene->removeItem(item);//delete the figure from scene
                delete item;// delete the figure from memory
            }
        }

        std::map<char, QString> blackFiguresMap = {
            {'P', ":/img/img/bpawn.png"}, {'R', ":/img/img/brook.png"},
            {'H', ":/img/img/bknight.png"}, {'B', ":/img/img/bbishop.png"},
            {'Q', ":/img/img/bqueen.png"}, {'K', ":/img/img/bking.png"}
        };

        std::map<char, QString> whiteFiguresMap = {
            {'P', ":/img/img/wpawn.png"}, {'R', ":/img/img/wrook.png"},
            {'H', ":/img/img/wknight.png"}, {'B', ":/img/img/wbishop.png"},
            {'Q', ":/img/img/wqueen.png"}, {'K', ":/img/img/wking.png"}
        };

        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                Figure* piece = board[row][col];

                if (piece) {
                    char kind = piece->showKind();
                    int team = piece->showTeam(); // taking color of the figure

                    QString imagePath;
                    if (team == 2 && blackFiguresMap.find(kind) != blackFiguresMap.end()) {
                        imagePath = blackFiguresMap[kind]; // Black Figure
                    } else if (team == 1 && whiteFiguresMap.find(kind) != whiteFiguresMap.end()) {
                        imagePath = whiteFiguresMap[kind]; // White Figure
                    } else {
                        qDebug() << "no figure to assign" << kind << " team: " << team;
                        continue;
                    }

                    QPixmap piecePixmap(imagePath);
                    if (piecePixmap.isNull()) {
                        qDebug() << "can not load the picure" << kind << " team: " << team << " w " << imagePath;
                        continue;
                    }

                    // creating and adding the figures
                    QGraphicsPixmapItem* chessPiece = new QGraphicsPixmapItem(piecePixmap.scaled(tileSize, tileSize));
                    chessPiece->setPos(col * tileSize, row * tileSize);
                    scene->addItem(chessPiece);

                    qDebug() << " OK Figure " << kind << " (" << (team == 1 ? "White " : "Black ") << ") allocated to  (" << row << ", " << col << ")";
                }
            }
        }
}

//click handler on the chessboard
void MainWindow::mousePressEvent(QMouseEvent *event) {

    QPointF clickedPos = ui->graphicsView->mapToScene(event->pos());
    int col = clickedPos.x() / 60;
    int row = clickedPos.y() / 60;

    qDebug() << "Clicked the square :" << row << col; //show clicked position *******************


    if (row < 0 || row >= 8 || col < 0 || col >= 8) return;

    if (!pieceSelected) {
        // selecting the figure with the first click
        Figure* selected = chessboard->getBoard()[row][col];
        if (selected != nullptr) {
            selectedRow = row;
            selectedCol = col;
            pieceSelected = true;
            qDebug() << "Figure selected on  (" << row << "," << col << ")";
        } else {
            qDebug() << "No figure to chose (" << row << "," << col << ")";
        }
    } else {
        // second click - move selected figure
        bool moved = chessboard->moveFigure(selectedRow, selectedCol, row, col);
        if (moved) {
            qDebug() << "Move from  (" << selectedRow << "," << selectedCol << ") to (" << row << "," << col << ")";
            drawBoard();     // refresh the board
            addFigures();    // refresh the figures
        } else {
            qDebug() << "Wrong move...";
        }

        // reset selected
        pieceSelected = false;
        selectedRow = -1;
        selectedCol = -1;


}
}

