#include <cstdio>
#include <cstring>

using namespace std;
typedef long long unsigned int llu;

int MOD;

struct Matrix{
    long long X[2][2];
    
    Matrix(){}
    
    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i < 2;++i) X[i][i] = 1;
    }
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    memset(m.X,0,sizeof(m.X));

    for(int i = 0;i < 2;++i)
        for(int j = 0;j < 2;++j)
            for(int k = 0;k < 2;++k)
                m.X[i][k] = (m.X[i][k] + m1.X[i][j] * m2.X[j][k]) % MOD;
}

Matrix pow(Matrix &M0, llu n){
	Matrix ret;
	ret.init();

	if(n == 0) return ret;
	if(n == 1) return M0;

	Matrix P = M0;

	while(n != 0){
	    if(n & 1){
	        aux = ret;
	        mult(ret,aux,P);
	    }

	    n >>= 1;

	    aux = P;
	    mult(P,aux,aux);
	}

    return ret;
}

int pisano(int m){

	if(m <= 1)
		return 1;
	
	int a, b, temp, i, last;
	a = b = 1;
	i = last = 0;

	while(true){
		temp = a;	
		a = b;
		b = (temp+b)%m;

		if(b==last && last==1)
			break;

		last = b;
		i++;
	}

	return i+1;
}

int main(){
    Matrix M0;
    M0.X[0][0] = M0.X[0][1] = M0.X[1][0] = 1;
    M0.X[1][1] = 0;
    
    int n, m, c;
    llu res1, res2;

    while(scanf("%d %d",&n,&m) != EOF){
        
        
        c = pisano(m);
        MOD = c;
        res1 = pow(M0,n).X[0][1];

        MOD = m;
        res2 = pow(M0,res1).X[0][1];

        printf("%lld\n", res2);
    }
    
    return 0;
}