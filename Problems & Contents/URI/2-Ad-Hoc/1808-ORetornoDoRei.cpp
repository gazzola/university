#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;




int main(){
	
	char s[101];
	scanf("%s", s);
	vector<int> notas;

	for(int i=0; s[i]!='\0'; i++){
		if(s[i] == '1'){
			if(s[i+1] == '0'){
				notas.push_back(10);
				i++;
			}
			else
				notas.push_back(1);
		}
		else
			notas.push_back((int) s[i]-'0');
	}

	int soma = 0;
	for(int i=0; i<(int) notas.size(); i++)
		soma += notas[i];

	printf("%.2lf\n", (double) soma/(double) notas.size());


	return 0;
}