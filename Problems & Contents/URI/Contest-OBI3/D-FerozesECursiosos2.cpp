#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;



typedef struct dot{

	int x, y, l;

	dot(){}
	dot(int x, int y, int l){
		this->x = x;
		this->y = y;
		this->l = l;
	};
	
}dot;


double distancia(double p1, double p2, double a1, double a2){
	double x = (a1-p1);
	double y = (a2-p2);
	return sqrt(x*x + y*y);
}


int distanciaPlanos(dot p, dot q){

	int a = p.x;
	int b = p.y;
	int x = q.x;
	int y = q.y;

	double l = p.l/2.0;
	double l2 = q.l/2.0;

	double q1[4][2] = {{a-l, b+l}, {a+l, b+l}, {a-l, b-l}, {a+l, b-l}};
	double q2[4][2] = {{x-l2, y+l2}, {x+l2, y+l2}, {x-l2, y-l2}, {x+l2, y-l2}};

	int menor = 9999999;
	int iL, jL, iL2, jL2, igual;
	iL = jL = iL2 = jL2 = igual = 0;

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			double d = distancia(q1[i][0], q1[i][1], q2[j][0], q2[j][1]);
			if(d < menor){
				menor = d;
				iL = i;
				jL = j;
				igual = 0;
			}
			else if(d == menor){
				iL2 = i;
				jL2 = j;
				igual = 1;
			}
		}
	}

	if(igual == 1)
		return menor;
	else{
		double d1, d2, d3;
		d1 = d2 = d3 = 0;

		d1 = menor;
		d2 = distancia(iL, jL2,iL2,jL);
		d3 = distancia(iL2, jL,iL,jL2);

		if(d1 < d2 and d1 < d3)
			return d1;
		if(d2 < d1 and d2 < d3)
			return d2;
		if(d3 < d2 and d3 < d1)
			return d3;
	}

	return 0;
}




int main(){
	
	int n, aah, x, y, l;
	int xi, yi, li;
	dot q1, r1, q2, r2;

	scanf("%d %d", &n, &aah);


	vector<dot> vet;
	while(n--){
		scanf("%d %d %d", &x, &y, &l);
		vet.push_back(dot(x,y,l));
	}


	n = vet.size() - 1;
	bool ok = true;

	for(int i=0; i<n; i++){
		if(distanciaPlanos(vet[i], vet[i+1]) > aah){
			ok = false;
			break;
		}
	}

	if(ok)
		printf("YEAH\n");
	else
		printf("OUCH\n");

}
