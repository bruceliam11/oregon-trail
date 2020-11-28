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
        double getOxenPrice();
        double getFoodPrice();
        double getAmmunitionPrice();
        double getWagonPartPrice();
        double getMedKitPrice();


    private:
        double markUp_;
        double oxenBasePrice_;
        double foodBasePrice_;
        double ammunitionBasePrice_;
        double wagonPartBasePrice_;
        double medKitBasePrice_;
};


