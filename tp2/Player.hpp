#include <iostream>
#include <string>
#include <vector>
#include "Card.hpp"

class Player
{
public:
    Player(const std::string &name);
    static void deal_all_cards(Player &p1, Player &p2);
    const Card operator[](int index) const;
    friend std::ostream &operator<<(std::ostream &os, const Card &card);

private:
    std::string _name;
    std::vector<Card> _cards = {};
    unsigned int _score = 0;
};