#include <iostream>
#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
bool FBullCowGame::isGameWon()const {return false;}
bool FBullCowGame::CheckGuessValitity(std::string) const { return false; }

void FBullCowGame::UpdateTrys(){ MyCurrentTry++;}
void FBullCowGame::Reset() { return; }