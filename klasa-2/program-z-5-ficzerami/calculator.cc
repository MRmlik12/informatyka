#include <iostream>

void calculator() {
    double firstValue;
    double secondValue;
    char character;

    std::cout << "Wpisz pierwsza liczbe: ";
    std::cin >> firstValue;
    std::cout << "Wpisz druga liczbe: " << std::endl;
    std::cin >> secondValue;
    std::cout << "Wpisz znak (+, -, *, /)" << std::endl;
    
    switch (character)
    {
        case '+':
            std::cout << "Wynik to: " << firstValue + secondValue << std::endl;
            break;
        case '-':
            std::cout << "Wynik to: " << firstValue - secondValue << std::endl;
            break;
        case '*':
            std::cout << "Wynik to: " << firstValue * secondValue << std::endl;
            break;
        case '/':
            std::cout << "Wynik to: " << firstValue / secondValue << std::endl;
            break;
        default:
            std::cout << "Wybrano zły znak" << std::endl;
            break;
    }
}