#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, anos, tempo;
	string nome;

	while(true){

		cin >> n;
		if(n==0)
			break;

		int menor = 999999;
		string menorNome = "";
		while(n--){
			cin >> nome >> anos >> tempo;
			if(anos-tempo < menor){
				menor = anos-tempo;
				menorNome = nome;
			}
		}

		cout << menorNome << endl;
	}

	return 0;
}