// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include "Store.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Settlers
{
    public:
        Settlers();
        void inputLeaderName();
        string getLeaderName();
        void setLeaderName(string leaderName);
        void inputCompanionNames();
        void printCompanionNames();
        void setCompanionNames(string companion1, string companion2, string companion3, string companion4);
        double getMoney();
        void setMoney(double money);
        void printMoney();
        double getMilesToGo();
        void setMilesToGo(double milesToGo);
        void printMilesToGo();
        void visitStore(Store store);
        
        

    private:
        string leaderName_;
        string companion1_;
        string companion2_;
        string companion3_;
        string companion4_;
        double money_;
        double milesToGo_;
        //supplies (food, oxen, bullets, wagon parts)
        //Oxen oxen_;
        //Food food_;
        //Ammunition ammo_;
        //MiscSupply miscSupply_;
        //wagon
        //money
        //start date
};
