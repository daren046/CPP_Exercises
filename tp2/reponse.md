### Daren Tagnan 

#### Question 1
> 1. Définissez un attribut statique Player::turn_number qui servira à contenir le nombre de tours de la partie.
Quel mot-clef devez-vous utiliser pour transformer la déclaration de l'attribut en définition ?
 
> le mot clef static est utilisé pour transformer la déclaration de l'attribut en définition

```cpp

int Player::turn_number = 0;
```

#### Question 2

> 2. Ajoutez une fonction-membre statique Player::play prenant en paramètre les deux joueurs.
Dedans, vous afficherez les deux cartes jouées au tour courant. Vous incrémenterez le score du joueur qui remporte le pli (en cas d'égalité, pas de changement), puis vous augmenterez le nombre de tours.
La fonction renverra sous forme de booléen si la partie est terminée ou pas. Attention, cette fonction ne modifie pas le contenu de Player::_cards, n'essayez pas de supprimer des éléments du std::vector.

```cpp
bool Player::play(Player &p1, Player &p2)
{
    std::cout << "Tour " << Player::turn_number << std::endl;
    std::cout << p1._name << " joue " << p1._cards[Player::turn_number] << std::endl;
    std::cout << p2._name << " joue " << p2._cards[Player::turn_number] << std::endl;
    if (p1._cards[Player::turn_number] > p2._cards[Player::turn_number])
    {
        p1._score++;
    }
    else if (p1._cards[Player::turn_number] < p2._cards[Player::turn_number])
    {
        p2._score++;
    }
    Player::turn_number++;
    return Player::turn_number == p1._cards.size();
}
```
#### Question 3

>5. Enfin, définissez un getter dans Player permettant de récupérer le score de chaque joueur.
Assurez-vous qu'il puisse être utilisé sur des variables const.



### Question 4

> 4.Modifiez la fonction main pour simuler une partie de bataille entre Julien et Gerald.

```cpp

    Player p1{"Gerald"};
    Player p2{"Julien"};
    Player::deal_all_cards(p1, p2);


   while (!p1.play(p1,p2))
   {
         std::cout << "Score de " << p1.name() << " : " << p1.score() << std::endl;
         std::cout << "Score de " << p2.name() << " : " << p2.score() << std::endl;
         std::cout << std::endl;
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


```

### Question 5

> 5. (Bonus) A quoi sert la fonction std::this_thread::sleep_for ? Utilisez-la dans votre code pour qu'une seconde s'écoule entre chaque pli.


> lafonction std::this_thread::sleep_for permet de mettre en pause le programme pour un temps donné
```cpp
#include <chrono>

std::this_thread::sleep_for(std::chrono::seconds(1));

```


### Question 6

> 6. Modifiez votre code de manière à gérer l'égalité comme dans les règles officielles : on pose une carte face cachée, puis une carte face visible, et le gagnant remporte alors 3 points au lieu de 1.

```cpp
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
        if (p2._cards[Player::turn_number+1] <  p1._cards[Player::turn_number+1])
        {
            p1._score+=3;
        }
        else if (p1._cards[Player::turn_number+1] < p2._cards[Player::turn_number+1])
        {
            p2._score+=3;
        }
        Player::turn_number+=3;
        return Player::turn_number >= p1._cards.size();
        
    }
    Player::turn_number++;
    return Player::turn_number == p1._cards.size();
}


```