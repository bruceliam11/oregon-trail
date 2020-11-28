// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Milestone.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


/*Milestone::Milestone(string milestone, int milesFromStart){
}

//member functions

int Milestone::inputMilestoneNames()   //input name of player
{
    std::vector<string> milestones(0);
    ifstream inFile("milestones.txt");
    string line;
    int i = 0;
    while(getline(inFile,line)){
        milestones.push_back(i);
        i = i+2;
    }
    for (int j = 0; j<milestones.size(); j++){
        cout<<milestones(j)<<endl;
    }
    return 0;
}
int Milestone::inputMilesFromStart()   //player name getter
{
    std::vector<int> milesFromStart(0);
    ifstream inFile("milestones.txt");
    string line;
    int i = 1;
    while(getline(inFile,line)){
        milesFromStart.push_back(i);
        i = i+2;
    }
    for (int j = 0; j<milesFromStart.size(); j++){
        cout<<milesFromStart(j)<<endl;
    }
    return 0;
}*/


Milestone::Milestone(string name, int milesFromStart, int type){
    setName(name);
    setMilesFromStart(milesFromStart);
    setType(type);
}
string Milestone::getName(){
    return name_;
}
void Milestone::setName(string name){
    name_ = name;
}
int Milestone::getMilesFromStart(){
    return milesFromStart_;
}
void Milestone::setMilesFromStart(int milesFromStart){
    milesFromStart_ = milesFromStart;
}
int Milestone::getType(){
    return type_;
}
void Milestone::setType(int type){
    type_ = type;
}
int getMilesFromString(string miles){
    string mile = miles.substr(2,miles.length()-2);
    return stoi(mile);
}
int getTypeFromString(string name){
    if (name.substr(0,4) == "Fort"){
        return 0;
    }
    else if (name.substr(name.length()-8,8) == "Crossing"){
        return 1;
    }
    else{
        return 2;
    }
}
int getMilestoneLine(string &name, int &miles, int &type, ifstream &inFile){
    string milesToGo;
    if (getline(inFile, name)){
        if (getline(inFile, milesToGo)){
            miles = getMilesFromString(milesToGo);
            type = getTypeFromString(name);
            return 1;
        }
    }
    return 0;
}


/*int main(){
    Milestone milestone("River",204,2);
    cout<<milestone.getName()<<" "<<milestone.getMilesFromStart()<<" "<<milestone.getType()<<" "<<endl;
    vector<Milestone> milestones;
    Milestone first("Fort",1000,1);
    milestones.push_back(first);
    cout<<milestones[0].getName()<<" "<<milestones[0].getMilesFromStart()<<" "<<milestones[0].getType()<<" "<<endl;
    for (int i = 0; i<10; i++){
        milestones.push_back(Milestone("Fort",1000,1));
    }
    cout<<milestones[6].getName()<<milestones.size()<<endl;


    vector<Milestone> milestones;
    ifstream inFile("milestones.txt");
    string line;
    string name;
    int miles;
    int type;
    getMilestoneLine(name,miles,type,inFile);
    cout<<endl;
    cout<<name<<" "<<miles<<" "<<type<<endl;
    while(getMilestoneLine(name,miles,type,inFile)){
        milestones.push_back(Milestone(name,miles,type));
    }
    for (int i = 0; i<milestones.size(); i++){
        cout<<milestones[i].getName()<<milestones[i].getMilesFromStart()<<milestones[i].getType()<<endl;
    }
    // =========== testing getTypeFromString ==========
    //cout<<endl;
    //cout<<"fort: "<<getTypeFromString("Fort Laramie")<<endl;
    //cout<<"cross: "<<getTypeFromString("Flasfsdgasb Crossing")<<endl;
   // cout<<"other: "<<getTypeFromString("asdasgs")<<endl;
    // ============================================
    return 0;
}*/