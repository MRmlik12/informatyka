#include <iostream>
#include <cmath>
#include <vector>

//(2x3−5x2+4x−1):(x−1)
int main() {
    int degree;
    std::cout << "Stopien pierwiastka: ";
    std::cin >> degree;

    int polynomial;
    std::cout << "Wielomian: ";
    std::cin >> polynomial;

    int length = degree + 1;
    int numbers[length];

    for (int i = 0; i < length; i++)
    {
        std::cin >> numbers[i];
    }

    std::cout << std::endl;

    std::vector<int> v = {};
    for (int i = 0; i < length; i++)
    {
        if (i == 0) {
            v.push_back(numbers[i]);
            continue;
        }

        v.push_back(abs(polynomial) * v[i - 1] + numbers[i]);
    }

    for (int i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}