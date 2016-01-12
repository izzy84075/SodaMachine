#include "Drink.hpp"

Drink::Drink(void) {
	Name = "Unavailable";
	Cost = 0.0;
	Amount = 0;
}

Drink::Drink(string argName, double argCost, int argAmount) {
	Name = argName;
	Cost = argCost;
	Amount = argAmount;
}