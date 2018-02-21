#pragma once
#include <string>

struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};
enum class EGuessStatus {
	OK,
	Wrong_Length,
	Not_Isogram
};
class FBullCowGame {
public:
	FBullCowGame();

	void Reset(); 
	void PrintIntro();
	void PlayGame();
	bool AskToPlayAgain();

	void GetGuess();
	FBullCowCount SubmitValidGuess();
	EGuessStatus CheckGuessValitity() const;

	int GetHiddenWordLength() const;
	int GetMaxTries() const;
	int GetCurrentTry() const;
private:
	int MyCurrentTry = 1;
	int MyMaxTries = GetHiddenWordLength() * 2;
	bool isIsogram()const;
	std::string MyHiddenWord;
	FBullCowCount BCCount;
	std::string Guess;

};