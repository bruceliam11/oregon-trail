// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Store
{
    public:
        Store(double markUp,
            double oxenBasePrice = 40.0, 
            double foodBasePrice = 0.5, 
            double ammunitionBasePrice = 2.0,
            double wagonPartBasePrice = 20.0,
            double medKitBasePrice = 25.0);
        void printWelcomeMessage();
        double printMenu(int &oxen, int &food, int &bullets, int &wagonParts, int &medKits);
        double getOxenPrice();
        double getFoodPrice();
        double getAmmunitionPrice();
        double getWagonPartPrice();
        double getMedKitPrice();
        double purchaseOxen(int &oxen);
        double purchaseFood(int &food);
        double purchaseAmmunition(int &bullets);
        double purchaseWagonParts(int &wagonParts);
        double purchaseMedKits(int &medKits);
        void setMoney(double money);
        double getMoney();


    private:
        double markUp_;
        double oxenBasePrice_;
        double foodBasePrice_;
        double ammunitionBasePrice_;
        double wagonPartBasePrice_;
        double medKitBasePrice_;
        double money_;   //money the leader has available  
};


