#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long unsigned int llu;



// http://en.wikipedia.org/wiki/Hamming_weight
// ---
// This uses fewer arithmetic operations than any other known  
// implementation on machines with fast multiplication.
// It uses 12 arithmetic operations, one of which is a multiply.
int count1(llu x) {
    int count;
    for (count=0; x; count++)
        x &= x-1;
    return count;
}

int getBase(llu x){
	return (int) log2(x);
}


llu countBase(int base){
	return base * (1LL << (base-1));
}

llu countNumber(llu x){
	llu b = getBase(x);
	llu t = countBase(b);
	llu y = x-(1LL << (b-1));
	t += y;

	while(b > 8){
		b = getBase(y);
		t += countBase(b);
		y = y-(1LL << (b-1));
		t += y;
	}

	return t;
} 



int main(){
	
	llu a, b;
	while(scanf("%llu %llu", &a, &b) != EOF){

		printf("%llu\n", countNumber(b) - countNumber(a));


	}
	

	return 0;
}




/*
000
001
010
011
100
101
110
111
---
3 * 2^2
*/