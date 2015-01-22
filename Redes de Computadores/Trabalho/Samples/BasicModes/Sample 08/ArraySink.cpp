// ArraySink: Defines the entry point for the console application.
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

  string plain = "Einstein said, " \
    "You cannot simultaneously prevent and prepare for war.";
  string recovered, scratch;
  vector<byte> cipher;

  ////////////////////
  // Encryption
  ////////////////////
  AESEncryption aese( key, AES::DEFAULT_KEYLENGTH );
  CBC_Mode_ExternalCipher::Encryption encryptor( aese, iv );

  StreamTransformationFilter stfaese( encryptor, new StringSink(scratch));
  stfaese.Put( (byte*)plain.c_str(), plain.size() );
  stfaese.MessageEnd(); 

  // Resize the vector
  cipher.resize( scratch.size() );
  StringSource( scratch, true, new ArraySink( &(cipher[0]), cipher.size() ) );

  ////////////////////
  // Decryption
  ////////////////////
  AESDecryption aesd( key, AES::DEFAULT_KEYLENGTH );
  CBC_Mode_ExternalCipher::Decryption decryptor( aesd, iv );

  StreamTransformationFilter stfaesd( decryptor, new StringSink( recovered ));
  stfaesd.Put(&(cipher[0]), cipher.size() );
  stfaesd.MessageEnd();

  std::cout << "Plain Text:" << std::endl;
  std::cout << plain << std::endl;

  std::cout << std::endl;

  std::cout << "Recovered Text:" << std::endl;
  std::cout << recovered << std::endl;

  return 0;
}
