#include <iostream>
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::PrintIntro()
{
	std::cout << "Welcome to BULLS AND COWS\n";
	std::cout << "can you get the " << GetHiddenWordLength() << " letter isogram I'm thinking of in " << MyMaxTries << " guesses?\n";
	return;
}
void FBullCowGame::PlayGame()
{
	for (int i = 0; i < GetMaxTries(); i++)
	{
		//TODO make loop check valid
		GetGuess();
		//submit valid guess
		//print number of bulls and cows
		std::cout << std::endl;
	}
}
std::string FBullCowGame::GetGuess()
{

	std::cout << "Try " << GetCurrentTry() << ". Make a guess!\n";
	std::getline(std::cin, Guess);
	EGuessStatus status = CheckGuessValitity(Guess);
	do
	{
		switch (status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Guess was not an isogram\n";
			GetGuess();
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Guess was not the right length\n";
			GetGuess();
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Guess must be lowercase letters only\n";
			GetGuess();
			break;
		default:
			break;
		}
	} while (status != EGuessStatus::OK);
	FBullCowCount BullCowCount = SubmitGuess(Guess);
	std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << std::endl;

	return Guess;
}
EGuessStatus FBullCowGame::CheckGuessValitity(std::string guess) const
{
	EGuessStatus res = EGuessStatus::Not_Isogram;
	bool lengthMatch = guess.length() == GetHiddenWordLength();
	//if guess isn't isogram 
	if (false) {
		//return error
		return EGuessStatus::Not_Isogram;
	}
	//If guess isn't lower case
	else if (false) {
		//return error
		return EGuessStatus::Not_Lowercase;
	}
	//If guess length is wrong
	else if (lengthMatch) {
		//return error
		return EGuessStatus::Wrong_Length;
	}
	//otherwise
	else {
		//return ok

		return EGuessStatus::OK;
	}
}
FBullCowCount FBullCowGame::SubmitGuess(std::string guess)
{
	// receives a valid guess, increments turn counter and returns count
	//increment turn
	FBullCowCount BullCowCount;

	std::cout << "you guessed: " << Guess << std::endl;
	EGuessStatus status = CheckGuessValitity(guess);

	int hiddenWordLength = MyHiddenWord.length();
	//todo crashes when guess is shorter then secret word.
	for (int i = 0; i < hiddenWordLength; i++) {
		if (MyHiddenWord == guess) {
			std::cout << "BULLSEYE\n";
			GameWon = true;
			BullCowCount.Bulls = hiddenWordLength;
			return BullCowCount;
		}
		for (int j = 0; j < hiddenWordLength; j++) {
			if (guess[i] == MyHiddenWord[j]) 
			{
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}

			}
		}
	}
	MyCurrentTry++;
	return BullCowCount;
}
bool FBullCowGame::AskToPlayAgain()
{
	std::cout << "do you want to play again? (y/n) ";
	std::string res;
	std::getline(std::cin, res);
	return (toupper(res[0]) == 'Y');
}
void FBullCowGame::Reset()
{
	const std::string Hidden_Word = "poo";
	MyHiddenWord = Hidden_Word;
	MyMaxTries = GetHiddenWordLength() * 2;
	PrintIntro();

	MyCurrentTry = 1;

	return;
}

int FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::isGameWon()const { return false; }