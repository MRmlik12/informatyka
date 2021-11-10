#include <iostream>

const int N = 10;

int main() {
    int cl[N][N];
    int r = 0;

    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            if (i == x) {
                cl[i][x] = i;
                r += i;
                continue;
            }

            cl[i][x] = 0;
        }
    }

    for (auto i = 9; i >= 0; i--) {
        for (auto x = 9; x >= 0; x--) {
            std::cout << cl[i][x] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "Suma to: " << r << std::endl;
}