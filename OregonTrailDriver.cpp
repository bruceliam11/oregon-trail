// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3
#include "Settlers.h"
#include "Store.h"
#include "Calender.h"
#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int health = 1;
    cout<<"THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROMINDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6MONTHS --- IF YOU MAKE IT ALIVE."<<endl<<endl;
    Settlers settlers;
    Month date;
    settlers.inputLeaderName();
    //cout<<settlers.getLeaderName()<<endl;
    settlers.inputCompanionNames();
    settlers.printCompanionNames();
    settlers.printMoney();
    settlers.printMilesToGo();
    settlers.inputStartDate();
    Store store(1.0);
    settlers.visitStore(store);
    settlers.printSupplies();
    while (health!=0)
    {
        cout<<date.computeCurrentDate()<<endl;
        settlers.printMilesToGo();
        
        health = 0;
    }
    //settlers.printMoney();
    //store.printMenu();
    //buying items in store
    //Store fort1(1.25);
    //settlers.visitStore(fort1);
    return 0;
}
