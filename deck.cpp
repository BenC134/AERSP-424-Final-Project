#include "deck.h"
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
Deck<CardType>::Deck(int numDecks)
{
    // Populate the deck with cards from multiple decks
    for (int i = 0; i < numDecks; ++i)
    {
        for (int j = Card::Ace; j <= Card::King; ++j)
        {
            for (int k = Card::Clubs; k <= Card::Spades; ++k)
            {
                cards.push_back(Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(k)));
            }
        }
    }
}

// Function to shuffle the deck
template<typename CardType>
void Deck<CardType>::shuffle()
{
    std::random_shuffle(cards.begin(), cards.end());
}

// Function to draw a card from the deck
template<typename CardType>
Card& Deck<CardType>::draw()
{
    Card& drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}
