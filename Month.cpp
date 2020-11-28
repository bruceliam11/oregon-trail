// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Month.h"
#include <iostream>
#include <cmath>
using namespace std;

Month::Month(){
    setName("");
    setDay(0);
}

Month::Month(string name, int day){
    setName(name);
    setDay(day);
}

string Month::getName()      //month getter
{
    return name_;
}

void Month::setName(string name)  //month setter
{
    name_ = name;
}
 
int Month::getDay()       //day getter
{
    return day_;
}
void Month::setDay(int day)    //day setter
{
    day_ = day;
}


/*int main(){
    Month date("March",28);
    cout<<date.getName()<<" "<<date.getDay()<<endl;
}*/