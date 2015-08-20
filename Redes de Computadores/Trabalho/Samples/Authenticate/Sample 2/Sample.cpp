// Sample.cpp
//

#include "stdafx.h"

#include "osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;

#include "aes.h"
using CryptoPP::AES;

#include "eax.h"
using CryptoPP::EAX;

int main(int argc, char* argv[]){
    
    AutoSeededRandomPool rng;

    byte key[AES::DEFAULT_KEYLENGTH];
    rng.GenerateBlock( key, sizeof(key) );
    byte iv[AES::BLOCKSIZE];
    rng.GenerateBlock( iv, sizeof(iv) );

    string plaintext = "Licenses: 10";
    string ciphertext, recovered;

    try{
        
        EAX<AES>::Encryption encryptor;
        encryptor.SetKeyWithIV(key, sizeof(key), iv);

        StringSource( plaintext, true,
            new AuthenticatedEncryptionFilter(
                encryptor,
                new StringSink( ciphertext )
            )
        );

        ///////////////////////////////////
        // Tamper
        // ciphertext[10] ^= 0x01;
        //
        ///////////////////////////////////

        EAX<AES>::Decryption decryptor;
        decryptor.SetKeyWithIV(key, sizeof(key), iv);

        StringSource( ciphertext, true,
            new AuthenticatedDecryptionFilter(
                decryptor,
                new StringSink( recovered )
            )
        );

        cout << "Recovered: " << recovered << endl;
    }
    catch( const exception& e ){
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
