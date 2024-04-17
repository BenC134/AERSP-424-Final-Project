#include "pos_messages.h"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

// Constructor for PositiveMessages class
PositiveMessages::PositiveMessages() : messages(std::make_unique<std::vector<std::string>>()), consecutiveWins(0)
{
    // Initialize positive messages
    messages->push_back("You're on a winning streak!");
    messages->push_back("Keep it up! You're doing great!");
    messages->push_back("Nice job! You're unbeatable!");
}

// Function to update consecutive wins and messages
void PositiveMessages::update(bool win)
{
    if (win)
    {
        consecutiveWins++;
        if (consecutiveWins >= messages->size())
            consecutiveWins = messages->size() - 1; // Avoid index out of bounds
    }
    else
    {
        consecutiveWins = 0; // Reset consecutive wins if the player loses
    }
}

// Function to get a positive message based on consecutive wins
std::string PositiveMessages::getMessage() const
{
    return (*messages)[consecutiveWins];
}