#include <iostream>
#include <cstdio>

using namespace std;



int main(){
	
	int n;
	int postes[5001];
	
	while(true){

		scanf("%d", &n);
		if(n == 0)
			break;

		int primeiro = -1;
		for(int i=0; i<n; i++){
			scanf("%d", &postes[i]);
			if(postes[i] == 1 and primeiro == -1){
				primeiro = i;
			}
		}

		
		int count = 0;
		int zeros = 0;
		int start = primeiro+1;
		bool tudoZero = false;

		if(primeiro == -1){
			tudoZero = true;
			primeiro = n-1;
			start = 0;
		}
		else if(primeiro+1 == n){
			start = 0;
		}

		int i = start;
		while(true){
			
			if(postes[i] == 0){
				zeros++;
			}
			else
				zeros = 0;

			if(zeros == 2){
				count++;
				zeros = 0;
			}

			if(i == primeiro)
				break;

			if(i == n-1){
				i = 0;
				if(i == primeiro)
					break;
				i--;
			}

			i++;
		}

		if(tudoZero and n%2 != 0)
			count++;

		printf("%d\n", count);

		
	}

	return 0;
}