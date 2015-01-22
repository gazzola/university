// PreCompiled Header
#include "StdAfx.h"

// Includes all required Crypto++
// Block Cipher Headers
#include "KeyTable.h"

// C Runtime Includes
#include <iostream>
#include <iomanip>

// Crypto++ Includes
#include "modes.h"    // xxx_Mode< >
#include "filters.h"  // StringSource and


CryptoPP::BlockCipher* Ciphers[] =
{
  new CryptoPP::AES::Encryption(),
  new CryptoPP::Blowfish::Encryption(),
  new CryptoPP::BTEA::Encryption(),
  new CryptoPP::Camellia::Encryption(),
  new CryptoPP::CAST128::Encryption(),
  new CryptoPP::CAST256::Encryption(),
  new CryptoPP::DES::Encryption(),
  new CryptoPP::DES_EDE2::Encryption(),
  new CryptoPP::DES_EDE3::Encryption(),
  new CryptoPP::DES_XEX3::Encryption(),
  new CryptoPP::GOST::Encryption(),
  new CryptoPP::IDEA::Encryption(),
  new CryptoPP::MARS::Encryption(),
  new CryptoPP::RC2::Encryption(),
  new CryptoPP::RC5::Encryption(),
  new CryptoPP::RC6::Encryption(),
  new CryptoPP::Rijndael::Encryption(),
  new CryptoPP::SAFER_K::Encryption(),
  new CryptoPP::SAFER_SK::Encryption(),
  new CryptoPP::Serpent::Encryption(),
  new CryptoPP::SHACAL2::Encryption(),
  new CryptoPP::SHARK::Encryption(),
  new CryptoPP::SKIPJACK::Encryption(),
  new CryptoPP::ThreeWay::Encryption(),
  new CryptoPP::Twofish::Encryption(),
  new CryptoPP::XTEA::Encryption(),
};

#define COUNTOF(x) sizeof(x)/sizeof(x[0])

int main(int argc, char* argv[]){

  for(int i = 0; i < COUNTOF(Ciphers); i++ )
  {
    std::cout << "Algorithm: ";
    std::cout << Ciphers[i]->AlgorithmName();
    std::cout << std::endl;

    std::cout << " Block Size: ";
    std::cout << Ciphers[i]->BlockSize();    
    std::cout << std::endl;

    std::cout << " Default Key Length: ";
    std::cout << Ciphers[i]->DefaultKeyLength();
    std::cout << std::endl;

    std::cout << " Minimum Key Length: ";
    std::cout << Ciphers[i]->MinKeyLength();
    std::cout << std::endl;

    std::cout << " Maximum Key Length: ";
    std::cout << Ciphers[i]->MaxKeyLength();
    std::cout << std::endl;

    std::cout << std::endl;
  }

  return 0;
}
