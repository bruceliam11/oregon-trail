#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum condition {Healthy,Typhoid,Cholera,Diarrhea,Measles,Dysentery,Fever,Dead}
class Player
{
    public:
        Player();

        string getName();
        void setName(string name);
        condition getState();
        void setState(condition state);

    private:
        string name_;
        condition state_;
        
        

};
