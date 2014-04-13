#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int verficia(int *v, int tam){
	 
	for(int i=3; i<=tam; i++)
		if(v[i-2] == v[i-1] && v[i-1] == v[i])
			return i-2;
		
	return tam+1;
}

int main(){
	 
	int r, x, somamark, somaleti, markcons, leticons;
	int mark[12], leti[12];
	
	while(true){
		
		cin >> r;
		if(r == 0)
			break;
		
		somamark = somaleti = 0;
		for(int i=1; i<=r; i++){
			cin >> mark[i];
			somamark += mark[i];
		}
		
		for(int i=1; i<=r; i++){
			cin >> leti[i];
			somaleti += leti[i];
		}
		
		markcons = verficia(mark, r);
		leticons = verficia(leti, r);
		
		if(markcons < leticons)
			somamark += 30;
		else if(leticons < markcons)
			somaleti += 30;
		
		if(somamark > somaleti)
			cout << "M" << endl;
		else if(somaleti > somamark)
			cout << "L" << endl;
		else
			cout << "T" << endl;
	}
	
	return 0;
}