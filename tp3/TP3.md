# TP2 - Ownership et durée de vie

## Objectifs

- Dessiner des graphes d'ownership pour comprendre la notion
- Utiliser des références

## Rappels du cours

<details>
<summary>Durée de vie</summary>

Les entités d'un programme C++ ont une **durée de vie**.

*Exemple*:
```
int main()
{
    int v = 3;          // "v" commence à exister
    if (v == 2)
    {
        char c = 'b';   // "c" commence à exister
        ...
    }                   // "c" finit d'exister

    ...
}                       // "v" finit d'exister
```
</details>

<details>
<summary>Lien entre composition et durée de vie</summary>

Si une entité "A" est constituée d'une entité "B", alors la destruction de l'entité "A" entraîne la destruction de l'entité "B".

*Exemple* : Une voiture est constituée de 4 roues. Si on détruit la voiture, on détruit également ses roues.
</details>

<details>
<summary>Lien entre ownership et durée de vie</summary>

Une entité A est **owner** d'une entité B si la destruction de A entraîne la destruction de B.

Par conséquence du paragraphe précédent, si une entité A est constituée d'une entité B, alors A est owner de B.

**Attention**  
La notion d'ownership dans un programme peut-être complètement décorrélé de la notion de propriété dans le monde réel !  
*Exemple* : John possède une voiture. Mais si on détruit John dans un programme, cela ne veut pas dire que la voiture va être détruite également.  
Si elle est détruite aussi, alors John own sa voiture. Si elle n'est pas détruite, alors John ne own pas sa voiture.

</details>

<details>
<summary>Graphe d'ownership</summary>

```cpp
struct Voiture
{
    Moteur      _moteur;
    std::string _marque;
};

struct Conducteur
{
    Voiture& _voiture;
};

void affiche_marque(Voiture& voiture)
{
    // <MARQUEUR> //
    std::cout << voiture.marque << std::endl;
}

int main()
{
    Voiture clio;
    Conducteur gontrand { voiture };
    affiche_marque(clio);
}
```

Graphe d'ownership à l'appel de `affiche_marque` par le `main` (cf `<MARQUEUR>`) :
![graph-1](tp3-graph-1.svg)

</details>

## Exercice 1 - Durée de vie

A faire avec l'ensemble du groupe.



1. Lorsque vous définissez une variable de type `int` dans une fonction, où le programme réserve-t-il de l'espace pour stocker la donnée ?
2. Considérez le code suivant :
```cpp
int main()
{
    int* ptr = nullptr;

    int i1 = 0;
    ptr = &i1;

    // <MARQUEUR 1>

    if (...)
    {
        int i2 = 3;
        ptr = &i2;
 
        for (...)
        {
            // <MARQUEUR 2>
        }
    }

    // <MARQUEUR 3>
}
```

a. Que fait l'instruction `ptr = &iX` ?  
b. A l'étape `<MARQUEUR 1>`, que contient `ptr` ? Quelle est la valeur de l'expression `*ptr` ?  
c. Mêmes questions pour `<MARQUEUR 2>` et `<MARQUEUR 3>` ?  
d. Pourquoi la durée de vie d'une variable locale se termine à la fin du scope dans lequel elle est définie ?

