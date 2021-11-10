#include <iostream>

const int N = 10;

int main() {
    int a[N][N];
    int b[N][N];
    int r = 0;

    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            append(i, x, a, i);
            append(i, x, b, i);
            a[i][x] = i;
            b[i][x] = i;
        }
    }

    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            std::cout << a[i][x] + b[i][x] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            std::cout << a[i][x] - b[i][x] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            std::cout << a[i][x] * b[i][x] << " ";
        }

        std::cout << std::endl;
    }
    
    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            std::cout << a[i][x] / b[i][x] << " ";
        }

        std::cout << std::endl;
    }
}