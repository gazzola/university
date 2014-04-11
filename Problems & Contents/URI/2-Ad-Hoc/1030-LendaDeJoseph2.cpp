#include <iostream>
#include <iomanip>

using namespace std;



void tirarElemento(int *v, int *tam, int pos){

	for(int i=pos; i<*tam; i++)
		v[i] = v[i+1];

	*tam -= 1;
}

void mostrarVetor(int *v, int tam){
	for(int i=0; i<tam; i++)
		cout << v[i] << " ";
	cout << endl;
}

void preecherVetor(int *v, int tam){
	for(int i=0; i<tam; i++)
		v[i] = i;
}

int restoPular(int *v, int tam, int pulo){

	int qtd = tam, mortos=1, i=pulo-1;
	preecherVetor(v, tam);

	while(mortos <= tam){


		mostrarVetor(v, qtd);
		tirarElemento(v, &qtd, i);
		i--;
		mortos++;
	
		
		if(i+pulo >= qtd)
			i += pulo-qtd;
		else
			i += pulo;
	

	}

	return v[0]+1;
}



int main(){
	
	int n, a, b, result, c=1;
	cin >> n;
	while(n--){

		cin >> a >> b;
		
		int* array = new int[a]();
		result = restoPular(array, a, b);
		delete[] array;
		
		cout << "Case " << c++ << ": " << result << endl;
	}

	return 0;
}


/*


0 | 1 | 2 | 3 | 4
    x       

0 | 2 | 3 | 4
	    x

0 | 2 | 4 |
x

2 | 4
    x


    3+2 > tam
    i = 3+2-tam



*/