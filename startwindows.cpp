#include "startwindows.h"
#include "ui_startwindows.h"
#include "mainwindow.h"
#include "Chessboard.h"

#include <QMessageBox>  // message info

#include<QPixmap>

StartWindows::StartWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindows)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/hero.jpg");
    if (!pix.isNull()) {
        ui->labelHero->setPixmap(pix.scaled(
            ui->labelHero->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            ));
    } else {
        qDebug() << "No picture found!";
    }

    setWindowTitle("Chessboard C++ Project");
}

StartWindows::~StartWindows()
{
    delete ui;
}

void StartWindows::on_startBtn_clicked()
{
    // initialization of chessboard
    Chessboard* board = new Chessboard();
    board->addArmy();

    // creation of MainWindow and sed borad object
    MainWindow* mainWindow = new MainWindow(board);

    // infoConsole log()
    board->setLogger([mainWindow](const QString& msg) {
        mainWindow->log(msg);
    });



    mainWindow->show();
    this->close();  // close menu
}

void StartWindows::on_closeBtn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "Exit Game",
        "Are you sure you want to quit?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        close(); // end and close app
    }
}

void StartWindows::on_aboutBtn_clicked()
{
    QMessageBox::about(
        this,
        "Chess Game",
        "C++ Project \nChess Game\n\n Train your tactical thinking and outsmart your opponent! \n\n\n\n Github creation proces: https://github.com/RomaMire/chessboard/branches/active \n\n Github main: https://github.com/RomaMire/chessboard\n\n\n\n\n Created by: Roman Mirek\n student id: 340 971 ."
        );
}

