#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

bool caiuArmadilha(int *arm, int pos){

	for(int i=0; i<3; i++)
		if(arm[i] == pos)
			return true;
	return false;
}


int proxJogador(int *ociosos, int atual, int total){

	while(ociosos[atual] == 1){
		ociosos[atual] = 0;
		atual = (atual%total)+1;
	}

	return atual;
}



int main(){
	
	int p, s, n, d1, d2;
	int armads[3];
	int jogadores[11];
	int ociosos[11];

	while(true){

		//cin >> p >> s;
		scanf("%d %d", &p, &s);

		if(p==0 && s==0)
			break;

		for(int i=0; i<3; i++)
			scanf("%d", &armads[i]);
		
		//cin >> n;
		scanf("%d", &n);

		memset(jogadores, 0, sizeof(jogadores));
		memset(ociosos, 0, sizeof(ociosos));
		int j = 0;

		for(int i=0; i<n; i++){

			j = proxJogador(ociosos, (j%p)+1, p);

			//cin >> d1 >> d2;
			scanf("%d %d", &d1, &d2);
			jogadores[j] += d1+d2;

			if(caiuArmadilha(armads, jogadores[j]))
				ociosos[j] = 1;
		}

		for(int i=1; i<=p; i++){
			if(jogadores[i] > s){
				//cout << i << endl;
				printf("%d\n", i);
				break;
			}
		}


	}

	return 0;
}