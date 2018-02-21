#include <iostream>
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
}

void FBullCowGame::Reset()
{
	const std::string Hidden_Word = "cake";
	MyHiddenWord = Hidden_Word;
	MyMaxTries = GetHiddenWordLength() * 2;
	PrintIntro();

	Guess = "";
	BCCount.Bulls = 0;
	BCCount.Cows = 0;
	MyCurrentTry = 1;

	return;
}
void FBullCowGame::PrintIntro()
{
	std::cout << "Welcome to BULLS AND COWS\n";
	std::cout << "Can you get the " << GetHiddenWordLength() << " letter isogram(word without repeating words) I'm thinking of in " << MyMaxTries << " guesses?\n";
	return;
}
void FBullCowGame::PlayGame()
{
	Reset();
	for (int i = 0; i < GetMaxTries(); i++)
	{
		if (BCCount.Bulls == GetHiddenWordLength()) {
			std::cout << "You Won!\n";
			return;
		}
		GetGuess();

		std::cout << std::endl;
	}
}
bool FBullCowGame::AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string res;
	std::getline(std::cin, res);
	return (toupper(res[0]) == 'Y');
}

void FBullCowGame::GetGuess()
{
	std::cout << "Try " << GetCurrentTry() << ". Make a guess!\n";
	std::string UnmodGuess;
	std::string fixedGuess;
	std::getline(std::cin, UnmodGuess);
	for (int i = 0; i < UnmodGuess.length(); i++) {
		fixedGuess += tolower(UnmodGuess[i]);
	}
	Guess = fixedGuess;

	EGuessStatus status = CheckGuessValitity();
	if (status == EGuessStatus::Wrong_Length) {
		std::cout << "Guess was not the right length.\n";
		GetGuess();
	}
	else if (status == EGuessStatus::Not_Isogram) {
		std::cout << "Guess was not an isogram (no double letters).\n";
		GetGuess();
	}
	else {
		MyCurrentTry++;
		BCCount = SubmitValidGuess();
		std::cout << "Bulls: " << BCCount.Bulls << " Cows: " << BCCount.Cows << std::endl;
	}
	return;
}
FBullCowCount FBullCowGame::SubmitValidGuess()
{
	FBullCowCount BullCowCount;
	//todo getting called twice
	int hiddenWordLength = MyHiddenWord.length();
	for (int i = 0; i < hiddenWordLength; i++) {
		for (int j = 0; j < hiddenWordLength; j++) {
			if (Guess[i] == MyHiddenWord[j])
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

	return BullCowCount;
}
EGuessStatus FBullCowGame::CheckGuessValitity() const
{
	//If guess length is wrong
	if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else if (!isIsogram()) {
		return EGuessStatus::Not_Isogram;
	}
	else {
		return EGuessStatus::OK;
	}
}

int FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::isIsogram() const
{
	//set up map
	TMap<char, bool> letters;
	//iterate over letters in guess
	for (auto letter : Guess) {
		if (letters[letter]) {return false;}
		else {letters[letter] = true;}
	}
	return true;
}
