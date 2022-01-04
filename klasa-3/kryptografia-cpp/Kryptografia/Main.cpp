#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>
#include "Hash.h"
#include "Symetric.h"
#include "Asymetric.h"

int main() {
    std::string message;

    std::cout << "Napisz wiadomosc: ";
    std::cin >> message;
    std::cout << std::endl;

    std::cout << "------SHA-256------" << std::endl;

    //SHA256 algorytm skrotu
    auto digest = getDigest(message);
    printHashedMessage(digest);

    //AES algorytm symetryczny
    std::cout << std::endl;
    std::cout << "------AES------" << std::endl;

    exampleSymetricAlgorithm(message);

    //RSA algorytm asymetryczny
    std::cout << std::endl;
    std::cout << "------RSA------" << std::endl;
    exampleAsymetricAlgorithm(message);
}
