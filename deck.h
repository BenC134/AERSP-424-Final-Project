#ifndef DECK_H
#define DECK_H

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

template<typename CardType>
class Deck 
{
public:
    Deck(int numDecks);
    void shuffle();
    Card& draw();

private:
    std::deque<Card> cards;
};

#endif // DECK_H
