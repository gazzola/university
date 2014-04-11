#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int n, t, ammount[3]={0,0,0}, total;
	char type;

	cin >> n;

	while(n--){
		cin >> t >> type;
		if(type == 'C')
			ammount[0] += t;
		else if(type == 'R')
			ammount[1] += t;
		else
			ammount[2] += t;
	}

	total = ammount[0]+ammount[1]+ammount[2];
	cout << "Total: " << total << " cobaias" << endl;

	
	cout << "Total de coelhos: " << ammount[0] << endl;
	cout << "Total de ratos: " << ammount[1] << endl;
	cout << "Total de sapos: " << ammount[2] << endl;
	cout << fixed << setprecision(2) << "Percentual de coelhos: " << 100 * ammount[0]/double(total) << " %" << endl;
	cout << fixed << setprecision(2) << "Percentual de ratos: " << 100 * ammount[1]/double(total) << " %" << endl;
	cout << fixed << setprecision(2) << "Percentual de sapos: " << 100 * ammount[2]/double(total) << " %" << endl;

	return 0;
}