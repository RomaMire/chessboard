#include "mainwindow.h"
#include "ui_mainwindow.h"
///////////////////////////
#include <QGraphicsRectItem>
///// load images
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    /////////////////////////////scene initialization
    ,scene(new QGraphicsScene(this))  // 🔹 Inicjalizacja `QGraphicsScene`
{
    ui->setupUi(this);
    ///////assign scene to QGraphicsView
    int boardSize = 900;

   ui->graphicsView->setFixedSize(boardSize, boardSize);

   scene->setSceneRect(0, 0, 900, 900);//wider scene due to embrace full size

    ui->graphicsView->setScene(scene);

    ui->graphicsView->setAlignment(Qt::AlignCenter);

     drawBoard(); //
    addPictures(); //

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::drawBoard() {/// creating visual chessboard - tiles of white and black color
    int tileSize = 60;



    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            QGraphicsRectItem *tile = new QGraphicsRectItem(col * tileSize, row * tileSize, tileSize, tileSize);
            tile->setBrush((row + col) % 2 == 0 ? Qt::white : Qt::gray);
            scene->addItem(tile);
        }
    }
}

void MainWindow::addPictures() {
    int tileSize = 60;  // Rozmiar pola

    // 🔹 Wczytanie grafik z `images.qrc`
    QPixmap blackImages[6] = {
        QPixmap(":/img/img/bpawn.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/brook.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/bknight.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/bbishop.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/bqueen.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/bking.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)
    };

    QPixmap whiteImages[6] = {
        QPixmap(":/img/img/wpawn.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/wrook.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/wknight.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/wbishop.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/wqueen.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation),
        QPixmap(":/img/img/wking.png").scaled(tileSize, tileSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)
    };

    //check if pictures loaded

    for (int i = 0; i < 6; i++) {
        if (blackImages[i].isNull()) {
            qDebug() << "err - figure number: " << i;
        }
        if (whiteImages[i].isNull()) {
            qDebug() << "err - figure number: " << i;
        }
    }

    //chessboard origin

    char boardSetup[8][8] = {
        {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'},  // Black figures
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'h', 'b', 'q', 'k', 'b', 'h', 'r'}   // White figures
    };


    //add pictures on the chessboard

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {

            char kind = boardSetup[row][col];

            if (kind == ' ') continue;  // avoid empty places

            int index = 0;

            switch (tolower(kind)) {
            case 'p': index = 0; break;
            case 'r': index = 1; break;
            case 'h': index = 2; break;
            case 'b': index = 3; break;
            case 'q': index = 4; break;
            case 'k': index = 5; break;
            }

            QPixmap piecePixmap = isupper(kind) ? blackImages[index] : whiteImages[index];

            QGraphicsPixmapItem *piece = new QGraphicsPixmapItem(piecePixmap);
            piece->setPos(col * tileSize, row * tileSize);
            scene->addItem(piece);
        }
    }
};
