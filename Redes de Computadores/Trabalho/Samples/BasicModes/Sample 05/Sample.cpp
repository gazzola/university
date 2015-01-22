// CTS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "3way.h"
#include "aes.h"
#include "modes.h"
#include "filters.h"

#include <iostream>

using namespace CryptoPP;
using namespace std;

int main(int argc, char* argv[])
{
  byte key[ ThreeWay::DEFAULT_KEYLENGTH ];
  byte iv[ ThreeWay::BLOCKSIZE ];

  memset( key, 0x00, ThreeWay::DEFAULT_KEYLENGTH );
  memset( iv, 0x00, ThreeWay::BLOCKSIZE );  

  // Problem at srtlen( plain )  = 12
  // string plain = "Hello World!";
  string plain = "Hello World!!";

  string cipher, recovered;



  ////////////////////
  // Encryption
  ////////////////////
  ThreeWayEncryption twe( key, ThreeWay::DEFAULT_KEYLENGTH );
  CBC_CTS_Mode_ExternalCipher::Encryption encryptor( twe, iv );

  StreamTransformationFilter stfe( encryptor, new StringSink( cipher ));
  stfe.Put( (byte*)plain.c_str(), plain.size() );
  stfe.MessageEnd();

  ////////////////////
  // Decryption
  ////////////////////
  ThreeWayDecryption twd( key, ThreeWay::DEFAULT_KEYLENGTH );
  CBC_CTS_Mode_ExternalCipher::Decryption decryptor( twd, iv );

  StreamTransformationFilter stfd( decryptor, new StringSink( recovered ));
  stfd.Put((byte*)cipher.c_str(), cipher.size() );
  stfd.MessageEnd();

  std::cout << "Recovered Text: " << recovered << std::endl;

  return 0;
}

