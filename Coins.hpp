#ifndef __COINS_HPP__
#define __COINS_HPP__

struct Coins {
	int dollars;
	int halfDollars;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
	
	inline double Total(void) {
		return ((dollars*1.0)+(halfdollars*0.5)+(quarters*0.25)+(dimes*0.1)+(nickels*0.05)+(pennies*0.01));
	}
	
	Coins operator+(Coins a) {
		return {a.dollars+dollars, a.halfDollars+halfDollars, a.quarters+quarters, a.dimes+dimes, a.nickels+nickels, a.pennies+pennies};
	}
	
	Coins operator-(Coins a) {
		return {a.dollars-dollars, a.halfDollars-halfDollars, a.quarters-quarters, a.dimes-dimes, a.nickels-nickels, a.pennies-pennies};
	}
	
	bool operator<(const Coins& left, const Coins& right) {
		if(
			(left.dollars < right.dollars) &&
			(left.halfDollars < right.halfDollars) &&
			(left.quarters < right.quarters) &&
			(left.dimes < right.dimes) &&
			(left.nickels < right.nickels) &&
			(left.pennies < right.pennies)
		) {
			return true;
		} else {
			return false;
		}
	}
	
	bool operator>(const Coins& left, const Coins& right) {
		return (right < left);
	}
	
	bool operator<=(const Coins& left, const Coins& right) {
		return !(left < right);
	}
	
	bool operator>=(const Coins& left, const Coins& right) {
		return !(right < left);
	}
};

#endif