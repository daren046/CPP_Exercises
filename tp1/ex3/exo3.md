## Exo 3 

1. Parlez de vos différents blocages avec le restant de la classe et discutez des solutions.

2. Expliquez la différence entre phase de build (compilation) et phase de link (édition des liens).  
En quoi consiste la précompilation et à quel moment est-elle effectuée ?
> La difference entre la phase de build et la phase de link est que durant la phase de buls nous allons compilez les fichier exec et durant la phase de link nous allons lier les fichier objet entre eux pour creer un executable. La précompilation est effectué avant la compilation et permet de remplacer les include par le contenu des fichier include.
3. Que signifient les messages suivants ?  
a.error: 'qqchose' was not declared in this scope  
> qqchose n'est pas déclaré dans ce scope

b. error: 'qqchose' is not a member of 'std' 

> elle n'est pas dans la table des symboles  qqchose n'est pas un membre de std 


Ces erreurs se produisent-elles pendant la phase de build ou de link ? 

> elle se produit lors du build 

Que fait exactement l'instruction préprocesseur `#include` et pourquoi permet-elle généralement de résoudre ce type de problème ?

>elle permet d'inclure le contenu d'un fichier dans un autre fichier

4. Compilez le programme de l'exercice en ne linkant que le fichier-objet associé à `main.cpp` (c'est-à-dire en oubliant `utils.cpp`).  
Quelle est l'erreur qui s'affiche ?    
En quoi est-elle différente des erreurs de la question précédente ?  
Expliquez ce qu'elle signifie exactement.

> elle se produit lors du link l'erreur qui s'affiche est : undefined reference to `print_bye()' elle signifie que la fonction print_bye n'est pas définie dans le fichier main.cpp

5. Décommentez maintenant les instructions commentées des fichiers [main.cpp](ex3/main.cpp) et [utils.hpp](ex3/utils.hpp).  
Compilez maintenant le programme complet (avec les modules main et utils).  
Quelle est l'erreur qui s'affiche ? S'agit-il d'une erreur de build ou de link ?  
Pourquoi se produit-elle ?  
Que faudrait-il faire pour la résoudre ?
> nous avons une declaration multiples sur print_bye() elle se produit lors du link il faut supprimer la declaration dans le fichier utils.hpp

6. Ajoutez le mot-clef `inline` devant la définition de la fonction `print_bye` dans [utils.hpp](ex3/utils.hpp). Que constatez-vous quand vous réessayez de compiler le programme ?  
Selon-vous, quel est l'effet du mot-clef `inline` sur le linker ?

> l'erreur disparait car le linker va accepeter les doublons de fonction inline


