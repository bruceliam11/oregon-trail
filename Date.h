// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Month
{
    public:
        Month(string name, int day);
        string getName();
        void setName(string name);
        int getDay();
        void setDay(int day);


    private:
        string name_;
        int day_;
};