```cpp
const double INF = 9999999;
typedef pair<int, int> ii;
double matAdj[510][510];




bool isSet(vector<int> &vertices, int v){
	return binary_search(vertices.begin(), vertices.end(), v);
}


int extractMin(vector<int> &vertices, double *chave){
	
	int menor=vertices[0], pos=0;
	for(int i=0; i<vertices.size(); i++){
		if(chave[vertices[i]] < chave[menor]){
			menor = vertices[i];
			pos = i;
		}
	}

	vertices.erase(vertices.begin()+pos); //remove(v[i]);
	return menor;
}


void prim(vector<int> &vertices, int r, double *chave, int *pi){

	int visitados[510];
	int tam = vertices.size();

	for(int i=0; i<tam; i++){
		chave[i] = INF;
		pi[i] = -1;
		visitados[i] = 0;
	}

	chave[r] = 0;

	while(vertices.size() > 0){
		int u = extractMin(vertices, chave);
		visitados[u] = 1;

		for(int v=0; v<tam; v++){
			if(matAdj[u][v] > 0){
				//prim
				if(!visitados[v] && matAdj[u][v] < chave[v]){
					chave[v] = matAdj[u][v];
					pi[v] = u;
				}

				//djikstra
				 if(!visitados[v] && chave[v] > chave[u] + matAdj[u][v]){
					chave[v] = chave[u] + matAdj[u][v];
					pi[v] = u;
				}
			}
		}
	}

}



double chave[510], soma=0;
int pi[510];

prim(vertices, 0, chave, pi);
for(int i=1; i<n; i++)
	soma += matAdj[i][pi[i]];


```