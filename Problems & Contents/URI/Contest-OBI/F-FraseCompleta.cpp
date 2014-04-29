#include <cstdio>
#include <cstring>
#include <iostream>


int main(){

	int n;
	char c, str[1000];
	int alfabeto[26];

	scanf("%d ", &n);
	while(n--){

		scanf("%[^\n]", str);
		scanf("%c", &c);

		memset(alfabeto, 0, sizeof(alfabeto));
		int total=0, tam=strlen(str);

		for(int i=0; i<tam; i++){
			int pos = (int) str[i];
			if(pos >= 97 && pos <= 122){
				if(alfabeto[pos-97] == 0){
					alfabeto[pos-97] = 1;
					total++;
				}
			}
		}

		if(total == 26)
			printf("frase completa\n");
		else if(total < 26 && total >= 13)
			printf("frase quase completa\n");
		else
			printf("frase mal elaborada\n");

	}


	return 0;
}
