#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

// Function to play Blackjack game
bool isValidBet(const std::string& input);
void playBlackjack(double money, unsigned int numDecks);

#endif // FUNCTION_H
