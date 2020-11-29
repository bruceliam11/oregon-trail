// CS1300 Fall 2020
// Author: Liam Smith
// Recitation: 510 - Edwards
// Project 3 Skeleton
#include "Store.h"
#include <iostream>
#include <cmath>
using namespace std;

Store::Store(double markUp, 
            double oxenBasePrice, 
            double foodBasePrice, 
            double ammunitionBasePrice,
            double wagonPartBasePrice,
            double medKitBasePrice){
    markUp_ = markUp;
    oxenBasePrice_ = oxenBasePrice;
    foodBasePrice_ = foodBasePrice;
    ammunitionBasePrice_ =  ammunitionBasePrice;
    wagonPartBasePrice_ =  wagonPartBasePrice;
    medKitBasePrice_ = medKitBasePrice;
 
}

void Store::printWelcomeMessage()   //welcome message in store
{
    cout<<"Welcome to the store!"<<endl;
    
}
double Store::printMenu(int &oxen, int &food, int &bullets, int &wagonParts, int &medKits)
{
	int choice = 0;
	double total = 0.0;
    while (choice!=6)
    {
        cout<<"What would you like to buy?\n1.Oxen........$"<<getOxenPrice()<<"\n2.Food........$"<<getFoodPrice()<<"\n3.Ammunition.....$"<<getAmmunitionPrice()<<"\n4.Wagon Parts....$"<<getWagonPartPrice()<<"\n5.Medical Kits...$"<<getMedKitPrice()<<endl;
        cout<<"Press 6 to exit"<<endl;
        cin>>choice;
        cout<<"You have $"<<getMoney()-total<<" left."<<endl;
		if (choice==1)
		{
		    total+=purchaseOxen(oxen);
		}
		else if (choice==2)
		{
		    total+=purchaseFood(food);
		}
		else if (choice==3)
		{
		    total+=purchaseAmmunition(bullets);
		}
		else if (choice==4)
		{
		    total+=purchaseWagonParts(wagonParts);
		}
		else if (choice==5)
		{
			total+=purchaseMedKits(medKits);
		}
	}
	cout<<"Thank you for shopping. Have a safe journey!"<<endl;
	return total;
}

double Store::getOxenPrice()  //price of oxen getter
{
    return oxenBasePrice_*markUp_;
}
double Store::getFoodPrice() //price of food getter
{
    return foodBasePrice_*markUp_;
}
double Store::getAmmunitionPrice()  //price of bullets getter
{
    return ammunitionBasePrice_*markUp_;
}
double Store::getWagonPartPrice()   //price of wagon parts getter
{
    return wagonPartBasePrice_*markUp_;
}
double Store::getMedKitPrice()    //price of med kit getter
{
    return medKitBasePrice_*markUp_;
}



double Store::purchaseOxen(int &oxen)
{
	int amount=1;
	int price=0;
	while (amount!=0)
	{
		cout<<"How many yokes of oxen would you like to buy? You must buy between 3 and 5 yokes of oxen. Each yoke is $"<<getOxenPrice()<<endl;
		cout<<"Press 0 to exit"<<endl;
		cin>>amount;
		if (amount==0)
		{
			break;
		}
		else if (amount<3 || amount>5)
		{
			cout<<"Must buy between 3 and 5 yokes"<<endl;
		}
		else{
			price += amount*getOxenPrice();
			oxen+=2*amount;
			cout<<"current oxen total: $"<<price<<endl;
		}
	}
	cout<<"total oxen price: $"<<price<<endl;
	return price;
}

double Store::purchaseFood(int &food)
{
	int amount=1;
	int price=0;
	while (amount!=0)
	{
		cout<<"How many pounds of food do you want to buy. You should buy at least 200lbs of food. Each pound of food is $"<<getFoodPrice()<<endl;
		cout<<"Press 0 to exit"<<endl;
		cin>>amount;
		if (amount==0)
		{
			break;
		}
		else
		{
			food+=amount;
			price += amount*getFoodPrice();
			cout<<"current food total: $"<<price<<endl;
		}
	}
	cout<<"total food price: $"<<price<<endl;
	return price;
}

double Store::purchaseAmmunition(int &bullets)
{
	int amount=1;
	int price=0;
	while (amount!=0)
	{
		cout<<"How many boxes of bullets do you want to buy? A box of 20 bullets costs $"<<getAmmunitionPrice()<<endl;
		cout<<"Press 0 to exit"<<endl;
		cin>>amount;
		if (amount==0)
		{
			break;
		}
		else
		{
			bullets += 20*amount;
			price += amount*getAmmunitionPrice();
			cout<<"current ammo total: $"<<price<<endl;
		}
	}
	cout<<"total ammo price: $"<<price<<endl;
	return price;
}

double Store::purchaseWagonParts(int &wagonParts)
{
	int amount=1;
	int price=0;
	while (amount!=0)
	{
		cout<<"How many wagon parts do you want to buy? Each wagon part is $"<<getWagonPartPrice()<<endl;
		cout<<"Press 0 to exit"<<endl;
		cin>>amount;
		if (amount==0)
		{
			break;
		}
		else
		{
			wagonParts += amount;
			price += amount*getWagonPartPrice();
			cout<<"current wagon parts total: $"<<price<<endl;
		}
	}
	cout<<"total wagon parts price: $"<<price<<endl;
	return price;
}


double Store::purchaseMedKits(int &medKits)
{
	int amount=1;
	int price=0;
	while (amount!=0)
	{
		cout<<"How many medical kits do you want to buy? Each med kit is $"<<getMedKitPrice()<<endl;
		cout<<"Press 0 to exit"<<endl;
		cin>>amount;
		if (amount==0)
		{
			break;
		}
		else
		{
			medKits += amount;
			price += amount*getMedKitPrice();
			cout<<"current med kit total: $"<<price<<endl;
		}
	}
	cout<<"total med kit price: $"<<price<<endl;
	return price;
}



void Store::setMoney(double money)
{
	money_ = money;
}


double Store::getMoney()
{
	return money_;
}
