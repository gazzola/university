#include <cstdio>


int main(){
	
	int n, la, lb, sa, sb;
	scanf("%d %d %d %d %d", &n, &la, &lb, &sa, &sb);

	if(n >= la and n <= lb and n >= sa and n <= sb)
		printf("possivel\n");
	else
		printf("impossivel\n");

	return 0;
}
