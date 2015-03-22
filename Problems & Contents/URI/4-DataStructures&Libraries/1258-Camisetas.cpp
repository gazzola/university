#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
#include <tuple>

using namespace std;

typedef tuple<string, char, string> scs; //C++11

bool orderBy(const scs &x, const scs &y){

	string x_cor = get<0>(x);
	char x_tam = get<1>(x);
	string x_nome = get<2>(x);

	string y_cor = get<0>(y);
	char y_tam = get<1>(y);
	string y_nome = get<2>(y);

	if(x_cor < y_cor)
		return true;
	else if(x_cor > y_cor)
		return false;

	if(x_tam > y_tam)
		return true;
	else if(x_tam < y_tam)
		return false;

	return (x_nome < y_nome);
}



int main(){

	int n;
	bool first = true;

	while(scanf("%d", &n) and n > 0){

		vector<scs> cams;
		string nome, cor;
		char tam;

		while(n--){

			getchar();
			getline(cin, nome);
			cin >> cor >> tam;

			cams.push_back(scs(cor, tam, nome));

		}


		sort(cams.begin(), cams.end(), orderBy);

		if(!first)
			printf("\n");

		for(int i=0; i<(int) cams.size(); i++)
			cout << get<0>(cams[i]) << " " <<
		            get<1>(cams[i]) << " " <<
		            get<2>(cams[i]) << endl;

		first = false;
	}
	

		
	return 0;
}