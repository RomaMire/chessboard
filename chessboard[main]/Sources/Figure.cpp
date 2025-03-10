#include "Figure.h"
#include<iostream>
using namespace std;


Figure::Figure(char newKind, int newTeam): kind(newKind), team(newTeam){};//important strange structure

Figure::~Figure(){};


char Figure::showKind(){
    return kind;
};

int Figure::showTeam(){
    return team;
}


//bool isValidMove();





