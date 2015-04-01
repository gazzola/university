#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
 
using namespace std;
 
 
 
const char *z1 = "0";
const char *z2 = "00";
const char *e1 = " ";
const char *e2 = "  ";
 
 
void printarZero(int qtd){
	 if(qtd > 2){
		  while(qtd > 255){
				printf("#%c", 255);
				qtd -= 255;
		  }
		  printf("#%c", qtd);
	 }
	 else if(qtd > 0)
		  printf("%s", (qtd == 2) ? z2 : z1);
}
 
 
void printarEspaco(int qtd){
	 if(qtd > 2){
		  while(qtd > 255){
				printf("$%c", 255);
				qtd -= 255;
		  }
		  printf("$%c", qtd);
	 }
	 else if(qtd > 0)
		  printf("%s", (qtd == 2) ? e2 : e1);
}
 
 
 
int main(){
  
	 int n;
	 char c;
 
 
	 scanf("%d\n", &n);
	 while(n--){
 
		  int z = 0;
		  int e = 0;
 
		  while(scanf("%c", &c) != EOF and c != '\n'){
 
				if(c == '0'){
					 printarEspaco(e);
					 e = 0;
					 z++;
				}
				else if(c == ' '){
					 printarZero(z);
					 z = 0;
					 e++;
				}
				else{
					 printarZero(z);
					 printarEspaco(e);
					 z = e = 0;
					 printf("%c", c);
				}
		  }
 
		  printarZero(z);
		  printarEspaco(e);
		  printf("\n");
			
	 }
 
  
	 return 0;
}