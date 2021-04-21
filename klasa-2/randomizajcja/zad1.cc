#include <iostream>
#include <random>

int main() {
    int i = 0;
    std::cin >> i;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-5, 30);

    auto *result = new int(i);
    for (int j = 0; j < i; j++) {
        result[j] = distrib(gen);
    }

    for (int x = 0; x < i; x++) {
        std::cout << result[x] << std::endl;
    }

    delete result;

    return 0;
}