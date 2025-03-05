#ifndef FIGURE_H
#define FIGURE_H


#include<iostream>
using namespace std;

class Figure
{
private:

    char kind {'*'};
    int team {0};//0-empty 1-white 2-black
    bool mortality {true};
    int position[0][0];

public:
    Figure();
    ~Figure();

    char setKind(char newKind);

    char showKind();

    int setTeam(int number);
    int showTeam();

    bool setMortality();
    int setPosition();

    void move();
    bool isMoveValid();


};

#endif // FIGURE_H
