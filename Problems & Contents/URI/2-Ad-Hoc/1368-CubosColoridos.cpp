#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
 
struct cubo{
	int lados[6];
		
	bool operator<(const cubo &c) const{
		return (memcmp(lados, c.lados, sizeof(lados)) < 0);
	}
};
 
 
cubo c;
set<cubo> cubos;
 
 
void rotaciona_horizontal(){
	int temp = c.lados[0];
	c.lados[0] = c.lados[1];
	c.lados[1] = c.lados[5];
	c.lados[5] = c.lados[3];
	c.lados[3] = temp;
}
 
 
void rotaciona_vertical(){
	int temp = c.lados[1];
	c.lados[1] = c.lados[2];
	c.lados[2] = c.lados[3];
	c.lados[3] = c.lados[4];
	c.lados[4] = temp;
}
 
 
void rotaciona_eixo(){
	int temp = c.lados[0];
	c.lados[0] = c.lados[2];
	c.lados[2] = c.lados[5];
	c.lados[5] = c.lados[4];
	c.lados[4] = temp;
}



//primeiro rotaciona verticalmente e o eixo e verifica
//se ja esta no conjunto.
//depois rotaciona horizontalmente.
bool tem_rotacao(){
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			rotaciona_vertical();
			for(int z = 0; z < 4; z++){
				rotaciona_eixo();
				if(cubos.count(c))
					return true;
			}
		}
		rotaciona_horizontal();
	}
	return false;
}
 
 
int main(){
	
	int n;
	while(true){

		scanf("%d", &n);
		if(n == 0)
			break;

		int count = 0;
		for(int i=0; i<n; i++){
			for(int i=0; i<6; i++)
				scanf("%d", &c.lados[i]);

			if(!tem_rotacao()){
				count++;
				cubos.insert(c);
			}
		}

		printf("%d\n", count);
		cubos.clear();
	}

	return 0;
}