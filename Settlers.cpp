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
    oxen_ = 0;
    food_ = 0;
    bullets_ = 0;
    wagonParts_ = 0;
    medKits_ = 0;
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
    return teamMemberNames_[0];
}

void Settlers::setLeaderName(string leaderName)  //player name setter
{
    teamMemberNames_.push_back(leaderName);
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
        <<teamMemberNames_[1]<<", "
        <<teamMemberNames_[2]<<", "
        <<teamMemberNames_[3]<<", "
        <<teamMemberNames_[4]<<endl;
}

void Settlers::setCompanionNames(string companion1, string companion2, string companion3, string companion4) //companion name setter
{
    teamMemberNames_.push_back(companion1);
    teamMemberNames_.push_back(companion2);
    teamMemberNames_.push_back(companion3);
    teamMemberNames_.push_back(companion4);
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
    store.setMoney(getMoney());
    double total = store.printMenu(oxen_,food_,bullets_,wagonParts_,medKits_);
    setMoney(getMoney()-total);
}

void Settlers::inputStartDate()
{
    int choice = 0;
    string month;
    int day = 0;
    int daysInMonth;
    while (choice>3 || choice<1)
    {
        cout<<"What month do you want to start your expedition?\n1.March\n2.April\n3.May"<<endl;
        cin>>choice;
    }
    if (choice==1)
    {
        month = "March";
        daysInMonth = 31;
    }
    else if (choice==2)
    {
        month = "April";
        daysInMonth = 30;
    }
    else
    {
        month = "May";
        daysInMonth = 31;
    }
    while (day>daysInMonth || day<1)
    {
        cout<<"What day do you want to leave in "<<month<<"? "<<month<<" has "<<daysInMonth<<" days."<<endl;
        cin>>day;
    }
    cout<<"Congratulations! You are about to embark on the epic journey from Independence, Mississippi to Oregon City, Oregon on "<<month<<" "<<day<<", 1847"<<endl;
    calender_.setStartDate(Month(month,day));
}



void Settlers::printSupplies()
{
	cout<<"Oxen: "<<oxen_<<"\nFood: "<<food_<<"\nBullets: "<<bullets_<<"\nWagon parts: "<<wagonParts_<<"\nMed Kits: "<<medKits_<<endl;
}
