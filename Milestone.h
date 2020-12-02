// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Milestone
{
    public:
        Milestone(string name, int milesFromStart, int type);
        string getName();
        void setName(string name);
        int getMilesFromStart();
        void setMilesFromStart(int milesFromStart);
        int getType();
        void setType(int type);        
        

    private:
        string name_;
        int milesFromStart_;
        int type_; //0 is Fort, 1 is Crossing, 2 is Landmark
};


