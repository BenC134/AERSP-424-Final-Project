#include "hand.h"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

// Function to add a card to the hand using integer representation
void Hand::addCard(int rank, int suit)
{
    Card newCard(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
    cards.push_back(newCard);
}

// Function to add a card to the hand using Card object
void Hand::addCard(const Card& card)
{
    cards.push_back(card);
}

// Calculates total values of cards in hand
int Hand::getTotal() const
{
    int total = 0;
    bool hasAce = false;
    for (const auto& card : cards)
    {
        total += card.getValue();
        if (card.getValue() == 1)
        {
            hasAce = true;
        }
    }
    if (hasAce && total + 10 <= 21)
    {
        total += 10;
    }
    return total;
}

// Function to display the cards in the hand
void Hand::display() const
{
    for (const auto& card : cards)
    {
        std::cout << card.toString() << " ";
    }
    std::cout << std::endl;
}

// Function to get the string representation of the first card in the hand
std::string Hand::getVisibleCard() const
{
    if (!cards.empty())
    {
        return cards[0].toString();
    }
    return "";
}

// Virtual function to check if the hand has a Blackjack
bool Hand::isBlackjack() const
{
    return cards.size() == 2 && getTotal() == 21;
}

// Virtual function to check if the hand is busted (total value exceeds 21)
bool Hand::isBusted() const
{
    return getTotal() > 21;
}

// Virtual function to retrieve the amount of bet placed on the hand
double Hand::getBetAmount() const
{
    // Default implementation returns 0
    return 0.0;
}

// Function to sort the cards in the hand
void Hand::sortCards()
{
    std::sort(cards.begin(), cards.end(), [](const Card& a, const Card& b)
    {
        return a.getValue() < b.getValue();
    });
}

// Override isBlackjack to include specific conditions for PlayerHand
bool PlayerHand::isBlackjack() const
{
    // Check if the hand has a Blackjack according to PlayerHand rules
    return Hand::isBlackjack(); // For simplicity, PlayerHand follows the same rules as Hand
}
// Override getBetAmount to return the bet amount for the player hand
double PlayerHand::getBetAmount() const
{
    return betAmount;
}
// Function to set the bet amount for the player hand
void PlayerHand::setBetAmount(double amount)
{
    betAmount = amount;
}

// Override isBlackjack to include specific conditions for DealerHand
bool DealerHand::isBlackjack() const
{
    // Check if the hand has a Blackjack according to DealerHand rules
    return Hand::isBlackjack(); // For simplicity, DealerHand follows the same rules as Hand
}
// Override getBetAmount to return the bet amount for the dealer hand
double DealerHand::getBetAmount() const
{
    return betAmount;
}
// Function to set the bet amount for the dealer hand
void DealerHand::setBetAmount(double amount)
{
    betAmount = amount;
}
