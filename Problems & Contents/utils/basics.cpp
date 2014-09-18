```cpp
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int numDigits(int n){
	if(n == 0)
		return 1;
	return (int) log10(n) + 1;
}


// bubble sort, retorna o numero de trocas
int bubble(int *v, int *t, int n){
	
	int i, j, k=n-1, c=0;

	for(i=0; i<n; i++){
		for(j=0; j<k; j++){
			if(v[j] == t[i])
				swap(v[j], v[j+1]);
			else
				c++;
		}
		k--;
	}

	return c;
}


vector<int> pegaDigito(int x){
	vector<int> digits;
	while(x != 0){
		int pos = x%10;
		digits.push_back(pos);
		x /= 10;
	}

	return digits;
}

int inverterDigitos(int n){
	int reverse = 0;
	while(n != 0){
		reverse = reverse*10 + n%10;
		n /= 10;
	}

	return reverse;
}


int countOccurrences(char *from, char *sub){
	
	int total = 0;
	char *tmp = from;

	while((tmp = strstr(tmp, sub)) != NULL){
		total++;
		tmp++;
	}

	return total;
}


int getPos(char c){
	return (int) c - (int) 'A';
}




int mdc(int a, int b){
	
	int temp;
	while (a != 0){
		temp = a; 
		a = b%a;  
		b = temp;
	}

	return temp;
}





string toBin(unsigned int n){
	unsigned int i;
	string s = "";
	for (i=1<<31; i>0; i=i/2)
		s += (n & i) ? "1" : "0";

	return s;
}

int decimalToBinary(int n) {
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

int binaryToDecimal(int n){
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}

unsigned long int decimalToX(unsigned long int n, int x){
	unsigned long int resto, i=1, quadral=0;
	while(n!=0){
		resto = n%x;
		n /= x;
		quadral += resto*i;
		i *= 10;
	}
	return quadral;
}



void printsEscanfs(){
	printf("%*llu", size, value); // %(size)(value)
	scanf("%20s", buffer);
	scanf("%[^\n]", buffer);
}


int buscaBinaria(int *vet, int x){
	int ini=0, meio, fim=n-1;
 		
	while(e <= d){

		meio = (ini+fim)/2;

		if (vet[meio] == x) 
			return count;
		else if(v[m] < x) 
			ini = m+1;
		else 
			fim = m-1;
	}

	return -1;
}



// prog dinamica 


int N;	// número de lajotas


int nc[N+1];	// vetor com as respostas dos sub-problemas

// casos bases
nc[N] = 1;
nc[N-1] = 1;

// sub-problemas
for(int K=N-2; K>=0; K--)
     nc[K] = nc[K+1] + nc[K+2];
// o problema principal é resolvido quando K é igual a 0, no laço acima.

resposta = nc[0];	// resposta final



// mochila buscaBinaria

void swapVectors(int *vB, int *vC, int maxSize){
	int i;
	for(i=0; i<=maxSize; ++i)
		vB[i] = vC[i];
}

void swapVectorsPointers(int **vB, int **vC){
	int *temp = *vB;
	*vB = *vC;
	*vC = temp;  
}


int *allocateVector(int m){
	int *vector = (int*) calloc(m, sizeof(int));	// ja faz o memset de 0
	return vector;
}

void vectorFreeAllocation(int *vector){
	free(vector);
}


//complexity: O(n.maxSize)
int binaryKnapsackVector(int **vB, int **vC, int n, int *weight, int *rank, int maxSize){
	
	int x, i, a, b, vi, pi;

	for(x=0; x<n; ++x){
		for(i=0; i<=maxSize; ++i){
			a = (*vB)[i];
			
			vi = rank[x];
			pi = weight[x];

			if(i-pi >= 0){
				b = vi + (*vB)[i-pi];
				if(a < b)
					a = b;
			}

			(*vC)[i] = a;
		}

		swapVectorsPointers(&(*vB), &(*vC));
		//swapVectors(*vB, *vC, maxSize);	
	}


	return (*vB)[maxSize];
}


/* mochila fracionaria

razao = sorted(musicas, key = lambda x : x[3], reverse=True)

somatam, somafav = 0, 0
for i, tam, fav, more in razao:
	if(somatam+tam <= self.__tamMaximo):
		somatam += tam
		somafav += fav

return somafav
*/

```