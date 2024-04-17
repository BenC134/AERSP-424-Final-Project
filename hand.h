#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

class Hand {
public:
    void addCard(int rank, int suit);
    void addCard(const Card& card);
    int getTotal() const;
    void display() const;
    std::string getVisibleCard() const;
    virtual bool isBlackjack() const;
    virtual bool isBusted() const;
    virtual double getBetAmount() const;
    void sortCards();

private:
    std::vector<Card> cards;
};

class PlayerHand : public Hand {
private:
    double betAmount;

public:
    bool isBlackjack() const override;
    double getBetAmount() const override;
    void setBetAmount(double amount);
};

class DealerHand : public Hand {
private:
    double betAmount;

public:
    bool isBlackjack() const override;
    double getBetAmount() const override;
    void setBetAmount(double amount);
};

#endif // HAND_H
