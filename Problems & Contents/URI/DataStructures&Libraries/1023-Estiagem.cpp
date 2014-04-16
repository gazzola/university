#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



int main(){
	
	int n, a, b, count=1;
	
	while(true){

		cin >> n;
		if(n==0)
			break;

		vector <int> vec;
		map <int, int> mapa;
		int last = -94941516;

		if(count > 1)
			cout << endl;
		cout << "Cidade# " << count << ":" << endl;


		int somam=0, somac=0;
		for(int i=1; i<=n; i++){
			cin >> a >> b;
			mapa[b/a] += a;
			vec.push_back(b/a);
			somac += b;
			somam += a;
		}

		sort(vec.begin(), vec.end()); //nlogn
		//tentar usar priority queue, diminui o tempo
		//tirar ins c++ e usar c
		//ou usar 2 maps e tentar ordenar com o iterador (pesquisar)

		int tam = vec.size();
		for(int i=0; i<tam; i++) {
			
			int x = vec[i];
			if(x != last){
				cout <<  mapa[x] << "-" << x;
				last = x;
				if(i < tam-1)
					cout << " ";
			}
		}


		double media = floor(100.0*somac/somam)/100.0;
		cout << fixed << setprecision(2)
			 << endl << "Consumo medio: " << media << " m3." << endl;
	
		count++;
	}

	return 0;
}