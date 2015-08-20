// Sample.cpp
//

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <assert.h>

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::ArraySink;
using CryptoPP::ArraySource;
using CryptoPP::StreamTransformationFilter;

#include "aes.h"
using CryptoPP::AES;

#include "modes.h"
using CryptoPP::CFB_Mode;

int main(int argc, char* argv[]){
    
    AutoSeededRandomPool rng;

    byte key[AES::DEFAULT_KEYLENGTH];
    rng.GenerateBlock( key, sizeof(key) );
    byte iv[AES::BLOCKSIZE];        

    string plaintext = "Licenses: 10";    

    const int ITERATIONS = 32;
    int countOf10 = 0;
    for( int i = 0; i < ITERATIONS; i++ ){
        
        string ciphertext, recovered;

        // Fresh IV
        rng.GenerateBlock( iv, sizeof(iv) );

        CFB_Mode<AES>::Encryption encryptor;
        encryptor.SetKeyWithIV(key, sizeof(key), iv);

        StringSource( plaintext, true,
            new StreamTransformationFilter(
                encryptor,
                new StringSink( ciphertext )
            )
        );

        ///////////////////////////////////
        // Tamper
        ciphertext[10] |= 6;
        //
        ///////////////////////////////////

        CFB_Mode<AES>::Decryption decryptor;
        decryptor.SetKeyWithIV(key, sizeof(key), iv);

        StringSource( ciphertext, true,
            new StreamTransformationFilter(
                decryptor,
                new StringSink( recovered )
            )
        );

        if( recovered == plaintext )
            countOf10++;

        cout << recovered << endl;
    }

    return 0;
}

