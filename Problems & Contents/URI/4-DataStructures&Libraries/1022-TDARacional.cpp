#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

int gcd(int a, int b){
	int c;
		while (a != 0){
		c = a; 
		a = b%a;  
		b = c;
	}

	return b;
}


int main(){
	
	int tarefas, N1, D1, N2, D2, val1, val2;
	char e, op;

	scanf("%d", &tarefas);
	while(tarefas--){

		scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);


		if(op == '+'){
			val1 = N1*D2 + N2*D1;
			val2 = D1*D2;
		}
		else if(op == '-'){
			val1 = N1*D2 - N2*D1;
			val2 = D1*D2;
		}
		else if(op == '*'){
			val1 = N1*N2;
			val2 = D1*D2;
		}
		else if(op == '/'){
			val1 = N1*D2;
			val2 = N2*D1;
		}

	
		int d = gcd(abs(val1), abs(val2));

		cout << val1 << "/" << val2 << " = "; 
		cout << val1/d << "/" << val2/d << endl;

	}

	return 0;
}