#include <iostream>
#include <string.h>

void initials() {
    std::string name;
    std::string surname;

    std::cout << "Podaj imię: ";
    std::cin >> name;

    std::cout << "Podaj nazwisko: ";
    std::cin >> surname;

    std::cout << name[0] + surname[0] << std::endl;
}