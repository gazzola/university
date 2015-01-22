#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 99999999;
const double EPSILON = 1e-9;


typedef struct dot{

	int x, y;

	dot(){}
	dot(int x, int y){
		this->x = x;
		this->y = y;
	};
	
}dot;


typedef struct line{

	double a, b, c;

	line(){}
	line(double a, double b, double c){
		this->a = a;
		this->b = b;
		this->c = c;
	};
	
}line;



dot toVector(dot a, dot b){
	return dot(a.x-b.x, a.y-b.y);
}

int cross(dot a, dot b){
	return a.x*b.y - a.y*b.x;
}

int ccw(dot a, dot b){
	return cross(a, b);
}


double dist(dot a, dot b, dot c){
	double d = (double) hypot(b.x - a.x, b.y - a.y);
	double ds = (double)((c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x)) / d;
	return fabs(ds);
}


int main(){
		
	int n, x, y;
	bool visitados[101][101];
	line l;

	while(scanf("%d", &n) and n > 0){

		memset(visitados, false, n*100*sizeof(visitados[0][0]));

		deque<dot> pontos;
		for(int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			pontos.push_back(dot(x,y));
		}


		// para diminuir a complexidade: gerar lista das combinacoes dos indices
		double minDiff=INF;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i != j and !visitados[i][j]){

					dot pt = toVector(pontos[i], pontos[j]);
					double se=0, sd=0;
					
					//double m = (double)(pontos[j].y-pontos[i].y)/(pontos[j].x-pontos[i].x);
					//l.a = -m;
					//l.b = 1;
					//l.c = m*pontos[i].x - pontos[i].y;

					//printf("%lfx %lfy + %lf = 0\n", l.a, l.b, l.c);

					for(int k=0; k<n; k++){
						if(k != i and k != j){
							if(ccw(pt, toVector(pontos[i], pontos[k])) > 0)
								sd += dist(pontos[i], pontos[j], pontos[k]);
							else if(ccw(pt, toVector(pontos[i], pontos[k])) < 0)
								se += dist(pontos[i], pontos[j], pontos[k]);
						}
					}


					if(se > 0 and sd > 0)
						minDiff = min(minDiff, fabs(sd-se));
				}

				visitados[i][j] = visitados[j][i] = true;
			}
		}

		// caso de teste do pata rachada
		if(minDiff == INF)
			printf("0.000\n");
		else
			printf("%.3lf\n", minDiff);

	}



	return 0;
}