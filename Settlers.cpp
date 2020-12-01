// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Settlers.h"
#include <iostream>
#include <cmath>
using namespace std;


Settlers::Settlers(){
    setMoney(1600.0);
    setMilesToGo(2040.0);
    oxen_ = 0;
    food_ = 0;
    bullets_ = 0;
    wagonParts_ = 0;
    medKits_ = 0;
}

//member functions

void Settlers::inputLeaderName()   //input name of player
{
    cout<<"What is the first name of the leader of the expedition?"<<endl;
    string leaderName;
    cin>>leaderName;
    setLeaderName(leaderName);
}
string Settlers::getLeaderName()   //player name getter
{
    return teamMemberNames_[0];
}

void Settlers::setLeaderName(string leaderName)  //player name setter
{
    teamMemberNames_.push_back(leaderName);
}
void Settlers::inputCompanionNames()  //input names of companions
{
    cout<<"What is the first name of your first companion?"<<endl;
    string companion1;
    cin>>companion1;
    cout<<"What is the first name of your second companion?"<<endl;
    string companion2;
    cin>>companion2;
    cout<<"What is the first name of your third companion?"<<endl;
    string companion3;
    cin>>companion3;
    cout<<"What is the first name of your fourth companion?"<<endl;
    string companion4;
    cin>>companion4;
    setCompanionNames(companion1,companion2,companion3,companion4);
}

void Settlers::printCompanionNames()  //prints out names (used for testing)
{
    cout<<"Your companions are: "
        <<teamMemberNames_[1]<<", "
        <<teamMemberNames_[2]<<", "
        <<teamMemberNames_[3]<<", "
        <<teamMemberNames_[4]<<endl;
}

void Settlers::setCompanionNames(string companion1, string companion2, string companion3, string companion4) //companion name setter
{
    teamMemberNames_.push_back(companion1);
    teamMemberNames_.push_back(companion2);
    teamMemberNames_.push_back(companion3);
    teamMemberNames_.push_back(companion4);
}

double Settlers::getMoney(){   //money getter
    return money_;
}

void Settlers::setMoney(double money){  //money setter
    money_ = money;
}

void Settlers::printMoney(){   //prints money (for testing)
    cout<<"You have $"<<money_<<" dollars remaining"<<endl;
}

double Settlers::getMilesToGo()  //miles remaining getter
{
    return milesToGo_;
}

void Settlers::printMilesToGo(){ 
    cout<<"You have "<<milesToGo_<<" miles left to go"<<endl;
}

void Settlers::setMilesToGo(double milesToGo)  //miles remaining setter
{
    milesToGo_ = milesToGo;
}

void Settlers::visitStore(Store store)  //when user enters store
{
    printMoney();
    store.printWelcomeMessage();
    store.setMoney(getMoney());
    double total = store.printMenu(oxen_,food_,bullets_,wagonParts_,medKits_);
    setMoney(getMoney()-total);
}

void Settlers::inputStartDate()
{
    int choice = 0;
    string month;
    int day = 0;
    int daysInMonth;
    while (choice>3 || choice<1)
    {
        cout<<"What month do you want to start your expedition?\n1.March\n2.April\n3.May"<<endl;
        cin>>choice;
    }
    if (choice==1)
    {
        month = "March";
        daysInMonth = 31;
    }
    else if (choice==2)
    {
        month = "April";
        daysInMonth = 30;
    }
    else
    {
        month = "May";
        daysInMonth = 31;
    }
    while (day>daysInMonth || day<1)
    {
        cout<<"What day do you want to leave in "<<month<<"? "<<month<<" has "<<daysInMonth<<" days."<<endl;
        cin>>day;
    }
    cout<<"Congratulations! You are about to embark on the epic journey from Independence, Mississippi to Oregon City, Oregon on "<<month<<" "<<day<<", 1847"<<endl;
    calender_.setStartDate(Month(month,day));
}



void Settlers::printSupplies()
{
	cout<<"Oxen: "<<oxen_<<"\nFood: "<<food_<<"\nBullets: "<<bullets_<<"\nWagon parts: "<<wagonParts_<<"\nMed Kits: "<<medKits_<<"\nCash: "<<money_<<endl;
}





Month Settlers::getCurrentDate()
{
	return calender_.computeCurrentDate();
}



int Settlers::getYear()
{
	return calender_.getYear();
}




void Settlers::addDaysElapsed(int daysElapsed)
{
	calender_.addElapsedDays(daysElapsed);
}





void Settlers::printStatus()
{
	cout<<endl<<endl;
	Month date = getCurrentDate();
    cout<<date.getName()<<" "<<date.getDay()<<", "<<getYear()<<endl;
    cout<<"Total mileage is "<<2040-getMilesToGo()<<endl;
    printSupplies();
    cout<<endl<<endl;
    
}

int Settlers::getMenuChoice()
{
	int choice;
	cout<<"Do you want to: \n1)Stop to rest\n2)Continue on the trail\n3)Hunt for food\n4)Quit"<<endl;
	cin>>choice;
	return choice;
}



void Settlers::continueOnTrail()
{
	int days = 14;
	addDaysElapsed(days);
	food_-= (teamMemberNames_.size()*3)*days;
	milesToGo_-=rand()%70+70;
	cout<<milesToGo_<<endl;
}



void Settlers::stopToRest()
{
	int days = rand()%3+1;
	cout<<days<<endl;
	addDaysElapsed(days);
	food_-= (teamMemberNames_.size()*3)*days;
}




void Settlers::huntForFood()
{
	int days = 1;
	int animalChoice;
	addDaysElapsed(days);
	bool encounteredRabbit = computeHuntEncounter(50);
	bool encounteredFox = computeHuntEncounter(25);
	bool encounteredDeer = computeHuntEncounter(15);
	bool encounteredBear = computeHuntEncounter(7);
	bool encounteredMoose = computeHuntEncounter(5);
	cout<<"You have encountered"<<endl;
	if (encounteredRabbit==true)
	{
		cout<<"1) a rabbit"<<endl;
	}
	if (encounteredFox==true)
	{
		cout<<"2) a fox"<<endl;
	}
	
	if (encounteredDeer==true)
	{
		cout<<"3) a deer"<<endl;
	}
	if (encounteredBear==true)
	{
		cout<<"4) a bear"<<endl;
	}
	if (encounteredMoose==true)
	{
		cout<<"5) a moose"<<endl;
	}
	if (encounteredRabbit==false && encounteredFox==false && encounteredDeer==false && encounteredBear==false && encounteredMoose==false){
		cout<<"nothing."<<endl;
		return;
	}
	cout<<"Which animal do you want to hunt for? Press 6 to exit"<<endl;
	cin>>animalChoice;
	if (bullets_<10)
	{
		cout<<"You did not have enough bullets. Hunt is unsuccessful"<<endl;
	}
	else if (animalChoice==1 && bullets_>=10)
	{
		int hunt = createPuzzle();
		if (hunt == 1)
		{
			food_+=5;
			bullets_-=10;
			computeHuntEating();
		}
	}
	else if (animalChoice==2 && bullets_>=10)
	{
		int hunt = createPuzzle();
		if (hunt == 1)
		{
			food_+=10;
			bullets_-=8;
			computeHuntEating();
		}
	}
	
	else if (animalChoice==3 && bullets_>=10)
	{
		int hunt = createPuzzle();
		if (hunt == 1)
		{
			food_+=60;
			bullets_-=5;
			computeHuntEating();
		}
	}
	else if (animalChoice==4 && bullets_>=10)
	{
		int hunt = createPuzzle();
		if (hunt == 1)
		{
			food_+=200;
			bullets_-=10;
			computeHuntEating();
		}
	}
	else if (animalChoice==5 && bullets_>=10)
	{
		int hunt = createPuzzle();
		if (hunt == 1)
		{
			food_+=500;
			bullets_-=12;
			computeHuntEating();
		}
	}
	else if (animalChoice == 6)
	{
		cout<<"You did not get any food"<<endl;
		return;
	}
	else{
		cout<<"Hunt unsuccessful"<<endl;
	}
}



bool Settlers::computeHuntEncounter(int probability)
{
	return (rand()%100)<probability;         
}



int Settlers::createPuzzle()
{
	int number = rand() % 10+1;
	int choice;
	int triesRemaining = 3;
	while (triesRemaining>0)
	{
		cout<<"I'm thinking of a number between 1 and 10. What number am I thinking of?"<<endl;
		cout<<number<<endl;
		cin>>choice;
		if (choice==number)
		{
			cout<<"Successful hunt!"<<endl;
			return 1;
		}
		else{
			cout<<"Incorrect. Guess again"<<endl;
			triesRemaining -= 1;
		}
	}
	cout<<"Hunt is unsuccessful"<<endl;
	return 0;
}




void Settlers::computeHuntEating()
{
	int foodChoice = 4;
	while (foodChoice!=0)
	{
		cout<<"Do you want to eat:\n1) Poorly\n2) Moderately\n3) Well"<<endl;
		cin>>foodChoice;
		if (foodChoice==1)
		{
			food_-=2*teamMemberNames_.size();
			foodChoice = 0;
		}
		else if (foodChoice==2)
		{
			food_-=3*teamMemberNames_.size();
			foodChoice = 0;
		}
		else if (foodChoice==3)
		{
			food_-=5*teamMemberNames_.size();
			foodChoice = 0;
		}
		else
		{
			cout<<"Not a valid option"<<endl;
		}

	}

}
