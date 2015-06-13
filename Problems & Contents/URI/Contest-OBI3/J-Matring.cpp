#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;



int ctoi(char c){
	return (int) c - '0'; 
}

int main(){
	
	int s[500], n, r=1000;
	char linha[500];

	memset(s, 0, sizeof(s));
	
	while(scanf("%[^\n]%n\n", linha, &n) != EOF){
		for(int i=0; i<n; i++)
			s[i] += ctoi(linha[i])*r;
		r /= 10;
	}


	int F = s[0];
	int L = s[n-1];

	for(int i=1; i<n-1; i++)
		printf("%c", (F*s[i] + L) % 257);
	
	printf("\n");
	

}
