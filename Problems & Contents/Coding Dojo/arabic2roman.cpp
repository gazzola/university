/*
* By Fabio Kepler
* compile: (g++ -std=c++11 -o arabic2roman arabic2roman.cpp -Wall
*/


#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, map<int, string>> romanNumerals = {
    {0, {{1, "I"}, {5, "V"}}},
    {1, {{1, "X"}, {5, "L"}}},
    {2, {{1, "C"}, {5, "D"}}},
    {3, {{1, "M"}}}};

int main() {
    while (true) {
        string number;
        cout << "Número (natural) arábico: ";
        cin >> number;
        int arabic_int = 0;
        try {
            arabic_int = stoi(number);
            if (arabic_int > 3999) {
                cerr << "Intervalo inválido" << endl;
                continue;
            }
        } catch (invalid_argument e) {
            cerr << "Número inválido" << endl;
            continue;
        }

        string arabicStr = to_string(arabic_int);
        reverse(arabicStr.begin(), arabicStr.end());
        string romanStr = "";

        for (unsigned int i = 0; i < arabicStr.size(); i++) {
            
            string algarismStr = string(1, arabicStr[i]);
            int algarism = stoi(algarismStr);
            
            while (algarism > 0) {
                if (algarism == 9) {
                    algarism = 0;
                    romanStr = romanNumerals[i][1] + romanNumerals[i+1][1] + romanStr;
                } else if (algarism == 4) {
                    algarism = 0;
                    romanStr = romanNumerals[i][1] + romanNumerals[i][5] + romanStr;
                } else if (algarism == 5) {
                    algarism -= 5;
                    romanStr = romanNumerals[i][5] + romanStr;
                } else {
                    algarism -= 1;
                    romanStr = romanNumerals[i][1] + romanStr;
                }
            }
        }

        cout << "Número romano: " << romanStr << endl;
    }
    return 0;
}

