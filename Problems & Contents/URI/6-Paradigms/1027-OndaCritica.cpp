#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;


double distancia(ii p1, ii p2){
	double x = p2.first-p1.first;
	double y = p2.second-p1.second;
	return sqrt((x*x) + (y*y));
}


bool orderBy(const ii &i, const ii &j){
	return (i.first < j.first and i.second < j.second);
}


void printVector(const vector<ii> &v){
	for(int i=0; i<(int) v.size(); i++)
		printf("(%d,%d)  ", v[i].first, v[i].second);
 	printf("\n");
}


void printMap(const map<int, int> &m){
	map<int, int> :: const_iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
		printf("%d ", iter->first);
	printf("\n");
}

void printSet(map<int, set<int> > &grafico, int a){
	set<int>::iterator its;
	printf("%2d: ", a);
	for(its = grafico[a].begin(); its != grafico[a].end(); ++its)
		printf("%d ", *its);
	printf("\n");
}

void printMapSet(map<int, int> &m, map<int, set<int> > &grafico, int min, int max){
	
	map<int, int> :: iterator iter;
	printSet(grafico, min);

	for (iter = m.begin(); iter != m.end(); ++iter){
		int a = iter->first;
		printSet(grafico, a);
	}
	
	printSet(grafico, max);
		
	printf("\n");
}


int calcular(map<int, int> &ipsolons, map<int, set<int> > &grafico){
	
	map<int, int>::const_iterator itm;
	set<int> set1, set2;
	set<int>::iterator its1, its2;

	int maior = 1;
	for(itm = ipsolons.begin(); itm != ipsolons.end(); itm++){
		int a = itm->first;

		int count = 1;
		set1 = grafico[a+1];
		set2 = grafico[a-1];
		int tam = set1.size()+set2.size();

		if(tam > maior){

			its1 = set1.begin();
			its2 = set2.begin();
			bool flag, cima, baixo;

			//printf("%d:%d - %d:%d\n", a+1, *its1, a-1, *its2);

			if(*its1 < *its2){	// comeca pelo a+1

				//printf("%d:%d - %d:%d\n", a+1, *its1, a-1, *its2);

				flag = true; //vai descer
				cima = baixo = false;

				while(true){

					if(!flag){

						if(cima == true and baixo == false)
							break;

						cima = false;

						for(; its1!=set1.end(); ++its1){
							if(*its1 > *its2){
								count++;
								cima = true;
								break;
							}
						}

						int dist = distance(its2, set2.end());
						if(dist == 0)
							break;
					}
					else{

						if(cima == false and baixo == true)
							break;

						baixo = false;

						for(; its2!=set2.end(); ++its2){
							if(*its2 > *its1){
								count++;
								baixo = true;
								break;
							}
						}

						int dist = distance(its1, set1.end());
						if(dist == 0)
							break;
					}

					flag = !flag;

				}

			}
			else if(*its1 > *its2){	// comeca pelo a-1
				flag = false; //vai descer
				cima = baixo = false;

				while(true){

					if(!flag){

						if(cima == true and baixo == false)
							break;

						cima = false;
						for(; its1!=set1.end(); ++its1){
							if(*its1 > *its2){
								count++;
								cima = true;
								break;
							}
						}

						int dist = distance(its2, set2.end());
						if(dist == 0)
							break;
					}
					else{

						if(cima == false and baixo == true)
							break;

						baixo = false;
						for(; its2!=set2.end(); ++its2){
							if(*its2 > *its1){
								count++;
								baixo = true;
								break;
							}
						}

						int dist = distance(its1, set1.end());
						if(dist == 0)
							break;

					}

					flag = !flag;
				}
			}
			else{	// testar os dois casos e ve qual foi o maior
				
				int count1=1, count2=1;
				

				//a+1

				flag = true; //vai descer
				cima = baixo = false;

				while(true){

					if(!flag){

						if(cima == true and baixo == false)
							break;

						cima = false;

						for(; its1!=set1.end(); ++its1){
							if(*its1 > *its2){
								count1++;
								cima = true;
								break;
							}
						}

						int dist = distance(its2, set2.end());
						if(dist == 1)
							break;
					}
					else{

						if(cima == false and baixo == true)
							break;

						baixo = false;

						for(; its2!=set2.end(); ++its2){
							if(*its2 > *its1){
								count1++;
								baixo = true;
								break;
							}
						}

						int dist = distance(its1, set1.end());
						if(dist == 0)
							break;
					}

					flag = !flag;

				}



				//a-1
				flag = false; //vai descer
				cima = baixo = false;

				while(true){

					if(!flag){

						if(cima == true and baixo == false)
							break;

						cima = false;
						for(; its1!=set1.end(); ++its1){
							if(*its1 > *its2){
								count2++;
								cima = true;
								break;
							}
						}

						int dist = distance(its2, set2.end());
						if(dist == 1)
							break;
					}
					else{

						if(cima == false and baixo == true)
							break;

						baixo = false;
						for(; its2!=set2.end(); ++its2){
							if(*its2 > *its1){
								count2++;
								baixo = true;
								break;
							}
						}

						int dist = distance(its1, set1.end());
						if(dist == 0)
							break;

					}

					flag = !flag;

				}

				count = max(count1, count2);
			}

			if(count > maior)
				maior = count;
		}
	}

	return maior;
}


int main(){

	int n, x, y;

	while(scanf("%d", &n) != EOF){

		vector<ii> pontos;

		map<int, int> ipsolons;
		map<int, set<int> > grafico;	//y -> x

		


		scanf("%d %d", &x, &y);
		pontos.push_back(ii(x, y));
		grafico[y].insert(x);
		//ipsolons[y] = y;
		n--;
		
		int min=y, max=y;

		while(n--){
			scanf("%d %d", &x, &y);
			pontos.push_back(ii(x, y));

			if(y < min)
				min = y;
			if(y > max)
				max = y;

			grafico[y].insert(x);
			//ipsolons[y] = y;
		}


		//ipsolons.erase(min);
		//ipsolons.erase(max);
		for(int i=min+1; i<max; i++)
			ipsolons[i] = i;

		//printMapSet(ipsolons, grafico, min, max);
		//printMap(ipsolons);
		//sort(pontos.begin(), pontos.end(), orderBy);
		//printVector(pontos);

		int total = calcular(ipsolons, grafico);
		printf("%d\n", total);
	}


	return 0;
}