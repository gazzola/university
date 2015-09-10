#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool inter(int x, int i, int j){
	return (x >= i and x <= j);
}



int main(){

	int a,b;
	scanf("%d %d", &a, &b);


	if(inter(b, 0, 2))
		printf("nova\n");
	else if(inter(b, 97, 100))
		printf("cheia\n");
	else if(inter(b, 3, 96) and b-a >= 0)
		printf("crescente\n");
	else
		printf("minguante\n");


	return 0;
}
