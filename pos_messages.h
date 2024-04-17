#ifndef POS_MESSAGES_H
#define POS_MESSAGES_H

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <memory>
#include <regex>

class PositiveMessages 
{
private:
    std::unique_ptr<std::vector<std::string>> messages;
    int consecutiveWins;

public:
    PositiveMessages();
    void update(bool win);
    std::string getMessage() const;
};

#endif // POS_MESSAGES_H
