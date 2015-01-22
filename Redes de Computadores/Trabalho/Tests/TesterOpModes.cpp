/*
* Testador de cifras com modos de operacoes basicos
* --------------------------------------------------
*
* Chave:			Simetrica
* Tipo de Cifra:	Bloco
* Algoritmos:		AES, Blowfish, RC5, Skipjack, TEA
* Modos:			ECB, CBC, CFB, OFB, CTR
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
* Compile: g++ -o test TesterOpModes.cpp -lcrypto++
* Run: ./test
*
*/

#include "TesterOpModes.h"

// C Runtime Includes
#include <cstdio>
#include <iostream>		// cout
#include <iomanip>		// precision
#include <sys/time.h>	// crono


// Crypto++ Includes
#include "modes.h" 		// Modes
#include "filters.h"	// StringSource and StreamTransformation




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
	
	// Message M
	string PlainText;
	getline(cin, PlainText);
	
	// ECB
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		// Key and IV setup
		byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
		    iv[ CryptoPP::CIPHER::BLOCKSIZE ];

		memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
		memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

		// Cipher Text Sink
		string CipherText;

		// Recovered Text Sink
		string RecoveredText;


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		// Encryptor
		CryptoPP::ECB_Mode<CryptoPP::CIPHER>::Encryption
		 encryptor( key, sizeof(key) );

		// Encryption
		CryptoPP::StringSource( PlainText, true,
			new CryptoPP::StreamTransformationFilter( encryptor,
				new CryptoPP::StringSink( CipherText )
			) // StreamTransformationFilter
		); // StringSource


		// Decryptor
		CryptoPP::ECB_Mode<CryptoPP::CIPHER>::Decryption
		 decryptor( key, sizeof(key) );

		// Decryption
		CryptoPP::StringSource( CipherText, true,
			new CryptoPP::StreamTransformationFilter( decryptor,
				new CryptoPP::StringSink( RecoveredText )
			) // StreamTransformationFilter
		); // StringSource

		timer = crono() - timer;

		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;
		
		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << " bytes" << endl;
		
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




	// CBC
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		// Key and IV setup
		byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
		    iv[ CryptoPP::CIPHER::BLOCKSIZE ];

		memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
		memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

		// Cipher Text Sink
		string CipherText;

		// Recovered Text Sink
		string RecoveredText;


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		// Encryptor
		CryptoPP::CBC_Mode<CryptoPP::CIPHER>::Encryption
		 encryptor( key, sizeof(key), iv );

		// Encryption
		CryptoPP::StringSource( PlainText, true,
			new CryptoPP::StreamTransformationFilter( encryptor,
				new CryptoPP::StringSink( CipherText )
			) // StreamTransformationFilter
		); // StringSource


		// Decryptor
		CryptoPP::CBC_Mode<CryptoPP::CIPHER>::Decryption
		 decryptor( key, sizeof(key), iv );

		// Decryption
		CryptoPP::StringSource( CipherText, true,
			new CryptoPP::StreamTransformationFilter( decryptor,
				new CryptoPP::StringSink( RecoveredText )
			) // StreamTransformationFilter
		); // StringSource

		timer = crono() - timer;

		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;
		
		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << " bytes" << endl;
		
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



	// CFB
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		// Key and IV setup
		byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
		    iv[ CryptoPP::CIPHER::BLOCKSIZE ];

		memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
		memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

		// Cipher Text Sink
		string CipherText;

		// Recovered Text Sink
		string RecoveredText;


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		// Encryptor
		CryptoPP::CFB_Mode<CryptoPP::CIPHER>::Encryption
		 encryptor( key, sizeof(key), iv );

		// Encryption
		CryptoPP::StringSource( PlainText, true,
			new CryptoPP::StreamTransformationFilter( encryptor,
				new CryptoPP::StringSink( CipherText )
			) // StreamTransformationFilter
		); // StringSource


		// Decryptor
		CryptoPP::CFB_Mode<CryptoPP::CIPHER>::Decryption
		 decryptor( key, sizeof(key), iv );

		// Decryption
		CryptoPP::StringSource( CipherText, true,
			new CryptoPP::StreamTransformationFilter( decryptor,
				new CryptoPP::StringSink( RecoveredText )
			) // StreamTransformationFilter
		); // StringSource

		timer = crono() - timer;

		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;
		
		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << " bytes" << endl;
		
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



	// OFB
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		// Key and IV setup
		byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
		    iv[ CryptoPP::CIPHER::BLOCKSIZE ];

		memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
		memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

		// Cipher Text Sink
		string CipherText;

		// Recovered Text Sink
		string RecoveredText;


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		// Encryptor
		CryptoPP::OFB_Mode<CryptoPP::CIPHER>::Encryption
		 encryptor( key, sizeof(key), iv );

		// Encryption
		CryptoPP::StringSource( PlainText, true,
			new CryptoPP::StreamTransformationFilter( encryptor,
				new CryptoPP::StringSink( CipherText )
			) // StreamTransformationFilter
		); // StringSource


		// Decryptor
		CryptoPP::OFB_Mode<CryptoPP::CIPHER>::Decryption
		 decryptor( key, sizeof(key), iv );

		// Decryption
		CryptoPP::StringSource( CipherText, true,
			new CryptoPP::StreamTransformationFilter( decryptor,
				new CryptoPP::StringSink( RecoveredText )
			) // StreamTransformationFilter
		); // StringSource

		timer = crono() - timer;

		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;
		
		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << " bytes" << endl;
		
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



	// CTR
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		// Key and IV setup
		byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
		    iv[ CryptoPP::CIPHER::BLOCKSIZE ];

		memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
		memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

		// Cipher Text Sink
		string CipherText;

		// Recovered Text Sink
		string RecoveredText;


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		// Encryptor
		CryptoPP::CTR_Mode<CryptoPP::CIPHER>::Encryption
		 encryptor( key, sizeof(key), iv );

		// Encryption
		CryptoPP::StringSource( PlainText, true,
			new CryptoPP::StreamTransformationFilter( encryptor,
				new CryptoPP::StringSink( CipherText )
			) // StreamTransformationFilter
		); // StringSource


		// Decryptor
		CryptoPP::CTR_Mode<CryptoPP::CIPHER>::Decryption
		 decryptor( key, sizeof(key), iv );

		// Decryption
		CryptoPP::StringSource( CipherText, true,
			new CryptoPP::StreamTransformationFilter( decryptor,
				new CryptoPP::StringSink( RecoveredText )
			) // StreamTransformationFilter
		); // StringSource

		timer = crono() - timer;

		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;
		
		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << " bytes" << endl;
		
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



	// CBS_CTS
	try{

		double timer = crono();

		///////////////////////////////////////
		// Setup //
		///////////////////////////////////////

		// Key and IV setup
		byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
		    iv[ CryptoPP::CIPHER::BLOCKSIZE ];

		memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
		memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

		// Cipher Text Sink
		string CipherText;

		// Recovered Text Sink
		string RecoveredText;


		///////////////////////////////////////
		// Encryption and Decryption //
		///////////////////////////////////////

		// Encryptor
		CryptoPP::CBC_CTS_Mode<CryptoPP::CIPHER>::Encryption
		 encryptor( key, sizeof(key), iv );

		// Encryption
		CryptoPP::StringSource( PlainText, true,
			new CryptoPP::StreamTransformationFilter( encryptor,
				new CryptoPP::StringSink( CipherText )
			) // StreamTransformationFilter
		); // StringSource


		// Decryptor
		CryptoPP::CBC_CTS_Mode<CryptoPP::CIPHER>::Decryption
		 decryptor( key, sizeof(key), iv );

		// Decryption
		CryptoPP::StringSource( CipherText, true,
			new CryptoPP::StreamTransformationFilter( decryptor,
				new CryptoPP::StringSink( RecoveredText )
			) // StreamTransformationFilter
		); // StringSource

		timer = crono() - timer;

		//////////////////////////////////////////
		// Output //
		//////////////////////////////////////////

		cout << "Algorithm: ";
		cout << encryptor.AlgorithmName() << endl;
		
		cout << "Key Length: ";
		cout << encryptor.DefaultKeyLength() << " bytes" << endl;
		
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