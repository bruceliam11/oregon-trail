// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3
#include "Settlers.h"
#include "Store.h"
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    
    cout<<"THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROMINDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6MONTHS --- IF YOU MAKE IT ALIVE."<<endl<<endl;
    Settlers settlers;
    settlers.inputLeaderName();
    cout<<settlers.getLeaderName()<<endl;
    settlers.inputCompanionNames();
    settlers.printCompanionNames();
    settlers.printMoney();
    settlers.printMilesToGo();
    settlers.inputStartDate();
    //Store store(1.0);
    //settlers.visitStore(store);
    //buying items in store
    //Store fort1(1.25);
    //settlers.visitStore(fort1);
    return 0;
}