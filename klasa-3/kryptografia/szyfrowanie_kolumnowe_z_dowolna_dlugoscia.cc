#include <iostream>

int main() {
    int width;
    std::string plainText;

    std::cin >> width;
    std::cin >> plainText;

    auto length = plainText.length() / width;

    if (length % width > 0) length++;

    int keys[width];
    int arr[length][width];

    for (int & key : keys) {
        std::cin >> key;
    }

    int index = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr[i][j] = plainText[index];
            index++;
        }
    }

    std::string cipherText;

    for (int key : keys) {
        std::string columnCipher;
        for (int j = 0; j < length; ++j) {
            if (arr[j][key] == 0) {
                continue;
            }

            columnCipher += arr[j][key];
        }

        cipherText += columnCipher;
    }

    std::cout << cipherText;

    return 0;
}
