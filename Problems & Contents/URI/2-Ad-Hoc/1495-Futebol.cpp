#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

bool wayToSort(int i, int j){ //descend
	return i > j; 
}

int main(){
	
	int n, g, vet[100001];;
	while(cin >> n >> g){
		
		int s, r, pontos=0, ganhou=0, perdeu=0, menor=-9999999;
									//ou empatou

		for(int i=0; i<n; i++){
			cin >> s >> r;
			
			if(s <= r){
				vet[perdeu] = s-r;
				perdeu++;
				if(vet[perdeu] < menor)
					menor = vet[perdeu];
			}
			else
				ganhou++;
		}


		sort(vet, vet+perdeu, wayToSort);

		pontos = ganhou*3;
		menor = abs(menor)+1;
		if(menor > g)
			menor = 1;

		int count=0, i=0;
		while(g > 0){
			if(vet[i] < 1){
				vet[i] += menor;
				g -= menor;
				
				if(g < 1)
					break;

				if(vet[i] > 0){
					count++;
					i++;
				}
			}

			if(count == perdeu)
				break;
		}
		

	
		for(int i=0; i<perdeu; i++){
			if(vet[i] > 0)
				pontos += 3;
			else if(vet[i] == 0)
				pontos += 1;
		}
	

		cout << pontos << endl;

	}

	return 0;
}