#include <string>

class Person
{
public:
    Person(std::string fn, std::string s ):
    first_name  {fn},
    surname {s}
    {

    }
    std::string get_first_name();
    std::string get_surname();
private:
    std::string first_name;
    std::string surname;
};