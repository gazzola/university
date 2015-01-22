// Sample.cpp
//

#include "stdafx.h"

// Runtime Includes
#include <iostream>
#include <string>

// Crypto++ Includes
#include "aes.h"
#include "modes.h" // xxx_Mode< >
#include "filters.h" // StringSource and
                     // StreamTransformation
#include "osrng.h"
#include "hex.h"

int main(int argc, char* argv[])
{

    ///////////////////////////////////////
    // Key and Counter //
    ///////////////////////////////////////

    byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ];
    byte counter[ CryptoPP::AES::BLOCKSIZE ];
    byte next[ CryptoPP::AES::BLOCKSIZE ];  // next counter

    ::memset( key, 0xAA, CryptoPP::AES::DEFAULT_KEYLENGTH );
    ::memset( counter, 0x00, CryptoPP::AES::BLOCKSIZE );

    ///////////////////////////////////////
    // Sources and Sinks                 //
    ///////////////////////////////////////

    // Message M
    std::string PlainText;

    // Cipher Text Sink
    std::string CipherText;

    // Recovered Text Sink
    std::string RecoveredText;

    ///////////////////////////////////////
    // Random Data                       //
    ///////////////////////////////////////
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::RandomNumberSource( rng,
        CryptoPP::AES::BLOCKSIZE,
        true, new CryptoPP::StringSink( PlainText )
    );

    ///////////////////////////////////////
    // Encryption                        //
    ///////////////////////////////////////

    CryptoPP::CTR_Mode< CryptoPP::AES >::Encryption Encryptor;
    Encryptor.SetKeyWithIV( key, sizeof(key), counter );

    CryptoPP::StringSource( PlainText, true,
        new CryptoPP::StreamTransformationFilter(
          Encryptor,
          new CryptoPP::StringSink( CipherText )
        ) // StreamTransformationFilter
    ); // StringSource

    ///////////////////////////////////////
    // Next Counter Value                //
    ///////////////////////////////////////
    Encryptor.GetNextIV( rng, next );

    ///////////////////////////////////////
    // Decryption                        //
    ///////////////////////////////////////

    CryptoPP::CTR_Mode< CryptoPP::AES >::Decryption Decryptor;
    Decryptor.SetKeyWithIV( key, sizeof(key), counter );

    CryptoPP::StringSource( CipherText, true,
        new CryptoPP::StreamTransformationFilter(
          Decryptor,
          new CryptoPP::StringSink( RecoveredText )
        ) // StreamTransformationFilter
    ); // StringSource

    //////////////////////////////////////////
    // Output                               //
    //////////////////////////////////////////

    cout << "Algorithm: ";
    cout << Encryptor.AlgorithmName() << endl;
    cout << endl;

    cout << "Default Key Size: ";
    cout << Encryptor.DefaultKeyLength() << " bytes" << endl;

    cout << "Block Size: ";
    cout << Encryptor.BlockSize() << " bytes" << endl;
    cout << endl;

    cout << "Plain Text: " << PlainText.length() << " bytes" << endl;
    cout << "Cipher Text: " << CipherText.length() << " bytes" << endl;
    cout << "Recovered Text:" << RecoveredText.length() << " bytes" << endl;
    cout << endl;

    //////////////////////////////////////////
    // Original Counter
    //////////////////////////////////////////
    std::string hexbytes;
    CryptoPP::ArraySource(
        (const byte*)counter, CryptoPP::AES::BLOCKSIZE, true,
        new CryptoPP::HexEncoder(
            new CryptoPP::StringSink( hexbytes ), true, 2
        )
    );

    cout << "Original Counter: " << endl;
    cout << hexbytes << endl;

    //////////////////////////////////////////
    // Next Counter
    //////////////////////////////////////////
    hexbytes.clear();
    CryptoPP::ArraySource(
        (const byte*)next, CryptoPP::AES::BLOCKSIZE, true,
        new CryptoPP::HexEncoder(
            new CryptoPP::StringSink( hexbytes ), true, 2
        )
    );

    cout << "Next Counter: " << endl;
    cout << hexbytes << endl;

    return 0;
}

