#ifndef STARTWINDOWS_H
#define STARTWINDOWS_H

#include <QMainWindow>

namespace Ui {
class StartWindows;
}
/**
 * @brief The StartWindows class represents the initial startup window for the Chess application.
 *
 * This class provides a graphical interface with buttons to start the game, close the application, or display information about the project.
 */

class StartWindows: public QMainWindow
{

    Q_OBJECT
public:

    /**
     * @brief Constructor for StartWindows.
     * @param parent The parent widget.
     */
    explicit StartWindows(QWidget *parent = nullptr);


    /**
     * @brief Destructor for StartWindows.
     */
    ~StartWindows();

private slots:

    /**
     * @brief Slot triggered when the "Start" button is clicked.
     *
     * Initializes the chessboard and launches the main game window.
     */
    void on_startBtn_clicked();  // slot "Start Game"
    /**
     * @brief Slot triggered when the "Close" button is clicked.
     *
     * Asks the user for confirmation before closing the application.
     */
    void on_closeBtn_clicked();  // slot "Exit"

    /**
     * @brief Slot triggered when the "About" button is clicked.
     *
     * Displays an informational message box about the project.
     */

    void on_aboutBtn_clicked(); // about information

private:
    Ui::StartWindows *ui;/// UI pointer to access UI components.

};

#endif // STARTWINDOWS_H
