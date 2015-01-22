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

#include "ccm.h"
using CryptoPP::CCM;

int main(int argc, char* argv[])
{
    AutoSeededRandomPool rng;

    byte key[AES::DEFAULT_KEYLENGTH];
    rng.GenerateBlock( key, sizeof(key) );
    byte iv[AES::BLOCKSIZE];
    rng.GenerateBlock( iv, sizeof(iv) );

    string plaintext = "Licenses: 10";
    string ciphertext, recovered;

    const int TAG_SIZE = 12; // 96 bit authenticator

    try
    {
        CCM<AES,TAG_SIZE>::Encryption encryptor;
        encryptor.SetKeyWithIV(key, sizeof(key), iv);
        encryptor.SpecifyDataLengths( 0, plaintext.size() );

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

        CCM<AES, TAG_SIZE>::Decryption decryptor;
        decryptor.SetKeyWithIV(key, sizeof(key), iv);
        decryptor.SpecifyDataLengths( 0, ciphertext.size()-TAG_SIZE );

        StringSource( ciphertext, true,
            new AuthenticatedDecryptionFilter(
                decryptor,
                new StringSink( recovered )
            )
        );

        cout << "Recovered: " << recovered << endl;
    }
    catch( const exception& e )
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
