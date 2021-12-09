#include <iostream>
#include <cmath>

const int MAP_SIZE = 10;

void writeValues(int a[MAP_SIZE][MAP_SIZE], int b[MAP_SIZE][MAP_SIZE], int c[MAP_SIZE][MAP_SIZE], int d[MAP_SIZE][MAP_SIZE]) {
    for (int x = 0; x < MAP_SIZE; ++x) {
        for (int y = 0; y < MAP_SIZE; ++y) {
            a[x][y] = x;
            b[x][y] = pow(y, 2);
            c[x][y] = a[x][y] + b[x][y];
            d[x][y] = b[x][y] * c[x][y];
        }
    }
}

void print(int map[MAP_SIZE][MAP_SIZE]) {
    for (int x = 0; x < MAP_SIZE; ++x) {
        for (int y = 0; y < MAP_SIZE; ++y) {
            std::cout << map[x][y] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    int a[MAP_SIZE][MAP_SIZE];
    int b[MAP_SIZE][MAP_SIZE];
    int c[MAP_SIZE][MAP_SIZE];
    int d[MAP_SIZE][MAP_SIZE];

    writeValues(a, b, c, d);

    print(a);
    print(b);
    print(c);
    print(d);

    return 0;
}