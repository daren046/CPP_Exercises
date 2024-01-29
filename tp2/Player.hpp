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
    bool play(Player &p1, Player &p2);
    int score() const;
    std::string name() const;

private:
    std::string _name;
    std::vector<Card> _cards;
    unsigned int _score = 0;
    unsigned int turn_number = 0;
};