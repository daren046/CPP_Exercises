#include <string>
#include <iostream>

class Card
{
    enum Color
    {
        Coeur, 
        Carreau,
        Pique,
        Trefle
    };

    enum Value
    {
        Sept,
        Huit,
        Neuf,
        Dix,
        Valet,
        Dame,
        Roi,
        As 
    };
    
public:
    Card(unsigned int value, const std::string &color);
    void print() const;
    int operator==(const Card &other) const;
    int operator<(const Card &other) const;
    friend std::ostream &operator<<(std::ostream &os, const Card &card);

private:
    unsigned int _value;
    std::string _color;
};
