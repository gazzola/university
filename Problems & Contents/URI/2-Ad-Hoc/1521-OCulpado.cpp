#include <iostream>
#include <iomanip>

using namespace std;


int main(){
	
	int n, alunos[55], k;

	while(true){

		cin >> n;
		if(n == 0)
			break;

		for(int i=1; i<=n; i++)
			cin >> alunos[i];

		cin >> k;


		while(true){
			if(alunos[k] == k)
				break;
			else
				k = alunos[k];
		}

		cout << k << endl;

	}


	return 0;
}