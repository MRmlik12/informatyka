#include <iostream>
#include <cmath>

const int X = 10;

int main() {
    int map[X][X];

    int firstColumnSum = 0;
    int secondColumnSum = 0;
    for (int x = 0; x < X; x++) {
        for (int y = 0; y < X; y++) {
            if (y == 0) {
                map[x][y] = x;
                firstColumnSum += x;
                continue;
            } else if (y == 1) {
                int squaredNumber = pow(x, 2);
                map[x][y] = squaredNumber;
                secondColumnSum += squaredNumber;
                continue;
            }

            map[x][y] = 0;
        }
    }

    for (auto & x : map) {
        for (int y : x) {
            std::cout << y << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "Suma liczb z pierwszej kolumny: " << firstColumnSum << std::endl;
    std::cout << "Suma liczb z drugiej kolumny: " << secondColumnSum << std::endl;

    return 0;
}