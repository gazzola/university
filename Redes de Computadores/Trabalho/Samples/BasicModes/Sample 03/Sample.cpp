// Sample.cpp
//

#include "stdafx.h"

// Runtime Includes
#include <iostream>

// Crypto++ Includes
#include "aes.h"
#include "modes.h" // xxx_Mode< >
#include "filters.h" // StringSource and
// StreamTransformation

int main(int argc, char* argv[])
{

  // Key and IV setup
  byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ];
  byte iv[ CryptoPP::AES::BLOCKSIZE ];

  ::memset( key, 0x01, CryptoPP::AES::DEFAULT_KEYLENGTH );
  ::memset( iv, 0x01, CryptoPP::AES::BLOCKSIZE );

  // Message M
  std::string PlainText = "Martin Luther King said, " \
    "Let no man pull you low enough to hate him.";

  // Cipher Text Sink
  std::string CipherText;

  // Encryptor
  CryptoPP::CFB_Mode< CryptoPP::AES >::Encryption
    Encryptor( key, sizeof(key), iv);

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
  CryptoPP::CFB_Mode< CryptoPP::AES >::Decryption
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

  std::cout << "Cipher Text (" << CipherText.length() << " bytes)" << std::endl;
  std::cout << std::endl;

  std::cout << "Recovered Text:" << std::endl;
  std::cout << " '" << RecoveredText << "'" << std::endl;
  std::cout << std::endl;

  return 0;
}

