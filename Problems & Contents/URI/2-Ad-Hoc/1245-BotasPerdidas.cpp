#include <iostream>
#include <iomanip>

using namespace std;

int min(int *a, int *b){
	return (*a < *b) ? *a : *b;
}

int main(){
	
	int n, m;
	char l;

	while(true){
		if(cin >> n){
			
			int *md = new int[32]();
			int *me = new int[32]();

			while(n--){
				cin >> m >> l;
				if(l == 'D')
					md[m-30] += 1;
				else
					me[m-30] += 1; 
			}

			int total=0;
			for(int i=0; i<32; i++)
				total += min(md[i], me[i]);
			
			cout << total << endl;

			delete[] md;
			delete[] me;
		}
		else{
			break;
		}
	}

	return 0;
}
