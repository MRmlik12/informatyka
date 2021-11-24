#include <iostream>
#include <random>

const int X = 10;

std::string getCords(int x, int y) {
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

int getRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);

    return distrib(gen);
}

void generateMap(int map[10][10], int& lowestNum, int& highestNum, std::string& lowestNumCords, std::string& highestNumCords) {
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < X; y++) {
            int generatedNumber = getRandomNumber();
            map[x][y] = generatedNumber;

            if (generatedNumber < lowestNum) {
                lowestNum = generatedNumber;
                lowestNumCords = getCords(x, y);
            }

            if (generatedNumber > highestNum) {
                highestNum = generatedNumber;
                highestNumCords = getCords(x ,y);
            }
        }
    }
}

void printLowestValue(int lowestNum, const std::string &lowestNumCords) {
    std::cout << "Najmniejsza wartosc: " << lowestNum << lowestNumCords << std::endl;
}

void printHighestValue(int highestNum, const std::string &highestNumCords) {
    std::cout << "Najwieksza wartosc: " << highestNum << highestNumCords << std::endl;
}

void printMap(int map[X][X]) {
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < X; y++) {
            std::cout << map[x][y] << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    int map[X][X];

    int lowestNum = 101;
    std::string lowestNumCords;
    int highestNum = 0;
    std::string highestNumCords;

    generateMap(map, lowestNum, highestNum, lowestNumCords, highestNumCords);
    printMap(map);

    printLowestValue(lowestNum, lowestNumCords);
    printHighestValue(highestNum, highestNumCords);

    return 0;
}