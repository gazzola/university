#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	
	int n, x;
	
	scanf("%d", &n);	
	int *mictorios = new int(n);

	for(int i=0; i<n; i++){
		scanf("%d", &x);
		mictorios[x] = 1;
	}


	int i;
	for(i=1; i<n; i++)
		if(mictorios[i-1] == 0 and mictorios[i] == 0 and mictorios[i+1] == 0)
			break;

	if(i == n)
		printf("*\n");
	else
		printf("%d\n", i);



	return 0;
}