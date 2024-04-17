#include "card.h"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}
// Function to get the value of a card
int Card::getValue() const
{
    if (rank >= Jack && rank <= King)
    {
        return 10;
    }
        return rank;
}

// Function to convert card to string representation
std::string Card::toString() const
{
    std::string rankStr;
    if (rank >= Two && rank <= Ten)
    {
        rankStr = std::to_string(rank);
    }
    else
    {
        switch (rank)
        {
        case Ace:
            rankStr = "A";
            break;
        case Jack:
            rankStr = "J";
            break;
        case Queen:
            rankStr = "Q";
            break;
        case King:
            rankStr = "K";
            break;
        }
    }
    std::string suitStr;
    switch (suit)
        {
        case Clubs:
            suitStr = "-C";
            break;
        case Diamonds:
            suitStr = "-D";
            break;
        case Hearts:
            suitStr = "-H";
            break;
        case Spades:
            suitStr = "-S";
            break;
        }
    return rankStr + suitStr;
}

// Overload the < operator to compare cards based on rank
bool Card::operator<(const Card& other) const
{
    return rank < other.rank;
}
