#include "mainwindow.h"
#include "ui_mainwindow.h"
///////////////////////////
#include <QGraphicsRectItem>
///// load images
#include <QDebug>
#include <QMessageBox>


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
//****************text console
    //ui->textConsole->append("Figure selected.");



//****************  size of the mainwindow
    ui->graphicsView->setFixedSize(boardSize + 40, boardSize + 200);// extra 40 pxx to width and hight
    scene->setSceneRect(0, 0, boardSize, boardSize);//starting points: left then upper, nect the end points -> dimension of the chessboard


    ui->graphicsView->setScene(scene);


    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//deactivation of scroll bar
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//deactivation of scroll bar

    ui->graphicsView->setAlignment(Qt::AlignCenter);//set the middle of the view

    this->setFixedSize(ui->graphicsView->width() + 5, ui->graphicsView->height() + 30);//constant (fixed) dimention of app window



     drawBoard(); //
     addFigures(); //correct now!


     //game window in the middle of the screen

     QScreen *screen = QGuiApplication::primaryScreen();
     QRect screenGeometry = screen->geometry();
     int x = (screenGeometry.width() - this->width()) / 2;
     int y = (screenGeometry.height() - this->height()) / 2;
     this->move(x, y);
}



MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

//****************text console
void MainWindow::log(const QString& msg) {
    ui->textConsole->append(msg);
    qDebug() << msg;
}



void MainWindow::drawBoard() {// creating visual chessboard - tiles of white and black color
    int tileSize = 60;



    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            QGraphicsRectItem *tile = new QGraphicsRectItem(col * tileSize, row * tileSize, tileSize, tileSize);


            QColor baseColor = (row+ col) % 2 == 0 ? Qt::white : Qt::gray;

            if (row == highlightedRow && col == highlightedCol) {
             baseColor = QColor(250, 250, 230);  //
            };

            for (const QPoint& p : possibleMoves) {
                if (p.x() == col && p.y() == row) {
                    baseColor = QColor(250, 250, 220);  //
                    break;
                }
            }

            tile->setBrush(baseColor);

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
                        qDebug() << "No figure to assign" << kind << " team: " << team;
                        continue;
                    }

                    QPixmap piecePixmap(imagePath);
                    if (piecePixmap.isNull()) {
                        qDebug() << "Can not load the picure" << kind << " team: " << team << " w " << imagePath;
                        continue;
                    }

                    // creating and adding the figures
                    QGraphicsPixmapItem* chessPiece = new QGraphicsPixmapItem(piecePixmap.scaled(tileSize, tileSize));
                    chessPiece->setPos(col * tileSize, row * tileSize);
                    scene->addItem(chessPiece);

                    //qDebug() << " OK Figure " << kind << " (" << (team == 1 ? "White " : "Black ") << ") allocated to  (" << row << ", " << col << ")";
                }
            }
        }
}

//click handler on the chessboard
void MainWindow::mousePressEvent(QMouseEvent *event) {

    QPointF clickedPos = ui->graphicsView->mapToScene(event->pos());
    int col = clickedPos.x() / 60;
    int row = clickedPos.y() / 60;

   // qDebug() << "Clicked the square :" << row << col; //show clicked position *******************


    if (row < 0 || row >= 8 || col < 0 || col >= 8) return;

    if (!pieceSelected) {
        //posible moves reset
        possibleMoves.clear();

        // selecting the figure with the first click
        Figure* selected = chessboard->getBoard()[row][col];
        if (selected != nullptr) {
            selectedRow = row;
            selectedCol = col;
            pieceSelected = true;
           // qDebug() << "Figure selected on  (" << row << "," << col << ")";

            highlightedRow = row;
            highlightedCol = col;

            drawBoard();
            addFigures();

            //looking for possible moves
            for (int r = 0; r < 8; ++r) {
                for (int c = 0; c < 8; ++c) {
                    if (selected->isMoveValid(row, col, r, c, chessboard->getBoard())) {
                        // Sprawdź czy nie blokuje własnego króla
                        Figure* tempDest = chessboard->getBoard()[r][c];
                        Figure* tempSrc = chessboard->getBoard()[row][col];
                        chessboard->getBoard()[r][c] = tempSrc;
                        chessboard->getBoard()[row][col] = nullptr;

                        chessboard->checkKingPosition();
                        if (!chessboard->isKingInCheck(selected->showTeam())) {
                            possibleMoves.append(QPoint(c, r));
                        }

                        // Przywróć stan planszy
                        chessboard->getBoard()[row][col] = tempSrc;
                        chessboard->getBoard()[r][c] = tempDest;
                    }
                }
            }
            //
            drawBoard();     // refresh te board
            addFigures();

        } else {
            qDebug() << "No figure to chose (" << row << "," << col << ")";
            log("No figure to chose ");
        }
    } else {
        // second click - move selected figure
        bool moved = chessboard->moveFigure(selectedRow, selectedCol, row, col);
        if (moved) {
           // qDebug() << "Move from  (" << selectedRow << "," << selectedCol << ") to (" << row << "," << col << ")";
            drawBoard();     // refresh the board
            addFigures();    // refresh the figures
            possibleMoves.clear();
        } else {
            qDebug() << "Wrong move...";
            log("Wrong move...");
        }

        // reset selected
        pieceSelected = false;
        selectedRow = -1;
        selectedCol = -1;

        //reset highlihted
        highlightedRow = -1;
        highlightedCol = -1;

        drawBoard();
        addFigures();
}
}

void MainWindow::confirmExit() {

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "Exit Game",
        "Are you sure you want to quit the game?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        close(); // zamyka aplikację
    }
}


void MainWindow::confirmReset() {

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "Exit Game",
        "Are you sure you want to reset the game?",
        QMessageBox::Yes | QMessageBox::No
        );

/*
    if (reply == QMessageBox::Yes) {
        chessboard->~Chessboard();                   // delete previous gamme
        new (chessboard) Chessboard();               // create new chessboard again
        chessboard->addArmy();                       // put figures on the table
        drawBoard();                                 // creat board
        addFigures();                                // add figures
        log(" Game has been reset");
    } else {                                         ******* reset game problem
        log("Reset canceled");
    }
*/

    delete chessboard;                   // destroy previous game
    chessboard = new Chessboard();       // create new game

    chessboard->setLogger([this](const QString& msg) { // set up new logger
        log(msg);

        });

    chessboard->addArmy();                   // put a figures on the board
    drawBoard();
    addFigures();

    log( "Game has been reset - play again! ");

    };


void MainWindow::on_closeBtn_clicked()
{
    confirmExit();
}

void MainWindow::on_resetBtn_clicked()
{
 confirmReset();
}



void MainWindow::on_aboutBtn_clicked()
{
    QMessageBox::aboutQt(this,"Chessboard Game" );
}

