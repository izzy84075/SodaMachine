#ifndef __COINMACHINE_HPP__
#define __COINMACHINE_HPP__

#include <iostream>
#include <vector>
#include <string>

#include "Coins.hpp"

struct CoinLimits {
	int dollars;
	int halfDollars;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
	
	CoinLimits(void);	//Assumes that we have 1 foot long storage tubes.
};

class CoinMachine {
	private:
		CoinLimits	dispenserLimits;	//How many coins the dispenser can hold
		Coins		dispenser;			//How many coins are in the dispenser?
		
		Coins		overflow;			//How many coins have overflowed the dispenser?
		
		double		intakeLimit;		//Maximum price of the drinks in the machine. Any coins past this limit will be spat back out immediately.
		Coins		intake;			//How many coins has the user put in?
		
		void AddToDispenser(Coins coinsToAdd);
		bool AddToIntake(Coins coinsToAdd);
		void Drop(Coins coinsToDrop);
		
	public:
		CoinMachine(void);	//Start with default values
		CoinMachine(double argIntakeLimit);	//Start with a given intake limit
		CoinMachine(double argIntakeLimit, Coins startingCoins);	//Start with some amount of coins
		CoinMachine(double argIntakeLimit, Coins startingCoins, CoinLimits argDispenserLimits);	//Start the machine with given limits/coins
		
		//Add various coins to the acceptor
		void AddDollar(void);
		void AddHalfdollar(void);
		void AddQuarter(void);
		void AddDime(void);
		void AddNickel(void);
		void AddPenny(void);
		
		//Check the total of what's in the intake
		double HowMuchMoneyInIntake(void);
		
		//Try to make a purchase of X amount and make change
		bool MakePurchase(double price);
		
		//Coin Return was pressed!
		void Eject(void);
		
		//"Restock" the machine
		void Restock(Coins coinsToAdd);
		
		//Is the Exact Change Only light on?
		bool ExactChangeOnly(void);
};

#endif