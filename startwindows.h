#ifndef STARTWINDOWS_H
#define STARTWINDOWS_H

#include <QMainWindow>

namespace Ui {
class StartWindows;
}


class StartWindows: public QMainWindow
{

    Q_OBJECT
public:

    explicit StartWindows(QWidget *parent = nullptr);
    ~StartWindows();

private slots:
    void on_startBtn_clicked();  // slot "Start Game"
    void on_closeBtn_clicked();  // slot "Exit"

    void on_aboutBtn_clicked(); // about information

private:
    Ui::StartWindows *ui;

};

#endif // STARTWINDOWS_H
