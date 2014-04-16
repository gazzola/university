#include <iostream>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>

using namespace std;



int main(){
	
	int n, a, b, count=1;
	
	while(true){

		cin >> n;
		if(n==0)
			break;

		//priority_queue<int, vector<int>, greater<int> > fila;
		map <int, int> mapa;
		map <int, int> :: const_iterator iter;

		if(count > 1)
			cout << endl;

		cout << "Cidade# " << count << ":" << endl;


		int somam=0, somac=0;
		for(int i=0; i<n; i++){
			cin >> a >> b;
			mapa[b/a] += a;
			//fila.push(b/a);
			somac += b;
			somam += a;
		}


		/*int x = fila.top();
		cout <<  mapa[x] << "-" << x;
		fila.pop();

		int tam = fila.size();
		while (tam--){
			x = fila.top();
			cout << " " <<  mapa[x] << "-" << x;
			fila.pop();
		}*/


		iter = mapa.begin();
		cout << iter->second << "-" << iter->first;
		iter++;
		for(iter; iter != mapa.end(); iter++){
			cout << " " << iter->second << "-" << iter->first;	
		}

		double media = floor(100.0*somac/somam)/100.0;
		cout << fixed << setprecision(2)
			 << endl << "Consumo medio: " << media << " m3." << endl;
	
		count++;
	}

	return 0;
}