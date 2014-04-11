#include <iostream>

using namespace std;

int main(){

	string msg = "DDD nao cadastrado";
	int ddd;
    cin >> ddd;

    if(ddd == 61)
    	msg = "Brasilia";
    else if(ddd == 71)
    	msg = "Salvador";
    else if(ddd == 11)
    	msg = "Sao Paulo";
    else if(ddd == 21)
    	msg = "Rio de Janeiro";
    else if(ddd == 32)
    	msg = "Juiz de Fora";
    else if(ddd == 19)
    	msg = "Campinas";
    else if(ddd == 27)
    	msg = "Vitoria";
    else if(ddd == 31)
    	msg = "Belo Horizonte";

    cout << msg << endl;

	return 0;
}