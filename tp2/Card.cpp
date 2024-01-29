#include "Card.hpp"

Card::Card(unsigned int value, const std::string &color) : _value(value), _color(color) {}

int Card::operator==(const Card &other) const
{
    return _value == other._value;
}

int Card::operator<(const Card &other) const
{
    return _value < other._value;
}

void Card::print() const
{
    switch (_value)
    {
    case 11:
        std::cout << "Valet";
        break;
    case 12:
        std::cout << "Dame";
        break;

    case 13:
        std::cout << "Roi";
        break;
    case 14:
        std::cout << "as";
        break;
    default:
        std::cout << _value;
        break;
    }
    std::cout << " de " << _color << std::endl;
}
/*
std::ostream &operator<<(std::ostream &os, const Card &card)
{
    switch (card._value)
    {
    case 1:
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
*/