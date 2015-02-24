#include <cstdio>
#include <cstring>


const int MAXB = 128;
const int MAXF = 512;

typedef int bigint[MAXB];
bigint fibs[MAXF];


void bigintZero(bigint a){
	for(int i=0 ; i<MAXB ; i++)
		a[i] = 0;
}


void bigintFromString(char *s, bigint a, int n){
	bigintZero(a);
	for(int i=n-1 ; i>=0 ; i--)
		a[i] = *s++ - '0';
}


void bigintAdd(bigint a, bigint b, bigint c){
	int carry=0;
	for(int i=0 ; i<MAXB ; i++){
		c[i] = carry + a[i] + b[i];
		carry = c[i] / 10;
		c[i] %= 10;
	}
}



int bigintCompare(bigint a, bigint b){
	int i;
	for(i=MAXB-1 ; i>=0 ; i--)
		if(a[i] > b[i])
			return 1;
		else if(a[i] < b[i])
			return -1;
	return 0;
}



int binSearch(int ini, int fim, bigint &ba){
	int med=0;
	while(fim >= ini){

		med = (ini+fim)/2;
		//printf("%d ", med);

		int cp1 = bigintCompare(fibs[med], ba);
		int cp2 = bigintCompare(fibs[med-1], ba);

		if(cp1 >= 0 and cp2 < 0)
			break;

		if(cp1 > 0 or cp2 > 0)
			fim = med - 1;
		else
			ini = med + 1;
	}

	return med;
}


int main(){

	
	bigintZero(fibs[0]);
	fibs[0][0] = 1;
	
	bigintZero(fibs[1]);
	fibs[1][0] = 2;
	
	for(int i=2; i<MAXF; i++)
		bigintAdd(fibs[i-2], fibs[i-1], fibs[i]);
	

	bigint bz, ba, bb;
	char sa[MAXB], sb[MAXB];

	bigintZero(bz);

	while(true){
		
		int n1, n2;
		scanf(" %s%n %s%n ", sa, &n1, sb, &n2);

		n2 = n2-n1-1;
		bigintFromString(sa, ba, n1);
		bigintFromString(sb, bb, n2);

		if(n1 == 1 && n2 == 1 && bigintCompare(ba, bz) == 0 && bigintCompare(bb, bz) == 0) 
			break;


		int ia, ib;
		ia = binSearch(0, MAXF-1, ba);

		for(ib=ia; ib<MAXF ; ib++)
			if(bigintCompare(fibs[ib], bb) > 0) 
				break;

		
		printf("%d\n", ib-ia);
	}

	return 0;
}