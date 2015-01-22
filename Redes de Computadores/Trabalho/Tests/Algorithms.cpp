// Includes all required Crypto++

// Block Cipher Headers
#include "Algorithms.h"

// C Runtime Includes
#include <iostream>
#include <iomanip>

// Crypto++ Includes
#include "modes.h"    // xxx_Mode< >
#include "filters.h"  // StringSource and


CryptoPP::BlockCipher* Ciphers[] ={
	new CryptoPP::AES::Encryption(),
	new CryptoPP::Blowfish::Encryption(),
	//new CryptoPP::BTEA::Encryption(),
	//new CryptoPP::Camellia::Encryption(),
	//new CryptoPP::CAST128::Encryption(),
	//new CryptoPP::CAST256::Encryption(),
	//new CryptoPP::DES::Encryption(),
	//new CryptoPP::DES_EDE2::Encryption(),
	//new CryptoPP::DES_EDE3::Encryption(),
	//new CryptoPP::DES_XEX3::Encryption(),
	//new CryptoPP::GOST::Encryption(),
	//new CryptoPP::IDEA::Encryption(),
	//new CryptoPP::MARS::Encryption(),
	//new CryptoPP::RC2::Encryption(),
	new CryptoPP::RC5::Encryption(),
	//new CryptoPP::RC6::Encryption(),
	//new CryptoPP::Rijndael::Encryption(),
	//new CryptoPP::SAFER_K::Encryption(),
	//new CryptoPP::SAFER_SK::Encryption(),
	//new CryptoPP::Serpent::Encryption(),
	//new CryptoPP::SHACAL2::Encryption(),
	//new CryptoPP::SHARK::Encryption(),
	new CryptoPP::SKIPJACK::Encryption(),
	//new CryptoPP::ThreeWay::Encryption(),
	//new CryptoPP::Twofish::Encryption(),
	//new CryptoPP::XTEA::Encryption(),
	new CryptoPP::TEA::Encryption(),
};

#define COUNTOF(x) sizeof(x)/sizeof(x[0])

using namespace std;



int main(){


	for(int i = 0; i < COUNTOF(Ciphers); i++ ){
		cout << "Algorithm: ";
		cout << Ciphers[i]->AlgorithmName();
		cout << endl;

		cout << " Block Size: ";
		cout << Ciphers[i]->BlockSize();    
		cout << endl;

		cout << " Default Key Length: ";
		cout << Ciphers[i]->DefaultKeyLength();
		cout << endl;

		cout << " Minimum Key Length: ";
		cout << Ciphers[i]->MinKeyLength();
		cout << endl;

		cout << " Maximum Key Length: ";
		cout << Ciphers[i]->MaxKeyLength();
		cout << endl;

		cout << endl;
	}

	cout << "AES: 10, 12, 14" << endl;
	//cout << CryptoPP::AES::ROUNDS << endl;

	cout << "BLOWFISH:";
	cout << CryptoPP::Blowfish::ROUNDS << endl;

	cout << "RC5:";
	cout << CryptoPP::RC5::DEFAULT_ROUNDS << endl;

	cout << "SKIPJACK: 32" << endl;
	//cout << CryptoPP::SKIPJACK::ROUNDS << endl;
	
	cout << "TEA:";
	cout << CryptoPP::TEA::DEFAULT_ROUNDS << endl;

	return 0;
}
