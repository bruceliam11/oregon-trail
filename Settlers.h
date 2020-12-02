// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include "Store.h"
#include "Calender.h"
#include "Month.h"
#include "Milestone.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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
        int getMilesToGo();
        void setMilesToGo(int milesToGo);
        void printMilesToGo();
        void visitStore(Store store);
        void inputStartDate();
        void printSupplies();
        Month getCurrentDate();
        int getYear();
        void addDaysElapsed(int daysElapsed);
		void printStatus();
		int getMenuChoice();
		int continueOnTrail();
		int stopToRest();
		void huntForFood();
		bool computeHuntEncounter(int probability);
		int createPuzzle();
		void computeHuntEating();
        void raiderAttack();
        void loadMilestones();
        int getMilesFromString(string miles);
        int getTypeFromString(string name);
        int getMilestoneLine(string &name, int &miles, int &type, ifstream &inFile);
        int computeTotalTrailDays();
        
        

    private:
        vector<string> teamMemberNames_;
        double money_;
        int oxen_;   //number of oxen
        int food_;   //pounds of food
        int bullets_;  //number of boxes
        int wagonParts_;  //number of wagon parts
        int medKits_;      //number of med kits
        int milesToGo_;
        Calender calender_;
        vector<Milestone> milestones_;
        //supplies (food, oxen, bullets, wagon parts)
        //Oxen oxen_;
        //Food food_;
        //Ammunition ammo_;
        //MiscSupply miscSupply_;
        //wagon
        //money
        //start date
};
