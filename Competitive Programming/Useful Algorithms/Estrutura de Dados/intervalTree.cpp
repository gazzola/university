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

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;
const int INF = 999999;

const char BLACK = 'B';
const char RED = 'R';

template <class T>
class Node{

	public:
		Node *left;
		Node *right;
		Node *parent;
		char color;
		pair<T, T> key; // key.first = under interval | key.second = upper interval
		int size;
		int max;

		Node(T i, T j){
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->key = make_pair(i, j);
			this->color = RED;
			this->size = 0;
			this->max = j;
		};

		virtual ~Node(){};
};

template <class T>
class IntervalTree{

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
		
		int calculeHeight(Node<T> *&node);
		
		void rotateLeft(Node<T> *x);
		void rotateRight(Node<T> *y);
		void insertFixUp(Node<T> *x);

		Node<T> *minNode(Node<T> *z);
		void transplant(Node<T> *u, Node<T> *v);
		void removeFixUp(Node<T> *x);
		

	public:

		IntervalTree();
		virtual ~IntervalTree();
		void destroy();
		
		void insert(T i, T j);
		void remove(T x);	// not implemented
		Node<T> *searchElement(T x);
		Node<T> *search(T i, T j);

		// news methods
		Node<T> *nthSelect(int i);
		int rank(T x);
		int getInversions();
		
		// helpers
		Node<T> *predecessor(Node<T> *x);
		Node<T> *successor(Node<T> *x);
		Node<T> *getMaximum();
		Node<T> *getMinimum();

		bool overlap(T i1, T j1, T i2, T j2);
		bool empty();
		int height();

		void printInOrder();
		void printPreOrder();
		void printPosOrder();
		void printInLevel();
};


template <class T>
IntervalTree<T>::IntervalTree(){
	
	this->ammount = 0;
	this->lastAmmount = 0;
	this->h = 0;
	
	this->NIL = new Node<T>(-1, 0);
	this->NIL->color = BLACK;
	this->NIL->left = this->NIL->right = this->NIL->parent = this->NIL;
	

	this->root = this->NIL;
	this->root->color = BLACK;
	this->root->left = this->root->right = this->root->parent = this->NIL;


	this->maximum = new Node<T>(-INF, 0);
	this->minimum = new Node<T>(+INF, 0);
}

template <class T>
IntervalTree<T>::~IntervalTree(){
	this->destroy();
}


template <class T>
void IntervalTree<T>::destroy_node(Node<T> *&node){
	if(node != this->NIL){
		this->destroy_node(node->left);
		this->destroy_node(node->right);
		delete node;
	}
}

template <class T>
void IntervalTree<T>::destroy(){
	this->destroy_node(this->root);
}



template <class T>
void IntervalTree<T>::rotateLeft(Node<T> *x){
	
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

	x->max = max(x->left->max, x->right->max);
	x->max = max(x->key.second, x->max);
	y->max = max(y->left->max, y->right->max);
	y->max = max(y->key.second, y->max);
}


template <class T>
void IntervalTree<T>::rotateRight(Node<T> *y){
	
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

	y->max = max(y->left->max, y->right->max);
	y->max = max(y->key.second, y->max);
	x->max = max(x->left->max, x->right->max);
	x->max = max(x->key.second, x->max);
}


template <class T>
void IntervalTree<T>::insertFixUp(Node<T> *z){
	

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
void IntervalTree<T>::insert(T i, T j){
	
	Node<T> *z = new Node<T>(i, j);
	Node<T> *x = this->root;
	Node<T> *y = this->NIL;

	while(x != this->NIL){
		x->size++;
		y = x;
		if(z->key.first < x->key.first)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	
	if(y == this->NIL)
		this->root = z;
	else if(z->key.first < y->key.first)
		y->left = z;
	else
		y->right = z;


	z->left = this->NIL;
	z->right = this->NIL;
	z->color = RED;
	z->size = 1;
	
	this->insertFixUp(z);
	this->ammount++;

	this->inversions += (this->ammount - this->rank(i));

	if(z->key.first >= this->maximum->key.first)
		this->maximum = z;
	else if(z->key.first <= this->minimum->key.first)
		this->minimum = z;

	Node<T> *aux = z;
	while(aux != this->NIL){
		aux->max = max(aux->left->max, aux->right->max);
		aux->max = max(aux->key.second, aux->max);
		aux = aux->parent;
	}
}


template <class T>
void IntervalTree<T>::transplant(Node<T> *u, Node<T> *v){
	if(u->parent == this->NIL)
		this->root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

template <class T>
Node<T> *IntervalTree<T>::minNode(Node<T> *z){
	Node<T> *x = z;
	while(x->left != this->NIL)
		x = x->left;
	return x;
}

template <class T>
void IntervalTree<T>::removeFixUp(Node<T> *x){

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
void IntervalTree<T>::remove(T val){
	
	Node<T> *z = this->searchElement(val);

	Node<T> *aux = z;
	T temp;

	while(aux != this->NIL){
		aux->size--;
		temp = max(aux->left->max, aux->right->max);
		aux = aux->parent;
		aux->max = max(aux->max, temp);
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
Node<T> *IntervalTree<T>::search_node(Node<T> *&node, T x){
	if(node == this->NIL)
		return this->NIL;
	
	if(node->key.first == x)
		return node;
	
	if(node->key.first > x)
		return this->search_node(node->left, x);
	
	return this->search_node(node->right, x);
}

template <class T>
Node<T> *IntervalTree<T>::searchElement(T x){
	return this->search_node(this->root, x);
}


template <class T>
Node<T> *IntervalTree<T>::nthSelect(int i){
	
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
int IntervalTree<T>::rank(T val){
	
	Node<T> *x = this->searchElement(val);
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
int IntervalTree<T>::getInversions(){
	return this->inversions;
}

// para ficar em O(1), precisamos manter um ponteiro
// para o sucessor na estrutura do nodo
template <class T>
Node<T> *IntervalTree<T>::predecessor(Node<T> *x){
	if(x->left == this->NIL)
		return x;

	Node<T> *aux = x->left;
	while(aux->right != this->NIL)
		aux = aux->right;

	return aux;
}

// para ficar em O(1), precisamos manter um ponteiro
// para o sucessor na estrutura do nodo
template <class T>
Node<T> *IntervalTree<T>::successor(Node<T> *x){
	if(x->right == this->NIL)
		return x;

	Node<T> *aux = x->right;
	while(aux->left != this->NIL)
		aux = aux->left;

	return aux;
}

template <class T>
Node<T> *IntervalTree<T>::getMaximum(){
	return this->maximum;
}

template <class T>
Node<T> *IntervalTree<T>::getMinimum(){
	return this->minimum;
}




template <class T>
bool IntervalTree<T>::overlap(T i1, T j1, T i2, T j2){
	// para intervalos abertos, usar apenas < (menor)
	return (i1 <= j2 && i2 <= j1);
}


template <class T>
Node<T> *IntervalTree<T>::search(T i, T j){
	Node<T> *x = this->root;

	while(x != this->NIL and !this->overlap(i, j, x->key.first, x->key.second)){
		// intervalo aberto usar apenas > (maior)
		if(x->left != this->NIL and x->left->max >= i)
			x = x->left;
		else
			x = x->right;
	}

	return x;
}



template <class T>
bool IntervalTree<T>::empty(){
	return (this->root == this->NIL);
}

template <class T>
int IntervalTree<T>::height(){
	
	if(this->lastAmmount == this->ammount)
		return this->h;

	this->h = this->calculeHeight(this->root);
	this->lastAmmount = this->ammount;
	return this->h;
}


template <class T>
int IntervalTree<T>::calculeHeight(Node<T> *&node){
	if(node == this->NIL)
		return 0;

	int l_h = this->calculeHeight(node->left);
	int r_h = this->calculeHeight(node->right);

	if(l_h > r_h)
		return l_h+1;

	return r_h+1;
}





template <class T>
void IntervalTree<T>::printInfo(Node<T> *&x){
	cout << "  key=";
	cout << x->key.first << "," << x->key.second << "|" << x->max;

	cout << " \t l->key=";
	if( x->left == this->NIL) 
		cout << "N";
	else 
		cout << x->left->key.first;

	cout << "  r->key=";
	if( x->right == this->NIL) 
		cout << "N";
	else 
		cout << x->right->key.first;

	cout << "  p->key=";
	if( x->parent == this->NIL) 
		cout << "N";
	else 
		cout << x->parent->key.first;

	cout << "  color=" << x->color;
	cout << "  size=" << x->size << endl;
}

template <class T>
void IntervalTree<T>::printInOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printInOrder_node(node->left);
		this->printInfo(node);
		this->printInOrder_node(node->right);
	}
}

template <class T>
void IntervalTree<T>::printInOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void IntervalTree<T>::printPreOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printInfo(node);
		this->printPreOrder_node(node->left);
		this->printPreOrder_node(node->right);
	}
}

template <class T>
void IntervalTree<T>::printPreOrder(){
	this->printPreOrder_node(this->root);
}



template <class T>
void IntervalTree<T>::printPosOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printPosOrder_node(node->left);
		this->printPosOrder_node(node->right);
		this->printInfo(node);
	}
}

template <class T>
void IntervalTree<T>::printPosOrder(){
	this->printPosOrder_node(this->root);
}



template <class T>
void IntervalTree<T>::printInLevel(){
	int h = this->height();
	for(int i=1; i<=h; i++)
		this->printInLevel_node(this->root, i);
}


template <class T>
void IntervalTree<T>::printInLevel_node(Node<T> *&node, int level){
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

	srand(time(NULL));
	IntervalTree<int> *bt = new IntervalTree<int>();

	int x, y;
	int vet[10] = {16, 8, 25, 5, 15, 17, 26, 0, 6, 19};
	int vet2[10] = {21, 9, 30, 8, 23, 19, 26, 3, 10, 20};

	for(int i=0; i<10; i++){
		x = vet[i];
		y = vet2[i];
		bt->insert(x, y);
	}

	cout << endl;
	cout << "Level:" << endl; 
	bt->printInLevel();
	cout << endl;
	
	cout << "4th element in order: ";
	Node<int> *n2 = bt->nthSelect(4);
	cout << n2->key.first << "," << n2->key.second << " " << n2->color << endl;

	cout << "Rank of element 15: ";
	cout << bt->rank(15) << endl;


	cout << endl;
	cout << "Num of inversions:" << bt->getInversions() << endl;


	cout << endl;
	cout << "Remove element 5:";
	bt->remove(5);

	cout << endl;
	cout << "Level:" << endl; 
	bt->printInLevel();
	cout << endl;


	cout << "Node 11:" << endl;
	Node<int> *n1 = bt->searchElement(16);
	cout << n1->key.first << "," << n1->key.second << " " << n1->color << endl;

	cout << "3th element in order: ";
	n1 = bt->nthSelect(3);
	cout << n1->key.first << "," << n1->key.second << " " << n1->color << endl;


	cout << endl;

	cout << "Greatest element: ";
	n1 = bt->getMaximum();
	cout << n1->key.first << "," << n1->key.second << " " << n1->color << endl;

	cout << "Lowest element: ";
	n1 = bt->getMinimum();
	cout << n1->key.first << "," << n1->key.second << " " << n1->color << endl;


	cout << endl;

	cout << "In interval [22, 25]: ";
	n1 = bt->search(14, 25);
	cout << n1->key.first << "," << n1->key.second << " " << n1->color << endl;


	delete bt;

	return 0;
}