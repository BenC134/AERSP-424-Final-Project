#include "function.h"
#include "hand.h"
#include "deck.h"
#include "card.h"
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

// Function to validate user input for bet amount using regular expressions
bool isValidBet(const std::string& input)
{
    // Regular expression pattern to match a positive floating-point number
    std::regex pattern("^\\d+(\\.\\d+)?$");

    // Check if the input matches the pattern
    return std::regex_match(input, pattern);
}

// Function to play Blackjack game
void playBlackjack(double money, unsigned int numDecks)
{
    Deck<Card> deck(6); // Create a deck of cards with 6 decks
    deck.shuffle(); // Shuffle the deck

    double bet; // Bet amount
    std::string betInput; // Input for bet amount
    PositiveMessages positiveMessages; // Object for managing positive messages

    while (money > 0)
    {
        std::cout << "\nMoney available: $" << money << std::endl;
        std::cout << "Enter your bet: ";
        std::cin >> betInput;

        if (!isValidBet(betInput))
        {
            std::cout << "Invalid bet amount. Please enter a valid number." << std::endl;
            continue;
        }

        bet = std::stod(betInput);

        if (bet > money)
        {
            std::cout << "You don't have enough money to bet that amount!" << std::endl;
            continue;
        }
        if (bet < 10)
        {
            std::cout << "Minimum bet is $10!" << std::endl;
            continue;
        }
        std::cout << "\n######################################################### \n\n";

        Hand playerHand, dealerHand; // Create hands for player and dealer
        playerHand.addCard(deck.draw()); // Deal two cards to player
        playerHand.addCard(deck.draw());
        dealerHand.addCard(deck.draw()); // Deal two cards to dealer
        dealerHand.addCard(deck.draw());

        // Sort the player's hand
        playerHand.sortCards();

        std::cout << "Your hand: ";
        playerHand.display();
        std::cout << "Your total: " << playerHand.getTotal() << std::endl;
        std::cout << "Dealer's hand: " << dealerHand.getVisibleCard() << " ?" << std::endl;

        if (playerHand.isBlackjack())
        {
            std::cout << "Congratulations! You got a Blackjack!" << std::endl;
            positiveMessages.update(true);
            std::cout << positiveMessages.getMessage() << std::endl; // Display positive message
            money += bet * 1.5; // Blackjack payout
            continue; // Proceed to next round
        }

        char choice;
        while (true)
        {
            std::cout << "\nDo you want to hit (h) or stand (s)? ";
            std::cin >> choice;
            if (choice == 'h')
            {
                playerHand.addCard(deck.draw());
                std::cout << "Your hand: ";
                playerHand.display();
                std::cout << "Your total: " << playerHand.getTotal() << std::endl;
                if (playerHand.isBusted())
                {
                    std::cout << "Busted! You lose." << std::endl;
                    positiveMessages.update(false); // Reset consecutive wins
                    money -= bet;
                    break;
                }
            }
            else if (choice == 's')
            {
                break;
            }
            else
            {
                std::cout << "Invalid choice. Please enter 'h' or 's'." << std::endl;
            }
        }

        if (playerHand.getTotal() <= 21)
        {
            std::cout << "Dealer's hand: ";
            dealerHand.display();
            std::cout << "Dealer total: " << dealerHand.getTotal() << std::endl;
            while (dealerHand.getTotal() < 17)
            {
                dealerHand.addCard(deck.draw());
                std::cout << "Dealer hits: ";
                dealerHand.display();
                std::cout << "Dealer total: " << dealerHand.getTotal() << std::endl;
            }
            if (dealerHand.isBusted() || playerHand.getTotal() > dealerHand.getTotal())
            {
                std::cout << "You win!" << std::endl;
                positiveMessages.update(true); // Increment consecutive wins
                std::cout << positiveMessages.getMessage() << std::endl; // Display positive message
                money += bet;
            }
            else if (playerHand.getTotal() < dealerHand.getTotal())
            {
                std::cout << "Dealer wins." << std::endl;
                positiveMessages.update(false); // Reset consecutive wins
                money -= bet;
            }
            else
            {
                std::cout << "It's a tie. Bet returned." << std::endl;
            }
        }
    }
    std::cout << "You are out of money. Game over!" << std::endl;
}