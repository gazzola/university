/*
*
* uma imagem que resume o problema:
* http://s2.postimg.org/bl3dgjit5/shortest_distance.png
*/

#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;


const double EPSILON = 1e-8;

typedef struct dot{

	double x, y;

	dot(){}
	dot(double x, double y){
		this->x = x;
		this->y = y;
	};
	
}dot;


typedef struct rect{

	dot esq, dir;
	rect();
	rect(dot esq, dot dir){
		this->esq = esq;
		this->dir = dir;
	}

}rect;




// distancia euclediana entre dois pontos
double distBetween2Dots(dot p1, dot p2){
	double d1 = p2.x - p1.x;
	double d2 = p2.y - p1.y;
	return sqrt(d1*d1 + d2*d2);
}




void swapRects(rect &a, rect &b){
	rect c = a;
	a = b;
	b = a;
}


double distBetween2Rects(rect a, rect b){


	/*
	
	EM CIMA OU EMBAIXO
	1a:                   1b:

	__________r1          __________r2
	|          |          |          | 
	|          |          |          | 
	q1_________|          q2_________| 
	
					or
	
	__________r2          __________r1
	|          |          |          | 
	|          |          |          | 
	q2_________|          q1_________| 

	
	
 	


    NAS DIAGONAIS
	2a:
	__________r1          __________r2  
	|          |          |          |  
	|          |          |          |  
	q1_________|          q2_________|  
	
				    or
    
    2b:
    __________r1          
	|          |          __________r2  
	|          |          |          |  
	q1_________|          |			 |
						  q2_________| 

	*/

	
	// se o a estiver na direta, mudamos os sentidos
	if(a.esq.x > b.esq.x)
		swapRects(b, a);

	
	// agora o b.esq.x esta a direita do a.esq.x 


	// se tiver b.esq.x estiver a esquerda do a.dir.x
	// entao a distancia eh uma linha vertical
	if(b.esq.x < a.dir.x){
		
		if(b.dir.y < a.esq.y) // caso 1a
			return a.esq.y - b.dir.y;

		if(b.esq.y > a.dir.y) // caso 1b
			return b.esq.y - a.dir.y;

		return 0;
	}


	// caso 2a
	if(b.esq.y > a.dir.y)
		return distBetween2Dots(b.esq, a.dir);

	// caso 2b
	if(b.dir.y < a.esq.y)
		return distBetween2Dots(dot(a.dir.x, a.esq.y), dot(b.esq.x, b.dir.y));


	// senao, ta um no lado do outro
	// nao preciso testar o caso da esquerda,
	// pois ja fiz o swap la em cima
	return b.esq.x - a.dir.x;
}


int main(){
	
	int n, aah, x, y, l;
	int xi, yi, li;
	dot q1, r1, q2, r2;

	scanf("%d %d", &n, &aah);

	bool ok = true;
	scanf("%d %d %d", &xi, &yi, &li);
	n--;

	while(n--){

		scanf("%d %d %d", &x, &y, &l);

		q1 = dot(xi - li/2.0, yi - li/2.0);
		r1 = dot(xi + li/2.0, yi + li/2.0);
		q2 = dot(x - l/2.0, y - l/2.0);
		r2 = dot(x + l/2.0, y + l/2.0);

		double k = distBetween2Rects(rect(q1, r1), rect(q2, r2));
		if(k > aah)
			ok = false;

		xi = x;
		yi = y;
		li = l;
	}


	if(ok)
		printf("YEAH\n");
	else
		printf("OUCH\n");

}
