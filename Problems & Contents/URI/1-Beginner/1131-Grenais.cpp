#include <iostream>
#include <iomanip>

using namespace std;


int main(){

	int x, i, g, ammount=0, wini=0, wing=0, draw=0;

	while(true){

		cin >> i >> g >> x;
		cout << "Novo grenal (1-sim 2-nao)" << endl;
		ammount++;

		if(i > g)
			wini++;
		else if(g > i)
			wing++;
		else
			draw++;

		if(x == 2)
			break;	
	}

	cout << ammount << " grenais" << endl;
	cout << "Inter:" << wini << endl;
	cout << "Gremio:" << wing << endl;
	cout << "Empates:" << draw << endl;
	
	if(wini > wing)
		cout << "Inter venceu mais" << endl;
	else if(wing > wini)
		cout << "Gremio venceu mais" << endl;
	else
		cout << "Nao houve vencedor" << endl;
	

	return 0;
}