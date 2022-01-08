#include <iostream>
#include <cryptopp/rsa.h>
#include <cryptopp/osrng.h>

void exampleAsymetricAlgorithm(std::string message) {
	std::string cipher, recovered;
	CryptoPP::AutoSeededRandomPool rng;

	CryptoPP::InvertibleRSAFunction params;
	params.GenerateRandomWithKeySize(rng, 1024);

	CryptoPP::RSA::PrivateKey privateKey(params);
	CryptoPP::RSA::PublicKey publicKey(params);

	CryptoPP::RSAES_OAEP_SHA_Encryptor e(publicKey);

	CryptoPP::StringSource ss1(message, true,
		new CryptoPP::PK_EncryptorFilter(rng, e,
			new CryptoPP::StringSink(cipher)
		) // PK_EncryptorFilter
	);

	std::cout << "Zaszyfrowana wiadomosc za pomoca klucza publicznego: " << cipher << std::endl;

	CryptoPP::RSAES_OAEP_SHA_Decryptor d(privateKey);

	CryptoPP::StringSource ss2(cipher, true,
		new CryptoPP::PK_DecryptorFilter(rng, d,
			new CryptoPP::StringSink(recovered)
		) // PK_DecryptorFilter
	);

	std::cout << "Odszyfrowana wiadomosc za pomoca klucza prywatnego: " << recovered << std::endl;
}