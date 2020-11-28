// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Settlers.h"
#include <iostream>
#include <cmath>
using namespace std;


Settlers::Settlers(){
    setMoney(1600.0);
    setMilesToGo(2040.0);
}

//member functions

void Settlers::inputLeaderName()   //input name of player
{
    cout<<"What is the first name of the leader of the expedition?"<<endl;
    string leaderName;
    cin>>leaderName;
    setLeaderName(leaderName);
}
string Settlers::getLeaderName()   //player name getter
{
    return leaderName_;
}

void Settlers::setLeaderName(string leaderName)  //player name setter
{
    leaderName_ = leaderName;
}
void Settlers::inputCompanionNames()  //input names of companions
{
    cout<<"What is the first name of your first companion?"<<endl;
    string companion1;
    cin>>companion1;
    cout<<"What is the first name of your second companion?"<<endl;
    string companion2;
    cin>>companion2;
    cout<<"What is the first name of your third companion?"<<endl;
    string companion3;
    cin>>companion3;
    cout<<"What is the first name of your fourth companion?"<<endl;
    string companion4;
    cin>>companion4;
    setCompanionNames(companion1,companion2,companion3,companion4);
}

void Settlers::printCompanionNames()  //prints out names (used for testing)
{
    cout<<"Your companions are: "
        <<companion1_<<", "
        <<companion2_<<", "
        <<companion3_<<", "
        <<companion4_<<endl;
}

void Settlers::setCompanionNames(string companion1, string companion2, string companion3, string companion4) //companion name setter
{
    companion1_ = companion1;
    companion2_ = companion2;
    companion3_ = companion3;
    companion4_ = companion4;
}

double Settlers::getMoney(){   //money getter
    return money_;
}

void Settlers::setMoney(double money){  //money setter
    money_ = money;
}

void Settlers::printMoney(){   //prints money (for testing)
    cout<<"You have $"<<money_<<" dollars remaining"<<endl;
}

double Settlers::getMilesToGo()  //miles remaining getter
{
    return milesToGo_;
}

void Settlers::printMilesToGo(){ 
    cout<<"You have "<<milesToGo_<<" miles left to go"<<endl;
}

void Settlers::setMilesToGo(double milesToGo)  //miles remaining setter
{
    milesToGo_ = milesToGo;
}

void Settlers::visitStore(Store store)  //when user enters store
{
    printMoney();
    store.printWelcomeMessage();
}
