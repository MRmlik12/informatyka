#include <iostream>
#include <random>

int main() {
    int table_size;
    std::cout << "Podaj długość tablicy" << std::endl;
    std::cin >> table_size;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 100);

    auto random_numbers = new int(table_size);

    std::cout << "Wylosowane liczby: " << std::endl;

    for (auto i = 0; i < table_size; i++)
    {
        random_numbers[i] = distrib(gen);
        std::cout << random_numbers[i] << " ";
    }
    
    std::cout << std::endl;
    std::cout << "Liczby mniejsze od 50" << std::endl;

    for (auto i = 0; i < table_size; i++)
    {
        if (random_numbers[i] < 50) {
            std::cout << random_numbers[i] << " ";
        }
    }

    delete random_numbers;
    return 0;
}