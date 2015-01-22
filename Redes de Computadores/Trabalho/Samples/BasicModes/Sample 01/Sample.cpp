// Sample.cpp
//

#include "stdafx.h"

// Runtime Includes
#include <iostream>

// Crypto++ Includes
#include "aes.h"
#include "modes.h"      // xxx_Mode< >
#include "filters.h"    // StringSource and
                        // StreamTransformation

int main(int argc, char* argv[])
{

  ///////////////////////////////////////
  // Key and IV                        //
  ///////////////////////////////////////

  byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ];
  byte iv[ CryptoPP::AES::BLOCKSIZE ];

  ::memset( key, 0x01, CryptoPP::AES::DEFAULT_KEYLENGTH );
  ::memset( iv, 0x01, CryptoPP::AES::BLOCKSIZE );

  ///////////////////////////////////////
  // Byte Blocks                       //
  ///////////////////////////////////////

  // Message M
  byte PlainText[] = {
    'H','e','l','l','o',' ',
    'W','o','r','l','d',
    0x0,0x0,0x0,0x0,0x0
  };

  // Cipher Text Sink
  byte cbCipherText[ CryptoPP::AES::BLOCKSIZE ] ;

  // Recovered Text Sink
  byte cbRecoveredText[ CryptoPP::AES::BLOCKSIZE ];

  ///////////////////////////////////////
  // Encryption                        //
  ///////////////////////////////////////

  CryptoPP::ECB_Mode< CryptoPP::AES >::Encryption Encryptor;
  Encryptor.SetKey( key, sizeof(key) );

  Encryptor.ProcessData( cbCipherText,
      PlainText, sizeof(PlainText) );

  ///////////////////////////////////////
  // Decryption                        //
  ///////////////////////////////////////

  CryptoPP::ECB_Mode< CryptoPP::AES >::Decryption Decryptor;
  Decryptor.SetKey( key, sizeof(key) );
    
  Decryptor.ProcessData( cbRecoveredText,
    cbCipherText, sizeof( cbCipherText ) );

  //////////////////////////////////////////
  // Output                               //
  //////////////////////////////////////////

  cout << "Algorithm: ";
  cout << Encryptor.AlgorithmName() << endl;
  cout << endl;

  cout << "Default Key Size: ";
  cout << Encryptor.DefaultKeyLength() << " bytes" << endl;

  cout << "Block Size: ";
  cout << Encryptor.MandatoryBlockSize() << " bytes" << endl;
  cout << endl;

  cout << "Plain Text (" << sizeof(PlainText) << " bytes)" << endl;
  cout << " '" << PlainText << "'" << endl;
  cout << endl;
  
  cout << "Cipher Text (" << sizeof(cbCipherText) << " bytes)" << endl;
  cout << endl;  

  cout << "Recovered Text:" << endl;
  cout << " '" << cbRecoveredText << "'" << endl;
  cout << endl;

  return 0;
}

