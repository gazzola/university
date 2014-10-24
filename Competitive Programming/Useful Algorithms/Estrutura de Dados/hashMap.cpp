/*
* Complexidade:
* Inserir: 		O(1)
* Retirar: 		O(1)
* Atualizar: 	O(1) // nao original
* Vazio:		O(1)
*
* Memoria usada: 
* O(n) para vetor
* O(1) para auxiliar
*
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;

template <class K, class V>
class HashNode{		

	public:

		K key; 
		V value;

		HashNode(K key, V value){
			this->key = key;
			this->value = value;
		};

		virtual ~HashNode(){};
};



template <class K, class V>
class HashMap{
	
	private:
		const static int MAP_SIZE = 10; // 2^14
		int tam;
		vector< deque< HashNode<K,V> > > map;

	public:

		HashMap(){
			this->map.resize(MAP_SIZE);
			this->tam = MAP_SIZE;
		};

		HashMap(int size){
			this->map.resize(size);
			this->tam = size;
		};

		virtual ~HashMap(){
			for(int i=0; i<(int) this->map.size(); i++)
				this->map[i].clear();
			this->map.clear();
		};

		int hashFunction(K key){
			return key % this->tam;
		};

		void insert(K key, V value){
			int pos = this->hashFunction(key);
			HashNode<K, V> *x = new HashNode<K, V>(key, value);
			this->map[pos].push_front(*x);
		};

		void remove(K key){

			int pos = this->hashFunction(key);
			if(this->map[pos].size() > 0){

				int i;
				for(i=0; i<(int) this->map[pos].size(); i++)
					if(this->map[pos][i].key == key)
						break;

				this->map[pos].erase(this->map[pos].begin()+i);
			}
		};

		bool search(K key){
			
			int pos = this->hashFunction(key);
			if(this->map[pos].size() > 0){
				for(int i=0; i<(int) this->map[pos].size(); i++)
					if(this->map[pos][i].key == key)
						return true;
			}

			return false;
		};
};



int main(){

	HashMap<int, string> h1;
	bool res;

	h1.insert(1, "val1");
	h1.insert(2, "val2");
	h1.insert(3, "val3");

	string value = "val1";

	h1.search(2);
	cout << value << endl;


	res = h1.search(3);
	if(res)
		cout << value << endl;

	h1.remove(3);
	res = h1.search(3);
	if(res)
		cout << value << endl;

	return 0;
}