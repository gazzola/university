#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_NOTES 7
#define MAX_COINS 5


int main(){

	double nd, n;
	unsigned int notes[MAX_NOTES], coins[MAX_COINS];


	cin >> nd;
	n = int(nd);
	nd = (nd-n)*100;

	cout << "NOTAS:" << endl;
	for(int i=0, note=100; i<MAX_NOTES; ++i, note/=2){
		
		if(note == 25)
			note = 20;

		notes[i] = n/note;
		n -= notes[i]*note;

		if(i < MAX_NOTES-1)
			cout << notes[i] << " nota(s) de R$ " 
			 	 << note << ".00" << endl;
	}

	cout << "MOEDAS:" << endl;
	cout << notes[MAX_NOTES-1] << " moeda(s) de R$ " 
	 	 << "1.00" << endl;

	for(int j=0, coin=50; j<MAX_COINS; ++j, coin/=2){

		if(coin == 12)
			coin = 10;

		if(coin == 2)
			coin = 1;
		

		coins[j] = nd/coin;
		nd -= coins[j]*coin;

		cout << fixed << setprecision(2)
			 << coins[j] << " moeda(s) de R$ " 
			 << double(coin)/100 << endl;
	}

	return 0;
}