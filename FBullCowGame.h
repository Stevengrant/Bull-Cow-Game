#pragma once
#include <string>

struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};
enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};
class FBullCowGame {
public:

	FBullCowGame();
	void Reset(); 
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool isGameWon() const;
	EGuessStatus CheckGuessValitity(std::string) const;
	FBullCowCount SubmitGuess(std::string);
	void PrintIntro();
	bool AskToPlayAgain();
	std::string GetGuess();
	void PlayGame();
	int GetHiddenWordLength() const;
private:

	int MyCurrentTry = 1;
	int MyMaxTries = GetHiddenWordLength() * 2;
	bool GameWon = false;
	std::string MyHiddenWord;

	std::string Guess;

};