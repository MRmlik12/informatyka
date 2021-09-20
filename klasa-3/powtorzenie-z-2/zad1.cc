#include <iostream>
#include <tuple>
#include <math.h>

bool isLinearFunction(int a) {
    if (a == 0) {
        return true;
    }

    return false;
}

void printSolution(float delta, bool isLinear) {
    if (isLinear) {
        std::cout << delta << std::endl;
        return;
    }

    if (delta > 0) {
        std::cout << "Dwa miejsca zerowe" << std::endl;
        return;
    } else if (delta == 0) {
        std::cout << "Jedno miejsce zerowe" << std::endl;
        return;
    } 

    std::cout << "Brak miejsc zerowych" << std::endl;
}

float calcLinearFunction(int b, int c) {
    return b / (c * -1);
}

float calcDelta(int a, int b, int c) {
    return pow(b, 2) - (4 * a * c);
}

std::tuple<int, int, int> getInput() {
    int a, b, c;

    std::cout << "Podaj a" << std::endl;
    std::cin >> a;
    std::cout << "Podaj b" << std::endl;    
    std::cin >> b;
    std::cout << "Podaj c" << std::endl;
    std::cin >> c;

    return std::make_tuple(a, b, c);
}

int main() {
    auto input = getInput();
    auto isLinear = isLinearFunction(std::get<0>(input));

    if (isLinear) {
        auto result = calcLinearFunction(std::get<1>(input), std::get<2>(input));
        printSolution(result, isLinear);
        return;
    }
    
    auto delta = calcDelta(std::get<0>(input), std::get<1>(input), std::get<2>(input));
    printSolution(delta, isLinear);
}