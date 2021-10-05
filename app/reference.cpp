#include <iostream>
#include <string>
#ifndef PERSON_H
#define PERSON_H
class Person
{
  private:
    std::string name{"noName"};
    int         age{0};

  public:
    Person(/* args */);
    Person(std::string name, int age) : name(name), age(age){};
    ~Person();
    Person(Person& other) = default; // copy constructor
    Person& operator=(Person const& other) = default;

  public:
    friend std::ostream& operator<<(std::ostream& os, Person const& person);

  public:
    void SetAge(int age) { this->age = age; };
};
#endif
Person::~Person() {}
std::ostream& operator<<(std::ostream& os, Person const& person) { return os << "Person(" << person.name << "," << person.age << ")"; }


void memory_dump(void* ptr, int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (i % 8 == 0 && i != 0)
            printf(" ");
        if (i % 16 == 0 && i != 0)
            printf("\n");
        printf("%02x ", *((uint8_t*)ptr + i));
    }
    printf("\n");
}


int main()
{
#pragma region value copy
    Person person          = Person("tim", 10);
    Person person_value_cp = person;
    person.SetAge(11);
    std::cout << "Value: " << person << std::endl;
    std::cout << "Value: " << person_value_cp << std::endl;
#pragma endregion


#pragma region reference copy
    Person& personRef_cp = person;
    person.SetAge(12);
    std::cout << "Reference: " << person << std::endl;
    std::cout << "Reference: " << personRef_cp << std::endl;
    personRef_cp.SetAge(13);
    std::cout << "Reference r: " << person << std::endl;
    std::cout << "Reference r: " << personRef_cp << std::endl;
#pragma endregion


#pragma region pointer copy
    Person* personPtr    = new Person("pointer", 10); // new in heap
    Person* personPtr_cp = personPtr;
    personPtr->SetAge(20);
    std::cout << "Reference: " << *personPtr << std::endl;
    std::cout << "Reference: " << *personPtr_cp << std::endl;
    delete personPtr;
#pragma endregion

    Person person_cp_cons = person;
    person_cp_cons        = person;
}