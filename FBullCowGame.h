#pragma once
#include <string>

struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};
enum class EGuessStatus {
	OK,
	Wrong_Length
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
	std::string MyHiddenWord;
	FBullCowCount BCCount;
	std::string Guess;

};