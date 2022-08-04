#include <iostream>
#include <string>

void repeat() {
    while (true) {
        std::string repeat;
        std::cin >> repeat;

        std::cout << "~ " << repeat << std::endl;

        if ((repeat.compare("q")) == 0) {
            break;
        }
    }   
}