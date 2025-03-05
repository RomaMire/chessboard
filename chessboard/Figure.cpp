#include "Figure.h"



#include<iostream>
using namespace std;


Figure::Figure(){};

Figure::~Figure(){};

char Figure:: showKind(){
    return kind;
};

char Figure:: setKind(char newKind){
    kind = newKind;
    return kind;
};

int Figure::setTeam(int number){
     team = number;
    return team;
};

int Figure::showTeam(){
    return team;
}

