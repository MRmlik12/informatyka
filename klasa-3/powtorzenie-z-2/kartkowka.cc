#include <iostream>
#include <random>
#include <math.h>

using namespace std;

void zad1() {
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a == 0) {
        cout << "Nie da sie rozwiazac rownania" << endl;
    }
    
    int result = c - b;
    cout << "Wynik rownania: " << result / a << endl;
}

void zad2() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 99);

    int numbers[5];

    int average = 0;
    int max = 0;
    int min = 100;

    for (auto i = 0; i < 5; i++)
    {
        int generated = distrib(gen);
        numbers[i] = generated;
        if (generated > max) {
            max = numbers[i];
        }

        if (generated < min) {
            min = numbers[i];
        }

        average += generated;
    }

    cout << endl;
    cout << "srednia: " << average / 5 << endl;
    cout << "najmniejsza: " << min << endl;
    cout << "najwieksza: " << max << endl;
}

void zad3() {
    auto a = 1;
    auto b = 1;

    while (a <= 100)
    {
        while (b <= 100)
        {
            std::cout << a << "*" << b << "=" << a * b << endl;
            b++;
        }

        a++;
        b = 1;
    }
}

int main() {
    cout << "---zadanie 1---" << endl;
    zad1();

    cout << "---zadanie 2---" << endl;
    zad2();

    cout << "---zadanie 3---" << endl;
    zad3();
}