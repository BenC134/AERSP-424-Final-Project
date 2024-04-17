#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

class Card 
{
public:
    enum Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    enum Suit { Clubs, Diamonds, Hearts, Spades };

    Card(Rank r, Suit s);
    int getValue() const;
    std::string toString() const;
    bool operator<(const Card& other) const;

private:
    Rank rank;
    Suit suit;
};

#endif // CARD_H
