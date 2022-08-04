#include <iostream>
#include <calculator.h>
#include <initials.h>
#include <rectangle.h>
#include <random.h>
#include <repeat.h>
#include <ncurses.h>

using namespace std;

void clearCli() {
    clear();
}

void menu() {
    std::cout << "Witaj w programie marzeń by Daniel Olczyk" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "1. kalkulator" << std::endl;
    std::cout << "2. Inicjały" << std::endl;
    std::cout << "3. Powtarzanie" << std::endl;
    std::cout << "4. Prostokąt" << std::endl;
    std::cout << "5. Losowanie" << std::endl;
    std::cout << "6. wyjdz" << std::endl;

    int choise;
    std::cin >> choise;

    switch (choise)
    {
        case 1:
            clearCli();
            calculator();
            break;
        case 2:
            clearCli();
            initials();
            break;
        case 3:
            clearCli();
            repeat();
            break;
        case 4:
            clearCli();
            rectangle();
            break;
        case 5:
            clearCli();
            random();
            break;
        case 6:
            clearCli();
            break;
        default:
            clearCli();
            menu();
            break;
    }
}

int main() {
    while (true) {
        menu();
    }

    return 0;
}