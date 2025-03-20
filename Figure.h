#ifndef FIGURE_H
#define FIGURE_H


#include<iostream>
using namespace std;

class Figure
{
protected:

    char kind {'*'};
    int team {0};// 1-white 2-black



    bool wasMoved = false;


public:
    Figure(char kind, int team);

    virtual ~Figure();

    char showKind();

    int showTeam();



    void move();

    //castling
    bool hasMoved();
    void setMove();

   // bool isMoveValid();

    virtual bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]) = 0;  // abstract - own rules for each figure

   /* virtual bool isMoveValid(int startX, int startY, int endX, int endY, Figure* board[8][8]){
        return false;
   }; */




};

#endif // FIGURE_H
