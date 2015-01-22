// PreCompiled Header
#include "StdAfx.h"

// Includes all required Crypto++
// Block Cipher Headers
#include "SymmetricCipher.h"

// C Runtime Includes
#include <iostream>
#include <iomanip>

// Crypto++ Includes
// #include "cryptlib.h"
#include "modes.h" // xxx_Mode< >
#include "filters.h" // StringSource and
// StreamTransformation

// Cipher Modes
//
// #define CIPHER_MODE CBC_CTS_Mode
// #define CIPHER_MODE CBC_Mode
// #define CIPHER_MODE CFB_FIPS_Mode
// #define CIPHER_MODE CFB_Mode
#define CIPHER_MODE CTR_Mode
// #define CIPHER_MODE ECB_Mode
// #define CIPHER_MODE OFB_Mode

// Ciphers
//
// #define CIPHER AES
#define CIPHER Blowfish
// #define CIPHER BTEA
// #define CIPHER Camellia
// #define CIPHER CAST128
// #define CIPHER CAST256
// #define CIPHER DES
// #define CIPHER DES_EDE2
// #define CIPHER DES_EDE3
// #define CIPHER DES_XEX3
// #define CIPHER GOST
// #define CIPHER IDEA
// #define CIPHER MARS
// #define CIPHER RC2
// #define CIPHER RC5
// #define CIPHER RC6
// #define CIPHER Rijndael
// #define CIPHER SAFER_K
// #define CIPHER SAFER_SK
// #define CIPHER Serpent
// #define CIPHER SHACAL2
// #define CIPHER SHARK
// #define CIPHER SKIPJACK
// #define CIPHER ThreeWay
// #define CIPHER Twofish
// #define CIPHER XTEA

int main(int argc, char* argv[]) {

   try
   {
      // Key and IV setup
      byte key[ CryptoPP::CIPHER::DEFAULT_KEYLENGTH ],
            iv[ CryptoPP::CIPHER::BLOCKSIZE ];

      ::memset( key, 0x01, CryptoPP::CIPHER::DEFAULT_KEYLENGTH );
      ::memset( iv, 0x01, CryptoPP::CIPHER::BLOCKSIZE );

      // Message M
      std::string PlainText = "Yoda said, Do or Do Not. There is no try.";

      // Cipher Text Sink
      std::string CipherText;

      // Encryptor
      CryptoPP::CIPHER_MODE<CryptoPP::CIPHER>::Encryption
         Encryptor( key, sizeof(key), iv );

      // Encryption
      CryptoPP::StringSource( PlainText, true,
         new CryptoPP::StreamTransformationFilter( Encryptor,
            new CryptoPP::StringSink( CipherText )
         ) // StreamTransformationFilter
      ); // StringSource

      ///////////////////////////////////////
      // DMZ //
      ///////////////////////////////////////

      // Recovered Text Sink
      std::string RecoveredText;

      // Decryptor
      CryptoPP::CIPHER_MODE<CryptoPP::CIPHER>::Decryption
         Decryptor( key, sizeof(key), iv );

      // Decryption
      CryptoPP::StringSource( CipherText, true,
         new CryptoPP::StreamTransformationFilter( Decryptor,
            new CryptoPP::StringSink( RecoveredText )
         ) // StreamTransformationFilter
      ); // StringSource

      //////////////////////////////////////////
      // Output //
      //////////////////////////////////////////

      std::cout << "Algorithm:" << std::endl;
      std::cout << " " << Encryptor.AlgorithmName() << std::endl;
      std::cout << "Minimum Key Size:" << std::endl;
      std::cout << " " << Encryptor.MinKeyLength() << " bytes" << std::endl;
      std::cout << std::endl;

      std::cout << "Plain Text (" << PlainText.length() << " bytes)" << std::endl;
      std::cout << " '" << PlainText << "'" << std::endl;
      std::cout << std::endl;

      std::cout << "Cipher Text Size:" << std::endl;
      std::cout << " " << CipherText.size() << " bytes" << std::endl;
      std::cout << std::endl;

      std::cout << "Recovered Text:" << std::endl;
      std::cout << " '" << RecoveredText << "'" << std::endl;
      std::cout << std::endl;
   }
   catch( CryptoPP::Exception& e)
   {
      std::cerr << e.what() << std::endl;
   }
   
   catch(...)
   {
      std::cerr << "Unknown Error" << std::endl;
   }   

   return 0;
}