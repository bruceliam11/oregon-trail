// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Store.h"
#include <iostream>
#include <cmath>
using namespace std;

Store::Store(double markUp, 
            double oxenBasePrice, 
            double foodBasePrice, 
            double ammunitionBasePrice,
            double wagonPartBasePrice,
            double medKitBasePrice){
    markUp_ = markUp;
    oxenBasePrice_ = oxenBasePrice;
    foodBasePrice_ = foodBasePrice;
    ammunitionBasePrice_ =  ammunitionBasePrice;
    wagonPartBasePrice_ =  wagonPartBasePrice;
    medKitBasePrice_ = medKitBasePrice;
 
}

void Store::printWelcomeMessage()   //welcome message in store
{
    cout<<"Welcome to the store!"<<endl;
    cout<<"We have oxen for $"<<getOxenPrice()<<endl;
    cout<<"We have food for $"<<getFoodPrice()<<endl;
    cout<<"We have ammunition for $"<<getAmmunitionPrice()<<endl;
    cout<<"We have wagon parts for $"<<getWagonPartPrice()<<endl;
    cout<<"We have med kits for $"<<getMedKitPrice()<<endl;
}
double Store::getOxenPrice()  //price of oxen getter
{
    return oxenBasePrice_*markUp_;
}
double Store::getFoodPrice() //price of food getter
{
    return foodBasePrice_*markUp_;
}
double Store::getAmmunitionPrice()  //price of bullets getter
{
    return ammunitionBasePrice_*markUp_;
}
double Store::getWagonPartPrice()   //price of wagon parts getter
{
    return wagonPartBasePrice_*markUp_;
}
double Store::getMedKitPrice()    //price of med kit getter
{
    return medKitBasePrice_*markUp_;
}