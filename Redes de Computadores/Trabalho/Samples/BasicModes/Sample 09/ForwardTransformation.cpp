// ForwardTransformation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "aes.h"
#include "modes.h"
#include "filters.h"

#include <iostream>
#include <vector>

using namespace CryptoPP;
using namespace std;

int main(int argc, char* argv[])
{
  byte key[ AES::DEFAULT_KEYLENGTH ];
  byte iv[ AES::BLOCKSIZE ];

  memset( key, 0x00, AES::DEFAULT_KEYLENGTH );
  memset( iv, 0x00, AES::BLOCKSIZE );  

  string plain = "Seneca said, " \
    "It is rash to condemn where you are ignorant.";
  string cipher, recovered;

  ////////////////////
  // Encryption
  ////////////////////
  AESEncryption aese( key, AES::DEFAULT_KEYLENGTH );
  CTR_Mode_ExternalCipher::Encryption encryptor( aese, iv );

  StreamTransformationFilter stfaese( encryptor, new StringSink(cipher));
  stfaese.Put( (byte*)plain.c_str(), plain.size() );
  stfaese.MessageEnd(); 

  ////////////////////
  // Decryption
  ////////////////////  

  // AESEncryption aesd( key, AES::DEFAULT_KEYLENGTH );
  AESDecryption aesd( key, AES::DEFAULT_KEYLENGTH );

  CTR_Mode_ExternalCipher::Decryption decryptor( aesd, iv );

  StreamTransformationFilter stfaesd( decryptor, new StringSink( recovered ));
  stfaesd.Put( (byte*)cipher.c_str(), cipher.size() );
  stfaesd.MessageEnd();

  std::cout << "Plain Text:" << std::endl;
  std::cout << plain << std::endl;

  std::cout << std::endl;

  std::cout << "Recovered Text:" << std::endl;
  std::cout << recovered << std::endl;

  return 0;
}


