#include <iostream>
#include "Person.cpp"
#include <vector>

int main(){
    /*
    debut de l'exo
    Person p;
    p.first_name = "Palluche";
    p.surname = "La Faluche";
    std::cout << "La personne s'appelle  "<<p.first_name << " " << p.surname << std::endl;
    */
   /*
   question 5 de l'exo
    Person p("Palluche" , "La Faluche");
    std::cout << "La personne s'appelle  "<<p.get_first_name() << " " << p.get_surname() << std::endl;
    return 0;
    */

   auto listperson = std::vector<Person>{};
   int sizelist = 0;
   auto cmpt = 0;
    std::cout << "Combien de personne voulez vous ajouter ?" << std::endl;
    std::cin >> sizelist;

    for(int value= 0 ; value < sizelist ; value++){
        std::string firstname;
        std::string surname;
        std::cout << "Entrez le prenom de la personne " << value+1 << std::endl;
        std::cin >> firstname;
        std::cout << "Entrez le nom de la personne " << value+1 << std::endl;
        std::cin >> surname;
        listperson.emplace_back(firstname,surname);
    }
    std::cout << "La personne s'appelle  "<< std::endl;
    for(auto person : listperson){
        cmpt++;
        std::cout << person.get_first_name() << " " << person.get_surname();
        if(cmpt < sizelist){
            std::cout << ", ";
        }
   
    }
    std::cout << "." << std::endl;
    return 0;
}