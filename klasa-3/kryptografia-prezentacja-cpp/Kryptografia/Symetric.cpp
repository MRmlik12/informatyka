#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

void exampleSymetricAlgorithm(std::string message) {
	CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
	std::string cipher;

	CryptoPP::AutoSeededRandomPool prng;
	
	CryptoPP::SecByteBlock key(CryptoPP::AES::DEFAULT_KEYLENGTH);
	CryptoPP::SecByteBlock iv(CryptoPP::AES::BLOCKSIZE);

	prng.GenerateBlock(key, key.size());
	prng.GenerateBlock(iv, iv.size());

	CryptoPP::CBC_Mode<CryptoPP::AES>::Encryption e;
	e.SetKeyWithIV(key, key.size(), iv);

	CryptoPP::StringSource s(message, true,
		new CryptoPP::StreamTransformationFilter(e,
			new CryptoPP::StringSink(cipher)
		)
	);

	std::cout << "Klucz: ";
	encoder.Put(key, key.size());
	encoder.MessageEnd();
	std::cout << std::endl;

	std::cout << "Wektor inicjujacy: ";
	encoder.Put(iv, iv.size());
	encoder.MessageEnd();
	std::cout << std::endl;

	std::cout << "Zaszyfrowany tekst: ";
	encoder.Put((const CryptoPP::byte*)&cipher[0], cipher.size());
	encoder.MessageEnd();
	std::cout << std::endl;
}
