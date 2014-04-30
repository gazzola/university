#include <cstdio>

int funRafael(int *x, int *y){
	int t = 3*(*x);
	return ((t*t) + ((*y)*(*y)));
}

int funBeto(int *x, int *y){
	int t = 5*(*y);
	return (2*((*x)*(*x)) + t*t); 
}

int funCarlos(int *x, int *y){
	return (-100*(*x) + ((*y) * (*y) * (*y)));
}


int main(){
	
	int n, x, y;
	scanf("%d", &n);

	while(n--){

		scanf("%d %d", &x, &y);
		int r = funRafael(&x, &y);
		int b = funBeto(&x, &y);
		int c = funCarlos(&x, &y);

		if(r > b && r > c)
			printf("Rafael ganhou\n");
		else if(b > r && b > c)
			printf("Beto ganhou\n");
		else if(c > r && c > b)
			printf("Carlos ganhou\n");

	}
		

	return 0;
}
