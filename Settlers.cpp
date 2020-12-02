// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Settlers.h"
#include "Milestone.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;


Settlers::Settlers(){
    setMoney(1600.0);
    setMilesToGo(2040.0);
    oxen_ = 0;
    food_ = 0;
    bullets_ = 0;
    wagonParts_ = 0;
    medKits_ = 0;
	loadMilestones();
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

int Settlers::getMilesToGo()  //miles remaining getter
{
    return milesToGo_;
}

void Settlers::printMilesToGo(){ 
    cout<<"You have "<<milesToGo_<<" miles left to go"<<endl;
}

void Settlers::setMilesToGo(int milesToGo)  //miles remaining setter
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
	cout<<"Oxen: "<<oxen_<<"\nFood: "<<food_<<"\nBullets: "<<bullets_<<"\nWagon parts: "<<wagonParts_<<"\nMed Kits: "<<medKits_<<"\nCash: "<<fixed<<setprecision(2)<<money_<<endl;
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



int Settlers::continueOnTrail()
{
	int days = 14;
	addDaysElapsed(days);
	food_-= (teamMemberNames_.size()*3)*days;
	int currentMilesFromStart = 2040-milesToGo_;
	int plannedTravelMiles=min((rand()%71+70),milestones_[0].getMilesFromStart()-currentMilesFromStart);
	milesToGo_-=plannedTravelMiles;
	if (food_<=0)
	{
		cout<<"Ran out of food. Game over."<<endl;
		return 0;
	}
	if (oxen_<=0)
	{
		cout<<"Ran out of oxen. Game over."<<endl;
		return 0;
	}
	if (wagonParts_<=0)
	{
		cout<<"Ran out of wagon parts. Game over."<<endl;
		return 0;
	}
	if (computeTotalTrailDays()==0)
	{
		cout<<"It's November 30 and you haven't made it to Oregon City. Game Over."<<endl;
		return 0;
	}
	if (plannedTravelMiles+currentMilesFromStart==milestones_[0].getMilesFromStart())
	{
		cout<<"You have reached "<<milestones_[0].getName()<<endl;
		milestones_.erase(milestones_.begin());
		if (milestones_.size()==0)
		{
			cout<<"Congratulations, you've finished the Oregon Trail!"<<endl;
			return 0;
		}
		else
		{
			cout<<"You are now heading to "<<milestones_[0].getName()<<". You are "<<milestones_[0].getMilesFromStart()<<" miles away"<<endl;
		}
		
	}
	else
	{
	}
	return 1;
	
	//int milesFromStart = 2040-milesToGo_+plannedTravelMiles;
	//milesToGo_ = getMilesTraveled(plannedTravelMiles, );
}



int Settlers::stopToRest()
{
	int days = rand()%3+1;
	//cout<<days<<endl;
	addDaysElapsed(days);
	food_-= (teamMemberNames_.size()*3)*days;
	if (food_<=0)
	{
		cout<<"Ran out of food. Game over."<<endl;
		return 0;
	}
	if (computeTotalTrailDays()==0)
	{
		cout<<"It's November 30 and you haven't made it to Oregon City. Game Over."<<endl;
		return 0;
	}
	return 1;
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


void Settlers::raiderAttack(){

	double M= double (2040.0-getMilesToGo());

	double a = ((M/100.0)-4.0);

	double b = (a*a)+72.0;

	double c = (a*a)+12.0;

	double prob = ((b/c)-1.0)/0.10;

    if (rand()%101<prob){
        
        cout << "RIDERS AHEAD! THEY LOOK HOSTILE!" << endl;

        int choice=0;
        while (choice >=0 and choice <=3){
            cout<<"Do you want to \n (1) Run. \n (2) Attack. \n (3) Surrender."<<endl;
            cin>>choice;
            if (choice==1){
                // The travelling party escapes with their lives but, in the hurry to flee the raiders, they leave behind 1 ox, 10 lbs. of food and 1 wagon part.
                oxen_ -= 1;
                food_ -= 10;
                wagonParts_ -= 1;
				cout<<"You and your companions managed to escape, but lost an oxen, 10 lbs of food, and a wagon part."<<endl;
                break;
            } 
			else if (choice==2){
                // In order to win the battle, the player must pass a puzzle (see the puzzle section later in the project description).
                cout << "Solve the puzzle in three attempts" << endl;
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
						food_ += 50;
                    	bullets_+= 50;
						cout<<"You beat the raiders! You and your party have gained 50 lbs of food and 50 bullets."<<endl;
						break;
					}
					else{
						cout<<"Incorrect. Guess again"<<endl;
						triesRemaining -= 1;
					}
				}
				if (choice!=number)
				{
					bullets_-= 50;
                    money_=(money_*3)/4;
					cout<<"You have lost the battle. You lose 50 bullets and a quarter of your money."<<endl;
				}
                break;
            } 
			else if (choice==3){
                // The travelling party loses a quarter of their cash reserves.
                money_= (money_*3)/4;
				cout<<"The raiders have spared your lives, but have taken a quarter of your remaining cash."<<endl;
                break;
            }
            else{
                cout<<"Invalid choice"<<endl;
            }
    
    	}
	}
}





void Settlers::loadMilestones()
{
	ifstream inFile("milestones.txt");
    string line;
    string name;
    int miles;
    int type;
    while(getMilestoneLine(name,miles,type,inFile)){
    	milestones_.push_back(Milestone(name,miles,type));
    }

}

  
int Settlers::getMilesFromString(string miles)
{
    string mile = miles.substr(2,miles.length()-2);
    return stoi(mile);
}
int Settlers::getTypeFromString(string name){
    if (name.substr(0,4) == "Fort"){
        return 0;
    }
    else if (name.substr(name.length()-8,8) == "Crossing")
	{
        return 1;
    }
    else{
        return 2;
    }
}
int Settlers::getMilestoneLine(string &name, int &miles, int &type, ifstream &inFile)
{
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


int Settlers::computeTotalTrailDays()
{
	Month currentDate = getCurrentDate();
	Month endingDate("November",30);
	if (endingDate.getName()==currentDate.getName() && endingDate.getDay()<=currentDate.getDay())
	{
		//currentDate.getDay() = endingDate.getDay();
		return 0;
	}
	else
	{
		return 1;
	}
	
}


//TODO: function to calculate distance from fort, if distance traveled on that day is greater than distance to fort -> miles traveled = milestone distance from start, pop off milestone from vector