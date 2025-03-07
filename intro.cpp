#include "Intro.h"

#include <iostream>
using namespace std;


Intro::Intro() {}

void Intro::setName(string myName){
    name = myName;
    cout<<myName<<endl;
};

string Intro::getName(){
    return name;
};

double Intro::setBalance(double bal){
    balance = bal;
};

double Intro::getBalance(){
    cout<<balance<<endl;
};
