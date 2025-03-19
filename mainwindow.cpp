#include "mainwindow.h"
#include "ui_mainwindow.h"
///////////////////////////
#include <QGraphicsRectItem>

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

     drawBoard();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::drawBoard() {
    int tileSize = 60;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            QGraphicsRectItem *tile = new QGraphicsRectItem(col * tileSize, row * tileSize, tileSize, tileSize);
            tile->setBrush((row + col) % 2 == 0 ? Qt::white : Qt::gray);
            scene->addItem(tile);
        }
    }
}
