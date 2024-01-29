#include "Player.hpp"
#include <algorithm>
#include <random>

Player::Player(const std::string &name) : _name(name) {}


void Player::deal_all_cards(Player &p1, Player &p2)
{
    std::vector<Card> all_cards;
    std::string colors[] = {"Coeur", "Carreau", "Pique", "Trefle"};
    std::vector<unsigned int> values = {7, 8, 9, 10, 11, 12, 13, 14};

    for (auto &color : colors)
    {
        for (auto &value : values)
        {
            all_cards.emplace_back(value, color);
        }
    }

    std::random_device rd;
    std::shuffle(all_cards.begin(), all_cards.end(), std::default_random_engine(rd()));

    int half = all_cards.size() / 2;
    for (auto i = 0; i < half; ++i)
    {
        p1._cards.push_back(all_cards[i]);
    }
    for (auto i = half; i < all_cards.size(); ++i)
    {
        p2._cards.push_back(all_cards[i]);
    }
}
std::ostream &operator<<(std::ostream &os, const Card &card)
{
    switch (card._value)
    {
    case 14:
        os << "As";
        break;
    case 11:
        os << "Valet";
        break;
    case 12:
        os << "Dame";
        break;
    case 13:
        os << "Roi";
        break;
    default:
        os << card._value;
        break;
    }
    os << " de " << card._color;
    return os;
}

const Card Player::operator[](int index) const
{
    return _cards[index];
}

bool Player::play(Player &p1, Player &p2)
{
    std::cout << "Tour " << Player::turn_number << std::endl;
    std::cout << p1._name << " joue " << p1._cards[Player::turn_number] << std::endl;
    std::cout << p2._name << " joue " << p2._cards[Player::turn_number] << std::endl;
    if (p2._cards[Player::turn_number] <  p1._cards[Player::turn_number])
    {
        p1._score++;
    }
    else if (p1._cards[Player::turn_number] < p2._cards[Player::turn_number])
    {
        p2._score++;
    }else{
        if(Player::turn_number + 3  > p1._cards.size()){
                Player::turn_number++;
                return Player::turn_number == p1._cards.size();
        }
        std::cout << "Egalité !" << std::endl;
        std::cout << p1._name << " joue " << p1._cards[Player::turn_number+1] << std::endl;
        std::cout << p2._name << " joue " << p2._cards[Player::turn_number+1] << std::endl;
        if (p2._cards[Player::turn_number+2] <  p1._cards[Player::turn_number+2])
        {
            p1._score+=3;
        }
        else if (p1._cards[Player::turn_number+2] < p2._cards[Player::turn_number+2])
        {
            p2._score+=3;
        }
        Player::turn_number+=3;
        return Player::turn_number >= p1._cards.size();
        
    }
    Player::turn_number++;
    return Player::turn_number == p1._cards.size();
}

int Player::score() const
{
    return _score;
}

std::string Player::name() const
{
    return _name;
}