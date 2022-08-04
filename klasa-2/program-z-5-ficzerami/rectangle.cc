#include <iostream>

void rectangle() {
    int width;
    int height;

    std::cout << "Podaj długosc prostokata" << std::endl;
    std::cin >> width;

    std:: cout << "Podaj wysokosc prostokata" << std::endl;
    std::cin >> height;

    drawWidth(width);    

    int i = 0;
    while (i <= height)
    {
        if (i == 0 || i == width) 
        {
            std::cout << ".";
        }
        i++;
    }

    drawWidth(width);
}

void drawWidth(int width) {
    int i = 0;
    while (i <= width) {
        std::cout << ".";
        i++;
    }
}