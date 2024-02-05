
#include "Player.hpp"
#include <iostream>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>   
int main()


{
    /*
        Card card(13, "Carreau");
        card.print();
        const Card c1{8, "Pique"};
        c1.print();
        const Card c2{8, "Carreau"};
        std::cout << (c2 == c1) << std::endl; // -> 1
        const Card c3{10, "Carreau"};
        std::cout << (c2 == c3) << std::endl; // -> 0
        std::cout << (c1 < c2) << std::endl;  // -> 0
        std::cout << (c1 < c3) << std::endl;  // -> 1
        std::cout << (c3 < c1) << std::endl;  // -> 0
        std::cout << c1 << std::endl;         // -> 8 de Pique
    */
    Player p1{"Gerald"};
    Player p2{"Julien"};
    Player::deal_all_cards(p1, p2);
    /*
    for (auto i = 0; i < 16; ++i)
    {
        p1[i].print();
        std::cout << std::endl;
        p2[i].print();
        std::cout << std::endl;
    }
    */

    while (!p1.play(p1,p2))
   {
         std::cout << "Score de " << p1.name() << " : " << p1.score() << std::endl;
         std::cout << "Score de " << p2.name() << " : " << p2.score() << std::endl;
         std::cout << std::endl;
        std::this_thread::sleep_for (std::chrono::seconds(1));
   }
   
    if (p1.score() > p2.score())
    {
        std::cout << p1.name() << " a gagné !" << std::endl;
    }
    else if (p1.score() < p2.score())
    {
        std::cout << p2.name() << " a gagné !" << std::endl;
    }
    else
    {
        std::cout << "Egalité !" << std::endl;
    }

    return 0;


}