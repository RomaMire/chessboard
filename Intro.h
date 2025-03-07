#ifndef INTRO_H
#define INTRO_H

#include<iostream>


using namespace std;


class Intro
{

private:
    double balance {0};
    string name;


public:
    void setName(string myName);
    string getName();
    double setBalance(double bal);
    double getBalance();

    Intro();
};

#endif // INTRO_H
