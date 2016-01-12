#ifndef __DRINK_HPP__
#define __DRINK_HPP__

#include <string>

//The Drink structure holds information about the name, cost and quantity of a drink.

struct Drink {
	string Name;
	double Cost;
	int Amount;
	
	Drink(void);	//Default constructor, puts default values in everything
	Drink(string argName, double argCost, int argAmount);	//Alternate constructor, puts real values in everything
};

#endif