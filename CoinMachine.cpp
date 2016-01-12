#include "CoinMachine.hpp"

CoinLimits::CoinLimits(void) {
	//Assume that we have ~1 foot long storage tubes
	//Calculated from information on http://www.usmint.gov/about_the_mint/?action=coin_specifications
	dollars = 152;
	halfDollars = 141;
	quarters = 174;
	dimes = 225;
	nickels = 156;
	pennies = 200;
}

CoinMachine::CoinMachine(void) {
	intakeLimit = 1.0;
}

CoinMachine::CoinMachine(double argIntakeLimit) {
	intakeLimit = argIntakeLimit;
}

CoinMachine::CoinMachine(double argIntakeLimit, Coins startingCoins) {
	intakeLimit = argIntakeLimit;
	AddToDispenser(startingCoins);
}

CoinMachine::CoinMachine(double argIntakeLimit, Coins startingCoins, CoinLimits argDispenserLimits) {
	intakeLimit = argIntakeLimit;
	dispenserLimits = argDispenserLimits;
	AddToDispenser(startingCoins);
}

void CoinMachine::AddToDispenser(Coins coinsToAdd) {
	//Trying to add coins to the dispenser. Need to make sure we don't overfill a tube.
	
	dispenser += coinsToAdd;	//Go ahead and add everything to the dispenser, first
	if(dispenser > dispenserLimits) {	//Are any tubes overfilled?
		//Okay, one of the coin tubes is more than full. Handle that.
		Coins overflowed;	//Store any overflowed coins, to add to the overflow container.
		
		//Figure out which tube(s) overflowed, and get the excess
		if(dispenser.dollars > dispenserLimits.dollars) {
			overflowed.dollars = (dispenser.dollars - dispenserLimits.dollars);
			dispenser.dollars = dispenserLimits.dollars;
		}
		if(dispenser.halfDollars > dispenserLimits.halfDollars) {
			overflowed.halfDollars = (dispenser.halfDollars - dispenserLimits.halfDollars);
			dispenser.halfDollars = dispenserLimits.halfDollars;
		}
		if(dispenser.quarters > dispenserLimits.quarters) {
			overflowed.quarters = (dispenser.quarters - dispenserLimits.quarters);
			dispenser.quarters = dispenserLimits.quarters;
		}
		if(dispenser.dimes > dispenserLimits.dimes) {
			overflowed.dimes = (dispenser.dimes - dispenserLimits.dimes);
			dispenser.dimes = dispenserLimits.dimes;
		}
		if(dispenser.nickels > dispenserLimits.nickels) {
			overflowed.nickels = (dispenser.nickels - dispenserLimits.nickels);
			dispenser.nickels = dispenserLimits.nickels;
		}
		if(dispenser.pennies > dispenserLimits.pennies) {
			overflowed.pennies = (dispenser.pennies - dispenserLimits.pennies);
			dispenser.pennies = dispenserLimits.pennies;
		}
		
		overflow += overflowed;	//Put the excess in the bucket
	}
}

void CoinMachine::AddToIntake(Coins coinsToAdd) {
	//Trying to add coins to the intake. Check that the total in the intake isn't already above the intakeLimit.
	if(intake.Total() >= intakeLimit) {
		//At or above the limit already
		return false;
	} else {
		//Not there yet, go ahead and add this coin to the intake
		intake += coinsToAdd;
		return true;
	}
}

void CoinMachine::Drop(Coins coinsToDrop) {
	Vector<string> 
}

void CoinMachine::Eject(void) {
	Drop(intake);	//Show the user what coins dropped out
	intake = new Coins;	//Reset the intake
}

void CoinMachine::Restock(Coins coinsToAdd) {
	AddToDispenser(coinsToAdd);
}

bool CoinMachine::ExactChangeOnly(void) {
	//Are there less than 3 quarters, 2 dimes, a nickel and 4 pennies?
	if(
		(dispenser.quarters < 3) ||
		(dispenser.dimes < 2) ||
		(dispenser.nickels < 1) ||
		(dispenser.pennies < 4)
	) {
		return true;
	} else {
		return false;
	}
}

