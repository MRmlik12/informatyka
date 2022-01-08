#include <iostream>

int main() {
    std::string plainText;
    std::cin >> plainText;

    auto length = plainText.length() / 5;

    if (length % 5 > 0) length++;

    int keys[5];
    int arr[length][5];

    for (int & key : keys) {
        std::cin >> key;
    }

    int index;
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