// Sample.cpp
//

#include "stdafx.h"

// Runtime Includes
#include <iostream>
#include <string>

// Crypto++ Includes
#include "default.h"
#include "filters.h" // StringSource and
                     // StreamTransformation
#include "osrng.h"
#include "hex.h"

using std::string;
using std::cout;
using std::endl;

using CryptoPP::DefaultEncryptorWithMAC;
using CryptoPP::DefaultDecryptorWithMAC;
using CryptoPP::StringSink;
using CryptoPP::StringSource;

int main(int argc, char* argv[])
{
    string message = "secret message";    
    string password = "password";
    string encrypted, recovered;

    StringSource(
        message,
        true,
        new DefaultEncryptorWithMAC(
            password.c_str(),
            password.length(),
            new StringSink( encrypted )
        ) // DefaultEncryptorWithMAC
    ); // StringSource

    StringSource(
        encrypted,
        true,
        new DefaultDecryptorWithMAC(
            password.c_str(),
            new StringSink( recovered )
        ) // DefaultDecryptorWithMAC
    ); // StringSource

    cout << "Recovered Text:" << endl;
    cout << "  " << recovered << endl;

    return 0;
}

