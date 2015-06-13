#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;


typedef pair<int, int> ii;
typedef long long unsigned int llu;


int main(){
	
	llu a, b;
	scanf("%llu %llu", &a, &b);

	llu x = (a*(a+1))/2;
	llu y = (b*(b+1))/2;

	printf("%llu\n", y-x+a);

}
