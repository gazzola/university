```cpp
typedef struct _times{
	int pontos;
	int vitorias;
	int aparicao;
	int gols;
	char nome[22];
}times;


static int count = 0;

bool ordenarPorPontos(const times &i, const times &j){
	
	::count++;

	if(i.pontos > j.pontos)
		return true;
	else if(i.pontos < j.pontos)
		return false;
	
	if(i.vitorias > j.vitorias)
		return true;
	else if(i.vitorias < j.vitorias)
		return false;

	if(i.gols > j.gols)
		return true;
	else if(i.gols < j.gols)
		return false;

	return (i.aparicao < j.aparicao);

}

struct char_cmp{ 
	bool operator ()(const char *a,const char *b) const{
		return strcmp(a,b)<0;
	} 
};


map<char*, int, char_cmp> posicaoPartidas;
vector<times> partidas;


//sort(partidas.begin(), partidas.end(), ordenarPorPontos);



map <int, int> mapa;
map <int, int> :: const_iterator iter;

for(iter = mapa.begin(); iter != mapa.end(); iter++)
	cout << " " << iter->second << "-" << iter->first;


// range heap example
#include <iostream>     // cout
#include <algorithm>    // make_heap, pop_heap, push_heap, sort_heap
#include <vector>       // vector

int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  make_heap(v.begin(), v.end());
  cout << "initial max heap   : " << v.front() << '\n';

  pop_heap(v.begin(), v.end()); //, greater<int>()
  v.pop_back();
  cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); 
  push_heap(v.begin(),v.end());
  
  cout << "max heap after push: " << v.front() << '\n';

  sort_heap(v.begin(),v.end());

  cout << "final sorted range :";
  for(unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];

  cout << '\n';

  return 0;
}
```