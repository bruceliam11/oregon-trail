// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Supply
{
    public:
        Supply();
        void printBill();

        
    private:
        double computeBill();

        double price_;
        double quantity_;
        string type_;
};