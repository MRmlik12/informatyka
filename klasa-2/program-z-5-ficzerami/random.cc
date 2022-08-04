#include <iostream>
#include <cstdlib>

void random() {
    std::cout << "Twoja wylosowana liczba to: " << rand() % 10000 + 1 << std::endl;
}