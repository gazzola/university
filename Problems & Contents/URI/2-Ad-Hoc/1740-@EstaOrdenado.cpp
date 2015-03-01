#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


/*
* Arvore RB com informacoes a mais para
* estatisticas dinamicas de ordem.
*
* Complexidade:
* Inserir: 		O(logn)
* Retirar: 		O(logn)
* Atualizar: 	O(logn)
* Vazio:		O(1)
*
* Memoria usada: 
* O(n) para arvore
* O(1) para auxiliar
*
*/


const int MAX = 8;
const int INF = 1000000001;

const char BLACK = 'B';
const char RED = 'R';

template <class T>
class Node{

	public:
		Node *left;
		Node *right;
		Node *parent;
		
		Node *succ;
		Node *pred;

		char color;
		T key;
		T value;
		int size;

		Node(T x, T y){
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->succ = NULL;
			this->pred = NULL;
			this->key = x;
			this->value = y;
			this->color = RED;
			this->size = 0;
		};

		virtual ~Node(){};
};

template <class T>
class OrderStatsTree{

	private:

		int ammount, lastAmmount;
		int h;
		int inversions;

		Node<T> *root;
		Node<T> *NIL;
		
		Node<T> *maximum;
		Node<T> *minimum;

		void destroy_node(Node<T> *&node);
		Node<T> *search_node(Node<T> *&node, T x);
		
		void printInfo(Node<T> *&x);
		void printInOrder_node(Node<T> *&node);
		void printPreOrder_node(Node<T> *&node);
		void printPosOrder_node(Node<T> *&node);
		void printInLevel_node(Node<T> *&node, int level);
		
		void insertInOrder_node(Node<T> *&node, T p, T x);
		void removeInOrder_node(Node<T> *&node, T p);
		void orderInOrder_node(Node<T> *&node, T x, T y);

		int calculeHeight(Node<T> *&node);
		
		void rotateLeft(Node<T> *x);
		void rotateRight(Node<T> *y);
		void insertFixUp(Node<T> *x);

		Node<T> *minNode(Node<T> *z);
		void transplant(Node<T> *u, Node<T> *v);
		void removeFixUp(Node<T> *x);
		

	public:

		OrderStatsTree();
		virtual ~OrderStatsTree();
		void destroy();
		
		void insert(T x, T y);
		void remove(T x);
		void remove(Node<T> *z);
		void update(T x, T val);
		void swap(T x, T y);
		string orders(T x, T y);
		Node<T> *search(T x);

		// news methods
		Node<T> *nthSelect(int i);
		int rank(T x);
		int getInversions();
		
		// helpers
		Node<T> *predecessor(Node<T> *x);
		Node<T> *successor(Node<T> *x);
		Node<T> *getMaximum();
		Node<T> *getMinimum();

		Node<T> *josephusProblem(int n, int m);


		bool empty();
		int height();

		void printInOrder();
		void printPreOrder();
		void printPosOrder();
		void printInLevel();
};


template <class T>
OrderStatsTree<T>::OrderStatsTree(){
	
	this->ammount = 0;
	this->lastAmmount = 0;
	this->h = 0;
	
	this->NIL = new Node<T>(-1, -1);
	this->NIL->color = BLACK;
	this->NIL->left = this->NIL->right = this->NIL->parent = this->NIL;
	this->NIL->succ = this->NIL->pred = this->NIL;

	this->root = this->NIL;
	this->root->color = BLACK;
	this->root->left = this->root->right = this->root->parent = this->NIL;
	this->root->succ = this->root->pred = this->NIL;

	this->maximum = new Node<T>(-INF, -INF);
	this->minimum = new Node<T>(+INF, +INF);
}

template <class T>
OrderStatsTree<T>::~OrderStatsTree(){
	this->destroy();
}


template <class T>
void OrderStatsTree<T>::destroy_node(Node<T> *&node){
	if(node != this->NIL){
		this->destroy_node(node->left);
		this->destroy_node(node->right);
		delete node;
	}
}

template <class T>
void OrderStatsTree<T>::destroy(){
	this->destroy_node(this->root);
}



template <class T>
void OrderStatsTree<T>::rotateLeft(Node<T> *x){
	
	Node<T> *y = x->right;
	x->right = y->left;

	if(y->left != this->NIL)
		y->left->parent = x;

	y->parent = x->parent;

	if(x->parent == this->NIL)
		this->root = y;
	else if(x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
	
	y->size = x->size;
	x->size = x->left->size + x->right->size + 1;
}


template <class T>
void OrderStatsTree<T>::rotateRight(Node<T> *y){
	
	Node<T> *x = y->left;
	y->left = x->right;

	if(x->right != this->NIL)
		x->right->parent = y;

	
	x->parent = y->parent;


	if(y->parent == this->NIL)
		this->root = x;
	else if(y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	x->right = y;
	y->parent = x;

	x->size = y->size;
	y->size = y->left->size + y->right->size + 1;
}


template <class T>
void OrderStatsTree<T>::insertFixUp(Node<T> *z){
	

	Node<T> *y;

	while(z->parent->color == RED){
		if(z->parent == z->parent->parent->left){
			y = z->parent->parent->right;
			if(y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{

				if(z == z->parent->right){
					z = z->parent;
					this->rotateLeft(z);
				}


				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				this->rotateRight(z->parent->parent);
			}
		}
		else{
			y = z->parent->parent->left;
			if(y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				if(z == z->parent->left){
					z = z->parent;
					this->rotateRight(z);
				}

				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				this->rotateLeft(z->parent->parent);
			}
		}
	}

	
	this->root->color = BLACK;
}



template <class T>
void OrderStatsTree<T>::insert(T val, T val2){
	

	Node<T> *z = new Node<T>(val, val2);
	z->succ = this->NIL;
	z->pred = this->NIL;

	// this->insertInOrder_node(this->root, val, val2);

	Node<T> *x = this->root;
	Node<T> *y = this->NIL;

	while(x != this->NIL){
		x->size++;
		y = x;
		if(z->key <= x->key)
			x = x->left;
		else
			x = x->right;
	}


	z->parent = y;
	
	if(y == this->NIL)
		this->root = z;
	else if(z->key <= y->key)
		y->left = z;
	else
		y->right = z;


	z->left = this->NIL;
	z->right = this->NIL;
	z->color = RED;
	z->size = 1;
	
	this->insertFixUp(z);
	this->ammount++;

	// this->inversions += (this->ammount - this->rank(val));

	if(z->value >= this->maximum->value)
		this->maximum = z;
	else if(z->value <= this->minimum->value)
		this->minimum = z;


	z->pred = this->predecessor(z);
	// z->succ = this->successor(z);
	//cout << z->succ->key << endl;
}


template <class T>
void OrderStatsTree<T>::transplant(Node<T> *u, Node<T> *v){
	if(u->parent == this->NIL)
		this->root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

template <class T>
Node<T> *OrderStatsTree<T>::minNode(Node<T> *z){
	Node<T> *x = z;
	while(x->left != this->NIL)
		x = x->left;
	return x;
}

template <class T>
void OrderStatsTree<T>::removeFixUp(Node<T> *x){

	Node<T> *w;

	while(x != this->root and x->color == BLACK){
		if(x == x->parent->left){

			w = x->parent->right;
			if(w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				this->rotateLeft(x->parent);
				w = x->parent->right;
			}

			if(w->left->color == BLACK and w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else{
				if(w->right->color == BLACK){
					w->left->color = BLACK;
					w->color = RED;
					this->rotateRight(w);
					w = x->parent->right;	
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				this->rotateLeft(x->parent);
				x = this->root;
			}
		}
		else{

			w = x->parent->left;
			if(w->color == RED){
				w->color = BLACK;
				x->parent->color = RED;
				this->rotateRight(x->parent);
				w = x->parent->left;
			}

			if(w->right->color == BLACK and w->left->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else{ 
				if(w->left->color == BLACK){
					w->right->color = BLACK;
					w->color = RED;
					this->rotateLeft(w);
					w = x->parent->left;
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				this->rotateRight(x->parent);
				x = this->root;
			}
		}
	}

	x->color = BLACK;
}

template <class T>
void OrderStatsTree<T>::remove(T val){
	
	if(this->ammount < 1)
		return;

	Node<T> *z = this->nthSelect(val);
	if(z == this->NIL)
		return;
	

	Node<T> *aux = z;
	while(aux != this->NIL){
		aux->size--;
		aux = aux->parent;
	}

	Node<T> *x;
	Node<T> *y = z;
	
	char originalColor = y->color;

	if(z->left == this->NIL){
		x = z->right;
		this->transplant(z, z->right);
	}
	else if(z->right == this->NIL){
		x = z->left;
		this->transplant(z, z->left);
	}
	else{
		y = this->minNode(z->right);
		originalColor = y->color;
		x = y->right;
		if(y->parent == z)
			x->parent = y;
		else{
			this->transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		this->transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if(originalColor == BLACK)
		this->removeFixUp(x);

	this->ammount--;

	// z = this->search(val+1);
	// if(z != this->NIL)
	// 	z->key -= 1;
	// this->removeInOrder_node(this->root, val);

}

template <class T>
void OrderStatsTree<T>::remove(Node<T> *z){

	Node<T> *aux = z;
	while(aux != this->NIL){
		aux->size--;
		aux = aux->parent;
	}

	Node<T> *x;
	Node<T> *y = z;
	
	char originalColor = y->color;

	if(z->left == this->NIL){
		x = z->right;
		this->transplant(z, z->right);
	}
	else if(z->right == this->NIL){
		x = z->left;
		this->transplant(z, z->left);
	}
	else{
		y = this->minNode(z->right);
		originalColor = y->color;
		x = y->right;
		if(y->parent == z)
			x->parent = y;
		else{
			this->transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		this->transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	if(originalColor == BLACK)
		this->removeFixUp(x);
}



template <class T>
Node<T> *OrderStatsTree<T>::search_node(Node<T> *&node, T x){
	if(node == this->NIL)
		return this->NIL;
	
	if(node->key == x)
		return node;
	
	if(node->key > x)
		return this->search_node(node->left, x);
	
	return this->search_node(node->right, x);
}

template <class T>
Node<T> *OrderStatsTree<T>::search(T x){
	return this->search_node(this->root, x);
}




template <class T>
void OrderStatsTree<T>::update(T x, T val){
	Node<T> *n1 = this->nthSelect(x);
	n1->value = val;
}


template <class T>
void OrderStatsTree<T>::swap(T x, T y){
	Node<T> *n1 = this->nthSelect(x);
	Node<T> *n2 = this->nthSelect(y);
	T temp;
	temp = n1->value;
	n1->value = n2->value;
	n2->value = temp;
}





template <class T>
string OrderStatsTree<T>::orders(T x, T y){


	T i = y;
	T n = x;

	Node<T> *current;
	Node<T> *aux = this->nthSelect(i);
	
	T last = aux->value;
	

	bool eq, inc, dec;
	eq = inc = dec = true;

	current = aux->pred;

	for(i=i-1; i>=n; i--){

		// cout << last << " ";

		if(last != current->value)
			eq = false;
		
		if(last > current->value)
			dec = false;
		
		if(last < current->value)
			inc = false;

		if(!eq and !inc and !dec)
			break;

		last = current->value;
		current = current->pred;
	}

	// cout << last << " ";


	if(eq)
		return "ALL EQUAL";

	if(inc)
		return "NON DECREASING";

	if(dec)
		return "NON INCREASING";

	return "NONE";
}




template <class T>
void OrderStatsTree<T>::insertInOrder_node(Node<T> *&node, T p, T x){
	if(node != this->NIL){
		if(node->left->key >= p)
			this->insertInOrder_node(node->left, p, x);
		
		if(node->key >= p and node->value != x)
			node->key += 1;

		if(node->right->key >= p)
			this->insertInOrder_node(node->right, p, x);
	}
}


template <class T>
void OrderStatsTree<T>::removeInOrder_node(Node<T> *&node, T p){
	if(node != this->NIL){

		if(node->left->key > p)
			this->removeInOrder_node(node->left, p);
		
		if(node->key > p){
			node->key -= 1;
			// cout << node->key << ":" << node->value << "   ";
		}

		if(node->right->key > p)
			this->removeInOrder_node(node->right, p);
	}
}





template <class T>
Node<T> *OrderStatsTree<T>::nthSelect(int i){
	
	Node<T> *aux = this->root;
	int r;

	while(aux != this->NIL){
		r = aux->left->size+1;	
		if(i == r)
			break;
		else if(i < r)
			aux = aux->left;
		else {
			aux = aux->right;
			i = i-r;
		}
	}

	return aux;
}


template <class T>
int OrderStatsTree<T>::rank(T val){
	
	Node<T> *x = this->search(val);
	if(x == this->NIL)
		return -1;

	int r = x->left->size+1;
	Node<T> *y = x;

	while(y != this->root){
		if(y == y->parent->right)
			r += y->parent->left->size+1;
		y = y->parent;
	}
	
	return r;
}



template <class T>
int OrderStatsTree<T>::getInversions(){
	return this->inversions;
}

// para ficar em O(1), precisamos manter um ponteiro
// para o sucessor na estrutura do nodo
template <class T>
Node<T> *OrderStatsTree<T>::predecessor(Node<T> *x){
	
	
	if(x->left != this->NIL){
		Node<T> *aux = x->left;
		while(aux->right != this->NIL)
			aux = aux->right;
		return aux;
	}
	
	Node<T> *aux = x;
	Node<T> *y = aux->parent;
	while(y != this->NIL and aux == y->left){
		aux = y;
		y = y->parent;
	}
	
	return y;
}

// para ficar em O(1), precisamos manter um ponteiro
// para o sucessor na estrutura do nodo
template <class T>
Node<T> *OrderStatsTree<T>::successor(Node<T> *x){

	
	if(x->right != this->NIL){
		Node<T> *aux = x->right;
		while(aux->left != this->NIL)
			aux = aux->left;
		return aux;
	}
	
	Node<T> *aux = x;
	Node<T> *y = x->parent;
	while(y != this->NIL and aux == y->right){
		aux = y;
		y = y->parent;
	}
	
	return y;
}

template <class T>
Node<T> *OrderStatsTree<T>::getMaximum(){
	return this->maximum;
}

template <class T>
Node<T> *OrderStatsTree<T>::getMinimum(){
	return this->minimum;
}


template <class T>
Node<T> *OrderStatsTree<T>::josephusProblem(int n, int m){
	
	for(int i=1; i<=n; i++)
		this->insert(i);

	int j = 1;
	Node<T> *x;

	for(int k=n; k>1; k--){
		j = ((j+m-2)%k)+1;
		x = this->nthSelect(j);
		cout << x->key << " ";
		this->remove(x);
	}

	return this->root;
}




template <class T>
bool OrderStatsTree<T>::empty(){
	return (this->root == this->NIL);
}

template <class T>
int OrderStatsTree<T>::height(){
	
	if(this->lastAmmount == this->ammount)
		return this->h;

	this->h = this->calculeHeight(this->root);
	this->lastAmmount = this->ammount;
	return this->h;
}


template <class T>
int OrderStatsTree<T>::calculeHeight(Node<T> *&node){
	if(node == this->NIL)
		return 0;

	int l_h = this->calculeHeight(node->left);
	int r_h = this->calculeHeight(node->right);

	if(l_h > r_h)
		return l_h+1;

	return r_h+1;
}





template <class T>
void OrderStatsTree<T>::printInfo(Node<T> *&x){
	cout << x->key << ":" << x->value << "   ";
	cout << x->pred->key << "-" << x->succ->key << endl;
}

template <class T>
void OrderStatsTree<T>::printInOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printInOrder_node(node->left);
		this->printInfo(node);
		this->printInOrder_node(node->right);
	}
}

template <class T>
void OrderStatsTree<T>::printInOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void OrderStatsTree<T>::printPreOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printInfo(node);
		this->printPreOrder_node(node->left);
		this->printPreOrder_node(node->right);
	}
}

template <class T>
void OrderStatsTree<T>::printPreOrder(){
	this->printPreOrder_node(this->root);
}



template <class T>
void OrderStatsTree<T>::printPosOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printPosOrder_node(node->left);
		this->printPosOrder_node(node->right);
		this->printInfo(node);
	}
}

template <class T>
void OrderStatsTree<T>::printPosOrder(){
	this->printPosOrder_node(this->root);
}



template <class T>
void OrderStatsTree<T>::printInLevel(){
	int h = this->height();
	for(int i=1; i<=h; i++)
		this->printInLevel_node(this->root, i);
}


template <class T>
void OrderStatsTree<T>::printInLevel_node(Node<T> *&node, int level){
	if(node == this->NIL)
		return;
	
	if(level == 1)
		this->printInfo(node);
	else if(level > 1){
		this->printInLevel_node(node->left, level-1);
		this->printInLevel_node(node->right, level-1);
	}
}



int main(){

	int n, d, x, y, q;

	while(scanf("%d", &n) != EOF){

		OrderStatsTree<int> *bt = new OrderStatsTree<int>();

		for(int i=1; i<=n; i++){
			scanf("%d", &x);
			bt->insert(i, x);
		}

		scanf("%d", &q);
		while(q--){

			scanf("%d", &d);
			if(d == 0){
				scanf("%d %d", &x, &y);
				bt->swap(x, y);
			}
			else if(d == 1){
				scanf("%d %d", &x, &y);
				bt->update(x, y);
			}
			else if(d == 2){
				scanf("%d %d", &x, &y);
				bt->insert(x, y);
			}
			else if(d == 3){
				scanf("%d", &x);
				bt->remove(x);
			}
			else if(d == 4){
				scanf("%d %d", &x, &y);
				cout << bt->orders(x, y) << endl;
			}

			// bt->printInOrder();
			// cout << endl;
		}


		delete bt;
	}


	return 0;
}

/*

15 6 6 48 56 24 2 11
15 6 6 6 48 56 24 2 11
15 6 13 6 48 56 24 2 11
15 6 6 48 56 24 2 11


*/