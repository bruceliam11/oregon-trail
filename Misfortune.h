#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


class Misfortune
{
    public:
        Misfortune();
        void printBill();

        
    private:
        double computeBill();

        double price_;
        double quantity_;
        string type_;
};