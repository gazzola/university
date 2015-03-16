#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>


using namespace std;




int main(){
 	
 	
 	int n;
 	while(scanf("%d", &n) and n > 0){

 		printf("Discarded cards:");

 		deque<int> fila;
 		for(int i=1; i<=n; i++)
			fila.push_front(i);


 		while(fila.size() > 1){

 			printf(" %d", fila.back());
 			fila.pop_back();


 			if(fila.size() > 1){
 				printf(",");
 				int x = fila.back();
 				fila.pop_back();
 				fila.push_front(x);
 			}

 		}
 		
 		printf("\nRemaining card: %d\n", fila.back());


 	}


 
	return 0;
}