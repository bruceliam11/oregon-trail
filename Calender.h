// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include "Month.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Calender
{
    public:
        Calender();
        Calender(int year);
        void addMonth(Month month);
        void printCalender();
        void setStartDate(Month startDate);
        void addElapsedDays(int daysElapsed);
        int findStartingMonthIndex();
        Month computeCurrentDate();


    private:
        vector<Month> months_;
        int year_;
        Month startDate_;
        int daysElapsed_;
};