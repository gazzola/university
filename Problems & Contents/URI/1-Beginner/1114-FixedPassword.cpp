#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int pass;

	while(true){
		cin >> pass;

		if(pass == 2002){
			cout << "Acesso Permitido" << endl;
			break;
		}
		else{
			cout << "Senha Invalida" << endl;
		}
	}

	return 0;
}