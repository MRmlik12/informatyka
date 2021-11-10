#include <iostream>

const int MATRIX_SIZE = 10;

void printMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE], char name) {
    std::cout << name << ")" << std::endl;
    for (auto x = 0; x < MATRIX_SIZE; x++) {
        for (auto y = 0; y < MATRIX_SIZE; y++) {
            std::cout << " " << matrix[x][y] << "  ";
        }

        std::cout << std::endl;
    }   

    std::cout << std::endl;
}

int main() {
    int a[MATRIX_SIZE][MATRIX_SIZE];
    int b[MATRIX_SIZE][MATRIX_SIZE];
    int c[MATRIX_SIZE][MATRIX_SIZE];
    int d[MATRIX_SIZE][MATRIX_SIZE];
    
    for (auto x = 0; x < MATRIX_SIZE; x++) {
        for (auto y = 0; y < MATRIX_SIZE; y++) {
            a[x][y] = y;
            b[x][y] = x;
            c[x][y] = y + x;
            d[x][y] = x * (y + x);
        }
    }

    printMatrix(a, 'A');
    printMatrix(b, 'B');
    printMatrix(c, 'C');
    printMatrix(d, 'D');
}