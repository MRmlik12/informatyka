#include <cryptopp/cryptlib.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>

void printHashedMessage(std::string digest) {
    CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
    std::cout << "Hash: ";
    CryptoPP::StringSource(digest, true, new CryptoPP::Redirector(encoder));
    std::cout << std::endl;
}

std::string getDigest(std::string message) {
    CryptoPP::SHA256 sha;
    std::string digest;
    sha.Update((const CryptoPP::byte*)message.data(), message.size());
    digest.resize(sha.DigestSize());
    sha.Final((CryptoPP::byte*)&digest[0]);

    return digest;
}
