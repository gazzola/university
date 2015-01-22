/*
* Testador de cifras com MAC (Message Authentication Code)
* --------------------------------------------------------
*
* Chave:			Simetrica
* Tipo de Cifra:	Bloco
* Algoritmos:		AES, Blowfish, RC5, Skipjack, TEA
* Modos:			EAX, GCM, CCM
*
*
* Referencias:
* ---
* http://www.cs.rit.edu/~sdc3737/final.pdf
* http://www.cix.co.uk/~klockstone/tea.pdf
* http://www.codeproject.com/Articles/21877/Applied-Crypto-Block-Ciphers
* http://www.codeproject.com/Articles/34380/Authenticated-Encryption
*
*
* Integrantes:
* ---
* Marcos V. Treviso, 121150107, marcosvtreviso@gmail.com
* Matheus B. Bieger, 111111111, matheusbieger@gmail.com
* Wolgans E. Quepfert, 111111111, ens.wolgan@gmail.com
*
*
* Instrucoes:
* ---
* Compile: g++ -o test TesterOpModes.cpp -lcrypto++ -DA_AES
* Run: ./test
*
*/


// Includes all required Crypto++
// Block and Stream Cipher Headers / MAC modes
#include "TesterMAC.h"

// C Runtime Includes
#include <cstdio>
#include <iostream>		// cout
#include <iomanip>		// precision
#include <sys/time.h>	// crono


// Crypto++ Includes
#include "modes.h" 		// Modes
#include "filters.h"	// StringSource and StreamTransformation
#include "osrng.h"

using CryptoPP::AutoSeededRandomPool;


// Ciphers
// --------

#ifdef A_AES
#define CIPHER AES
#endif  // A_AES

#ifdef A_BLO
#define CIPHER Blowfish
#endif  // A_AES

#ifdef A_RC5
#define CIPHER RC5
#endif  // A_AES

#ifdef A_SKI
#define CIPHER SKIPJACK
#endif  // A_AES

#ifdef A_TEA
#define CIPHER TEA
#endif  // A_AES

#ifndef CIPHER
#define CIPHER AES
#endif //CIPHER


using namespace std;

double crono(){
	struct timeval tv;
	gettimeofday(&tv, 0);
	return tv.tv_sec + tv.tv_usec / 1e6;
}


int main(){

	string plaintext;
	getline(cin, plaintext);

	// EAX
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		CryptoPP::AutoSeededRandomPool rng;

		byte key[CryptoPP::CIPHER::DEFAULT_KEYLENGTH];
		rng.GenerateBlock( key, sizeof(key) );
		byte iv[CryptoPP::CIPHER::BLOCKSIZE];
		rng.GenerateBlock( iv, sizeof(iv) );

		string ciphertext, recovered;

		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		CryptoPP::EAX<CryptoPP::CIPHER>::Encryption encryptor;
		encryptor.SetKeyWithIV(key, sizeof(key), iv);

		CryptoPP::StringSource( plaintext, true,
			new CryptoPP::AuthenticatedEncryptionFilter(
				encryptor, new CryptoPP::StringSink( ciphertext )
			)
		);


		CryptoPP::EAX<CryptoPP::CIPHER>::Decryption decryptor;
		decryptor.SetKeyWithIV(key, sizeof(key), iv);

		CryptoPP::StringSource( ciphertext, true,
			new CryptoPP::AuthenticatedDecryptionFilter(
				decryptor, new CryptoPP::StringSink( recovered )
			)
		);

		timer = crono() - timer;


		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;

		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << endl;

		cout << "Time: ";
		cout << fixed << setprecision(14) << timer << endl;
		
		cout << endl;

	}
	catch( CryptoPP::Exception& e){
		cout << e.what() << endl << endl;
	}
	catch(...){
		cout << "Unknown Error" << endl << endl;
	}



	// GCM
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		CryptoPP::AutoSeededRandomPool rng;

		byte key[CryptoPP::CIPHER::DEFAULT_KEYLENGTH];
		rng.GenerateBlock( key, sizeof(key) );
		byte iv[CryptoPP::CIPHER::BLOCKSIZE];
		rng.GenerateBlock( iv, sizeof(iv) );

		string ciphertext, recovered;

		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		CryptoPP::GCM<CryptoPP::CIPHER>::Encryption encryptor;
		encryptor.SetKeyWithIV(key, sizeof(key), iv);

		CryptoPP::StringSource( plaintext, true,
			new CryptoPP::AuthenticatedEncryptionFilter(
				encryptor, new CryptoPP::StringSink( ciphertext )
			)
		);


		CryptoPP::GCM<CryptoPP::CIPHER>::Decryption decryptor;
		decryptor.SetKeyWithIV(key, sizeof(key), iv);

		CryptoPP::StringSource( ciphertext, true,
			new CryptoPP::AuthenticatedDecryptionFilter(
				decryptor, new CryptoPP::StringSink( recovered )
			)
		);

		timer = crono() - timer;


		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;

		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << endl;

		cout << "Time: ";
		cout << fixed << setprecision(14) << timer << endl;
		
		cout << endl;

	}
	catch( CryptoPP::Exception& e){
		cout << e.what() << endl << endl;
	}
	catch(...){
		cout << "Unknown Error" << endl << endl;
	}



	// CCM
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		CryptoPP::AutoSeededRandomPool rng;

		byte key[CryptoPP::CIPHER::DEFAULT_KEYLENGTH];
		rng.GenerateBlock( key, sizeof(key) );
		byte iv[CryptoPP::CIPHER::BLOCKSIZE];
		rng.GenerateBlock( iv, sizeof(iv) );

		string ciphertext, recovered;

		const int TAG_SIZE = 12; // 96 bit authenticator


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		CryptoPP::CCM<CryptoPP::CIPHER, TAG_SIZE>::Encryption encryptor;
		encryptor.SetKeyWithIV(key, sizeof(key), iv);
		encryptor.SpecifyDataLengths( 0, plaintext.size() );

		CryptoPP::StringSource( plaintext, true,
			new CryptoPP::AuthenticatedEncryptionFilter(
				encryptor, new CryptoPP::StringSink( ciphertext )
			)
		);


		CryptoPP::CCM<CryptoPP::CIPHER, TAG_SIZE>::Decryption decryptor;
		decryptor.SetKeyWithIV(key, sizeof(key), iv);
		decryptor.SpecifyDataLengths( 0, ciphertext.size()-TAG_SIZE );

		CryptoPP::StringSource( ciphertext, true,
			new CryptoPP::AuthenticatedDecryptionFilter(
				decryptor, new CryptoPP::StringSink( recovered )
			)
		);

		timer = crono() - timer;


		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;

		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << endl;

		cout << "Time: ";
		cout << fixed << setprecision(14) << timer << endl;
		
		cout << endl;

	}
	catch( CryptoPP::Exception& e){
		cout << e.what() << endl << endl;
	}
	catch(...){
		cout << "Unknown Error" << endl << endl;
	}

	return 0;
}