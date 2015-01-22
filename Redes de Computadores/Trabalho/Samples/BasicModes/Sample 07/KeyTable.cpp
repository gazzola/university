// PreCompiled Header
#include "StdAfx.h"

// Includes all required Crypto++
//  Block and Stream Cipher Headers
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
  // new CryptoPP::Rijndael::Encryption(),
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

#define COUNTOF(x) sizeof(x) / sizeof(x[0])
int main(int argc, char* argv[]){

  for(int i = 0; i < COUNTOF( Ciphers ); i++ )
  {
    const int BYTECOUNT = 32;
    byte key[ BYTECOUNT ], iv[ BYTECOUNT ];
    memset( key, 0, BYTECOUNT );
    memset( iv, 0 , BYTECOUNT );

    std::string data = "Hello World!";
    std::string cipher;

    try
    {
      Ciphers[i]->SetKey( key, Ciphers[i]->DefaultKeyLength() );

      std::cout << "Algorithm: " << Ciphers[i]->AlgorithmName() << std::endl;
      std::cout << " Block Size: " << Ciphers[i]->BlockSize() << std::endl;

      ////////
      // ECB
      ////////
      CryptoPP::ECB_Mode_ExternalCipher::Encryption
        ecb( *(Ciphers[i]) );
      CryptoPP::StreamTransformationFilter stfECB(
        ecb, new CryptoPP::StringSink( cipher )
      );

      stfECB.Put( (byte*)data.c_str(), data.length() );
      stfECB.MessageEnd();

      std::cout << " " << ecb.StaticAlgorithmName();
      std::cout << ": " << cipher.length() << std::endl;
      cipher.clear();

      ////////
      // CBC
      ////////
      CryptoPP::CBC_Mode_ExternalCipher::Encryption
        cbc( *(Ciphers[i]), iv );
      CryptoPP::StreamTransformationFilter stfCBC(
        cbc, new CryptoPP::StringSink( cipher )
      );

      stfCBC.Put( (byte*)data.c_str(), data.length() );
      stfCBC.MessageEnd();

      std::cout << " " << cbc.StaticAlgorithmName();
      std::cout << ": " << cipher.length() << std::endl;
      cipher.clear();

      ////////
      // OFB
      ////////
      CryptoPP::OFB_Mode_ExternalCipher::Encryption
        ofb( *(Ciphers[i]), iv );
      CryptoPP::StreamTransformationFilter stfOFB(
        ofb, new CryptoPP::StringSink( cipher )
      );

      stfOFB.Put( (byte*)data.c_str(), data.length() );
      stfOFB.MessageEnd();

      std::cout << " " << ofb.StaticAlgorithmName();
      std::cout << ": " << cipher.length() << std::endl;
      cipher.clear();

      ////////
      // CTR
      ////////
      CryptoPP::CTR_Mode_ExternalCipher::Encryption
        ctr( *(Ciphers[i]), iv );
      CryptoPP::StreamTransformationFilter stfCTR(
        ctr, new CryptoPP::StringSink( cipher )
      );

      stfCTR.Put( (byte*)data.c_str(), data.length() );
      stfCTR.MessageEnd();

      std::cout << " " << ctr.StaticAlgorithmName();
      std::cout << ": " << cipher.length() << std::endl;
      cipher.clear();

      ////////
      // CFB
      ////////
      CryptoPP::CFB_Mode_ExternalCipher::Encryption
        cfb( *(Ciphers[i]), iv );
      CryptoPP::StreamTransformationFilter stfCFB(
        cfb, new CryptoPP::StringSink( cipher )
        );

      stfCFB.Put( (byte*)data.c_str(), data.length() );
      stfCFB.MessageEnd();

      std::cout << " " << cfb.StaticAlgorithmName();
      std::cout << ": " << cipher.length() << std::endl;
      cipher.clear();

      ////////////
      // CBC/CTS
      ////////////    
      CryptoPP::CBC_CTS_Mode_ExternalCipher::Encryption
        cts( *(Ciphers[i]), iv );
      CryptoPP::StreamTransformationFilter stfCTS(
        cts, new CryptoPP::StringSink( cipher )
      );

      if( Ciphers[i]->BlockSize() < data.length() )
      {
        stfCTS.Put( (byte*)data.c_str(), data.length() );
        stfCTS.MessageEnd();
      }
      
      std::cout << " " << cts.StaticAlgorithmName() << ": " ;
      if( Ciphers[i]->BlockSize() < data.length() )
      { std::cout << cipher.length(); }
      else
      { std::cout << "N/A"; }
      std::cout << std::endl;
      cipher.clear();

      ////////////
      // CBC/FIPS
      ////////////
      /*
      CryptoPP::CFB_FIPS_Mode_ExternalCipher::Encryption
        // AES must always be 128 bit for FIPS. Does not
        //   apply to other ciphers
        fips( *(Ciphers[i]), iv, 128/8 );
      CryptoPP::StreamTransformationFilter stfFIPS(
        fips, new CryptoPP::StringSink( cipher )
      );

      stfFIPS.Put( (byte*)data.c_str(), data.length() );
      stfFIPS.MessageEnd();

      std::cout << " " << fips.StaticAlgorithmName();
      std::cout << " (FIPS): ";
      std::cout << cipher.length() << std::endl;
      cipher.clear();
      */
    }

    catch( CryptoPP::Exception& e )
    {
      std::cout << e.what() << std::endl;
    }

    catch( std::exception& e )
    {
      std::cout << e.what() << std::endl;
    }

    catch(...) { ; }

    std::cout << std::endl;
  }

  return 0;
}
