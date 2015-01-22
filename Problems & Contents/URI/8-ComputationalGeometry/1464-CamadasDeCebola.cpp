#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <algorithm>

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

	bool operator<(const dot &c) const{
		return this->y < c.y;
	};

	bool operator==(const dot &c) const{
		return this->x == c.x and this->y == c.y;
	};
	
}dot;


dot pivo;


void printVector(const deque<dot> &vet, int n){
	for(int i=0; i<n; i++)
		printf("%d,%d  ", vet[i].x, vet[i].y);
	printf("\n");
}




dot toVector(dot a, dot b){
	return dot(a.x-b.x, a.y-b.y);
}

int cross(dot a, dot b){
	return a.x*b.y - a.y*b.x;
}


int ccw(dot a, dot b, dot c){
	int t = cross(toVector(a, b), toVector(a, c));
	if(t > 0)
		return 1;
	else if(t < 0)
		return -1;
	return 0;
}

bool colinear(dot a, dot b, dot c){
	return cross(toVector(a, b), toVector(a, c)) == 0;
}


// menor em y e maior em x
bool myLess(dot &a, dot &b){
	if(a.y < b.y)
		return true;
	else if(a.y > b.y)
		return false;

	return a.x > b.x;
}


// hypot
int dist(dot a, dot b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}


template <class T>
bool orderBy(const dot &a, const dot &b){

	if(ccw(pivo, a, b) == 0){
		if(pivo.y == a.y and pivo.y == b.y)
			return a.x < b.x;
		return dist(pivo, a) < dist(pivo, b);
	}

	dot d1 = toVector(pivo, a);
	dot d2 = toVector(pivo, b);
	return atan2(d1.y, d1.x)-atan2(d2.y, d2.x) < 0;
}


int main(){
		
	int n, x, y;
	
	dot temp;

	while(scanf("%d", &n) and n > 0){

		deque<dot> pontos;
		for(int i=0; i<n; i++){
			scanf("%d %d", &x, &y);
			pontos.push_back(dot(x,y));
		}


		int camadas = 0;
		while(pontos.size() >= 3){

			int N = pontos.size();

			int j = 0;
			for(int i=1; i<N; i++)
				if(myLess(pontos[i], pontos[j]))
					j = i;
			
			//swap
			temp = pontos[j];
			pontos[j] = pontos[0];
			pontos[0] = temp;
			pivo = pontos[0];


			// sort in clock-wise angle
			pontos.pop_front();
			sort(pontos.begin(), pontos.begin()+(N-1), orderBy<int>);
			pontos.push_front(pivo);

			//printVector(pontos, pontos.size());
			

			
			// scan
			deque<dot> s;
			s.push_back(pontos[N-1]);
			s.push_back(pontos[0]);
			s.push_back(pontos[1]);


			int i = 2;
			while(i < N){
				j = s.size();
				if(ccw(s[j-2], s[j-1], pontos[i]) != -1){
					s.push_back(pontos[i]);
					++i;
				}
				else
					s.pop_back();
			}


			// printVector(s, s.size());


			// tira os pontos que estao no perimetro
			int l = 0;
			for(int k=1; k<(int) s.size(); k++){
				while(l < (int) pontos.size()){
					if(s[k] == pontos[l]){
						pontos.erase(pontos.begin()+l);
						break;
					}
					l++;
				}
			}

			camadas++;
		}


		// printf("qtd de camadas: %d\n", camadas);
		if(camadas % 2 == 1)
			printf("Take this onion to the lab!\n");
		else
			printf("Do not take this onion to the lab!\n");
	}



	return 0;
}