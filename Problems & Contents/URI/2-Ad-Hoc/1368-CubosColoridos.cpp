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


void rotHorizontal(cubo &c){
	int temp = c.lados[0];
	c.lados[0] = c.lados[1];
	c.lados[1] = c.lados[5];
	c.lados[5] = c.lados[3];
	c.lados[3] = temp;
}
 
 
void rotVertical(cubo &c){
	int temp = c.lados[1];
	c.lados[1] = c.lados[2];
	c.lados[2] = c.lados[3];
	c.lados[3] = c.lados[4];
	c.lados[4] = temp;
}
 
 
void rotEixo(cubo &c){
	int temp = c.lados[0];
	c.lados[0] = c.lados[2];
	c.lados[2] = c.lados[5];
	c.lados[5] = c.lados[4];
	c.lados[4] = temp;
}


bool temRotDisponivel(set<cubo> &cubos, cubo &c){

	for(int x=0; x<4; x++){
		for(int y=0; y<4; y++){
			rotVertical(c);
			for(int z=0; z<4; z++){
				rotEixo(c);
				if(cubos.count(c))
					return false;
			}
		}
		rotHorizontal(c);
	}

	return true;
}
 
 
int main(){
	
	int n;
	cubo c;
	set<cubo> cubos;

	while(true){

		scanf("%d", &n);
		if(n == 0)
			break;

		int num = 0;
		for(int i=0; i<n; i++){
			for(int i=0; i<6; i++)
				scanf("%d", &c.lados[i]);

			if(temRotDisponivel(cubos, c)){
				cubos.insert(c);
				num++;
			}
		}


		printf("%d\n", num);
		cubos.clear();
	}

	return 0;
}