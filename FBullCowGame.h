#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); //todo
	int GetMaxTries() const; //todo
	int GetCurrentTry() const;
	bool isGameWon() const;
	bool CheckGuessValitity(std::string) const;
	void UpdateTrys();

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;

};