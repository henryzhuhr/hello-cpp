#include <iostream>
#include <string>

class Person
{
  private:
    std::string name{"noName"};
    int         age{0};

  public:
    Person(/* args */);
    Person(std::string name, int age) : name(name), age(age){};
    ~Person();

  public:
    friend std::ostream& operator<<(std::ostream& os, Person const& person);

  public:
    void SetAge(int age) { this->age = age; };
};

Person::~Person() {}
std::ostream& operator<<(std::ostream& os, Person const& person) { return os << "Person(" << person.name << "," << person.age << ")"; }

int main()
{
#pragma region value copy
    Person person          = Person("tim", 10);
    Person person_value_cp = person;
    person.SetAge(11);
    std::cout << "Value: " << person << std::endl;
    std::cout << "Value: " << person_value_cp << std::endl;
#pragma endregion
}