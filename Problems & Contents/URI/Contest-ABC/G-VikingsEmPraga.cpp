#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;

void preencheLista(deque<char> &v){
	for(int i='A'; i<='Z'; i++)
		v.push_back((char) i);
}


void moveToFirst(deque<char> &v, int pos){
	char a = v[pos];
	v.erase(v.begin()+pos);
	v.push_front(a);
}


int main(){
	
	int n, x, t=1;	

	while(scanf("%d", &n) and n > 0){
		printf("Instancia %d\n", t++);
		deque<char> v;
		preencheLista(v);

		while(n--){
			scanf("%d", &x);
			printf("%c", v[x-1]);
			moveToFirst(v, x-1);
		}

		printf("\n\n");
	}


}

