#include <cstdio>
#include <string>
#include <cstring>

using namespace std;



int ctoi(char c){
	return (int) c - 'a';
}


int main(){

	int n;
	char d;
	char num[1001];

	while(scanf("%c %s%n\n", &d, num, &n) and d != '0' and num[0] != '0'){

		n = n-2;

		string s;
		for(int i=0; i<n; i++)
			if(num[i] != d)
				s.push_back(num[i]);
		

		
		int i = 0;
		while(s[i] == '0' and i < (int) s.size())
			i++;

		if(i == (int) s.size())
			printf("0");
		else{
			while(i < (int) s.size() and s[i+1] != '\n')
				printf("%c", s[i++]);
		}

		printf("\n");

	}

	return 0;
}