// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory
{
    public:
        Inventory(
            int oxenNum = 0, 
            int foodNum = 0, 
            int ammunitionNum = 0,
            int wagonPartsNum = 0,
            int medKitNum = 0);
        int getOxenNum();
        void setOxenNum(int oxenNum);
        int getFoodNum();
        void setFoodNum(int foodNum);
        int getAmmunitionNum();
        void setAmmunitionNum(int ammunitionNum);
        int getWagonPartsNum();
        void setWagonPartsNum(int wagonPartsNum);
        int getMedKitNum();
        void setMedKitNum(int medKitNum);


    private:
        int oxenNum_;
        int foodNum_;
        int ammunitionNum_;
        int wagonPartsNum_;
        int medKitNum_;
};