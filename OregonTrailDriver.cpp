// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3
#include "Settlers.h"
#include "Store.h"
#include "Calender.h"
#include "Month.h"
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
    cout<<endl<<endl;
    while (health!=0)
    {
    	int initialChoice;    
        date = settlers.getCurrentDate();
        settlers.printStatus();
        //cout<<date.getName()<<" "<<date.getDay()<<", "<<settlers.getYear()<<endl;
        initialChoice = settlers.getMenuChoice();
        if (initialChoice == 1)
        {
        	settlers.stopToRest();
        }
        else if (initialChoice == 2)
        {
        	settlers.continueOnTrail();
		}
		else if(initialChoice == 3)
        {
        	settlers.huntForFood();
        }
        else{
        	cout<<"We hope you had a good time on the Oregon Trail!"<<endl;
        	health = 0;
        }
        //settlers.addDaysElapsed(14);
        //settlers.printStatus();
        //cout<<endl<<endl<<endl;
        //settlers.printMilesToGo();
    }
    //settlers.printMoney();
    //store.printMenu();
    //buying items in store
    //Store fort1(1.25);
    //settlers.visitStore(fort1);
    return 0;
}
