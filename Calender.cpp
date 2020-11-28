// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Calender.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


Calender::Calender()
{
    year_ = 1847;
    daysElapsed_ = 0;
    //add months to calender
    addMonth(Month("January", 31));
    addMonth(Month("February", 28));
    addMonth(Month("March", 31));
    addMonth(Month("April", 30));
    addMonth(Month("May", 31));
    addMonth(Month("June", 30));
    addMonth(Month("July", 31));
    addMonth(Month("August", 31));
    addMonth(Month("September", 30));
    addMonth(Month("October", 30));
    addMonth(Month("November", 30));
    addMonth(Month("December", 31));
}

Calender::Calender(int year){
    year_ = year;
    daysElapsed_ = 0;
}

void Calender::addMonth(Month month)      //month getter
{
    months_.push_back(month);

}

void Calender::printCalender()
{
    for (int i = 0; i<months_.size(); i++){
        cout<<months_[i].getName()<<" "<<months_[i].getDay()<<endl;
    }
}

void Calender::setStartDate(Month startDate)
{
    startDate_ = startDate;
}


void Calender::addElapsedDays(int daysElapsed)
{
    daysElapsed_+=daysElapsed;
}


int Calender::findStartingMonthIndex()
{
    if (startDate_.getName() == "January"){
        return 0;
    }
    else if (startDate_.getName() == "February"){
        return 1;
    }
    else if (startDate_.getName() == "March"){
        return 2;
    }
    else if (startDate_.getName() == "April"){
        return 3;
    }
    else if (startDate_.getName() == "May"){
        return 4;
    }
    else if (startDate_.getName() == "June"){
        return 5;
    }
    else if (startDate_.getName() == "July"){
        return 6;
    }
    else if (startDate_.getName() == "August"){
        return 7;
    }
    else if (startDate_.getName() == "September"){
        return 8;
    }
    else if (startDate_.getName() == "October"){
        return 9;
    }
    else if (startDate_.getName() == "November"){
        return 10;
    }
    else{
        return 11;
    }
}



Month Calender::computeCurrentDate()
{
    int i = findStartingMonthIndex();
    int remainingDays = daysElapsed_+startDate_.getDay();
    while ((remainingDays - months_[i].getDay()) > 0)
    {
        remainingDays = remainingDays - months_[i].getDay();
        i++;
    }
    return Month(months_[i].getName(),remainingDays);
}


/*int main(){
    Calender calender(1847);
    calender.addMonth(Month("January", 31));
    calender.addMonth(Month("February", 28));
    calender.addMonth(Month("March", 31));
    calender.addMonth(Month("April", 30));
    calender.addMonth(Month("May", 31));
    calender.addMonth(Month("June", 30));
    calender.addMonth(Month("July", 31));
    calender.addMonth(Month("August", 31));
    calender.addMonth(Month("September", 30));
    calender.addMonth(Month("October", 30));
    calender.addMonth(Month("November", 30));
    calender.addMonth(Month("December", 31));
    
    calender.setStartDate(Month("March",28));
    calender.addElapsedDays(90);
    Month currentDate = calender.computeCurrentDate();
    cout<<currentDate.getName()<<" "<<currentDate.getDay()<<endl;
    calender.addElapsedDays(90);
    currentDate = calender.computeCurrentDate();
    cout<<currentDate.getName()<<" "<<currentDate.getDay()<<endl;
}*/