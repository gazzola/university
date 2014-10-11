/*
* Trabalho 1.
* Implementacao de um conversor de decimal para binario.
*
* Os numeros podem estar no intervalo de 0 a 1023 (sem negativos).
* Os numeros podem ser ponto flutuantes.
* 
*
* Calculo Numerico
* Claudio Schepke
* ---
* Ciencia da Computacao
* Universidade Federal do Pampa
* 
*
* Integrantes:
* ---
* Marcos V. Treviso, 121150107, marcosvtreviso@gmail.com
*
*
* Instrucoes:
* ---
* Compile: g++ -o trab Trabalho1.cpp -Wall -Wextra
* Run: ./trab
*
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;


string intToBin(int number){
	
	if(number == 0)
		return "0";

	string bin = "";
	int base = 2;	// binary
	char buffer[12];

	while(number > 0){
		int rem = number%base;
		sprintf(buffer, "%d", rem);
		bin = buffer+bin;
		number /= base;
	}

	return bin;
}



int numDigits(int n){
	if(n == 0)
		return 1;
	return (int) log10(n) + 1;
}


string doubleToBin(double number, bool tokens, int precision){
	
	int e = numDigits((int) number);
	
	string exponent = "00000000000"; // 11 bits para o expoente
	if((int) number > 0){
		exponent = intToBin(e);
		while((int) exponent.size() < 11)
			exponent = "0"+exponent;
	}



	string sign = "1"; // 1 bit para o sinal
	if(number < 0)
		sign = "0";


	if((int) number > 0){
		int less = pow(10, e);
		number = number/less;
	}


	string fraction = "";
	int max = (precision < 4) ? 52 : precision;	// 52 bits de precisao para a parte fracionaria

	while(max--){

		if(number > 1.0)
			fraction += "1";
		else if(number < 1.0)
			fraction += "0";
		else{
			fraction += "1";
			break;
		}

		number = number - (int) number;
		number = number*2;

	}


	if(tokens)
		return sign+"|"+exponent+"|"+fraction;
	
	return sign+exponent+fraction;
}





int binToInt(string bin){
	
	int decimal = 0;
	for(int i=0; i<(int) bin.size(); i++){
		int j = bin[i] - '0';
		decimal = decimal*2 + j;
	}

	return decimal;
}

double binToDouble(string bin){

	string fraction = "";
	string exponent = "";

	char sign = bin[0];

	for(int i=1; i<12; i++)
		exponent += bin[i];

	int e = binToInt(exponent);


	int tam = bin.size();
	int end = tam-1;

	for(int i=tam-1; i>=0; i--){
		if(bin[i] == '1'){
			end = i;
			break;
		}
	}

	for(int i=12; i<=end; i++)
		fraction += bin[i];


	double decimal = 0;
	tam = fraction.size();
	for(int i=0; i<end; i++)
		if(fraction[i] == '1')
			decimal += 1.0/pow(2, (i+1));


	if(sign == '0')
		decimal = -decimal;

	return 2*decimal * pow(10, e);
}




int main(){
	
	string bin;
	double num;

	// numerals to binary
	cout << "Numerals to Binary:" << endl;

	num = 25;
	cout << num << " -> " << intToBin((int) num) << endl;
	
	num = 0.625;
	cout << num << " -> " << doubleToBin(num, false, 52) << endl;		


	cout << endl << "Binary to Numerals:" << endl; 

	// binary to numerals
	bin = "11001";
	cout << bin << " -> " << binToInt(bin) << endl;

	bin = "1000000000000101";
	cout << bin << " -> " << binToDouble(bin) << endl;

	return 0;
}