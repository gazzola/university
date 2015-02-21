#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int A, B, C;
	while (scanf ("%d%d%d", &A, &B, &C) && A != 0 && B != 0 && C != 0){
		if (B > C)
			swap(B, C);
		if (A > B)
			swap(A, B);
		if (B > C)
			swap(B, C);
		if (A != B && B != C){
			printf ("1 1 2\n");
			continue;
		}
		if (A == C){
			if (A == 13)
				printf("*\n");
			else
				printf("%d %d %d\n", A+1, A+1, A+1);
			continue;
		}
		int ra, rb, rc;
		if (A == B && (A < 13 || (A == 13 && C < 12))){
			if (C < 13)
				printf("%d %d %d\n", A, A, C+1);
			else
				printf("%d %d %d\n", 1, A+1, A+1);
			continue;
		}
		if (B == C && (B < 13 || (B == 13 && A < 12))){
			if (A == 13)
				printf("%d %d %d\n", 1, B+1, B+1);
			else{
				if (A + 1 == B)
					printf("%d %d %d\n", B, B, A+2);
				else
					printf("%d %d %d\n", A+1, B, B);
			}
			continue;
		}
		printf ("1 1 1\n");
	}
	return 0;
}
