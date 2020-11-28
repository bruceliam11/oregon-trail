// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Inventory.h"
#include <iostream>
#include <cmath>
using namespace std;

Inventory::Inventory( 
            int oxenNum, 
            int foodNum, 
            int ammunitionNum,
            int wagonPartsNum,
            int medKitNum){}

int Inventory::getOxenNum()   //number of oxen getter
{
    return oxenNum_;
}

void Inventory::setOxenNum(int oxenNum)    //number of oxen setter
{
    oxenNum_ = oxenNum;
    cout<<"You have "<<oxenNum_<<" oxen"<<endl;
}
int Inventory::getFoodNum()     //number of pounds of food getter
{
    return foodNum_;
}
void Inventory::setFoodNum(int foodNum)   //number of pounds of food setter
{
    foodNum_ = foodNum;
    cout<<"You have "<<foodNum_<<" pounds of food"<<endl;
}
int Inventory::getAmmunitionNum()  //number of bullets getter
{
    return ammunitionNum_;
}
void Inventory::setAmmunitionNum(int ammunitionNum)  //number of bullets setter
{
    ammunitionNum_ = ammunitionNum;
    cout<<"You have "<<ammunitionNum_<<" bullets"<<endl;
}
int Inventory::getWagonPartsNum()  //number of wagon parts getter
{
    return wagonPartsNum_;
}
void Inventory::setWagonPartsNum(int wagonPartsNum)   //number of wagon parts setter
{
    wagonPartsNum_ = wagonPartsNum;
    cout<<"You have "<<wagonPartsNum_<<" wagon"<<endl;
}
int Inventory::getMedKitNum()    //number of med kits getter
{
    return medKitNum_;
}
void Inventory::setMedKitNum(int medKitNum)   //number of med kits setter
{
    medKitNum_ = medKitNum;
    cout<<"You have "<<medKitNum_<<" med kits"<<endl;
}


int main(){
    return 0;
}