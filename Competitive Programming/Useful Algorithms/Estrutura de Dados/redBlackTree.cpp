/*
* Mais detalhes em: http://www.geeksforgeeks.org/
* Simulacao: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
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
* Deixa a arvore balanceada, como a AVL,
* porem eh melhor para insercoes/remocoes,
* pois faz menos rotacoes.
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


const char BLACK = 'B';
const char RED = 'R';

template <class T>
class Node{

	public:
		Node *left;
		Node *right;
		Node *parent;
		char color;
		T key;

		Node(T x){
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->key = x;
			this->color = RED;
		};

		virtual ~Node(){};
};

template <class T>
class RedBlackTree{

	private:

		int ammount;
		int h;
		int lastAmmount;
		Node<T> *root;
		Node<T> *NIL;
		
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

		RedBlackTree();
		virtual ~RedBlackTree();
		void destroy();
		
		void insert(T x);
		void remove(T x);
		Node<T> *search(T x);
		
		
		bool empty();
		int height();

		void printInOrder();
		void printPreOrder();
		void printPosOrder();
		void printInLevel();
};


template <class T>
RedBlackTree<T>::RedBlackTree(){
	
	this->ammount = 0;
	this->lastAmmount = 0;
	this->h = 0;
	
	this->NIL = new Node<T>(-1);
	this->NIL->color = BLACK;
	this->NIL->left = this->NIL->right = this->NIL->parent = this->NIL;
	

	this->root = this->NIL;
	this->root->color = BLACK;
	this->root->left = this->root->right = this->root->parent = this->NIL;
}

template <class T>
RedBlackTree<T>::~RedBlackTree(){
	this->destroy();
}


template <class T>
void RedBlackTree<T>::destroy_node(Node<T> *&node){
	if(node != this->NIL){
		this->destroy_node(node->left);
		this->destroy_node(node->right);
		delete node;
	}
}

template <class T>
void RedBlackTree<T>::destroy(){
	this->destroy_node(this->root);
}



template <class T>
void RedBlackTree<T>::rotateLeft(Node<T> *x){
	
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
}


template <class T>
void RedBlackTree<T>::rotateRight(Node<T> *y){
	
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
}


template <class T>
void RedBlackTree<T>::insertFixUp(Node<T> *z){
	

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
void RedBlackTree<T>::insert(T val){
	
	Node<T> *z = new Node<T>(val);
	Node<T> *x = this->root;
	Node<T> *y = this->NIL;

	while(x != this->NIL){
		y = x;
		if(z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}


	z->parent = y;
	
	if(y == this->NIL)
		this->root = z;
	else if(z->key < y->key)
		y->left = z;
	else
		y->right = z;


	z->left = this->NIL;
	z->right = this->NIL;
	z->color = RED;
	
	this->insertFixUp(z);
	this->ammount++;
}


template <class T>
void RedBlackTree<T>::transplant(Node<T> *u, Node<T> *v){
	if(u->parent == this->NIL)
		this->root = v;
	else if(u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

template <class T>
Node<T> *RedBlackTree<T>::minNode(Node<T> *z){
	Node<T> *x = z;
	while(x->left != this->NIL)
		x = x->left;
	return x;
}

template <class T>
void RedBlackTree<T>::removeFixUp(Node<T> *x){

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
void RedBlackTree<T>::remove(T val){
	Node<T> *z = this->search(val);
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
Node<T> *RedBlackTree<T>::search_node(Node<T> *&node, T x){
	if(node == this->NIL)
		return this->NIL;
	
	if(node->key == x)
		return node;
	
	if(node->key > x)
		return this->search_node(node->left, x);
	
	return this->search_node(node->right, x);
}

template <class T>
Node<T> *RedBlackTree<T>::search(T x){
	return this->search_node(this->root, x);
}





template <class T>
bool RedBlackTree<T>::empty(){
	return (this->root == this->NIL);
}

template <class T>
int RedBlackTree<T>::height(){
	
	if(this->lastAmmount == this->ammount)
		return this->h;

	this->h = this->calculeHeight(this->root);
	this->lastAmmount = this->ammount;
	return this->h;
}


template <class T>
int RedBlackTree<T>::calculeHeight(Node<T> *&node){
	if(node == this->NIL)
		return 0;

	int l_h = this->calculeHeight(node->left);
	int r_h = this->calculeHeight(node->right);

	if(l_h > r_h)
		return l_h+1;

	return r_h+1;
}





template <class T>
void RedBlackTree<T>::printInfo(Node<T> *&x){
	cout << "  key=";
	cout << x->key;

	cout << "  l->key=";
	if( x->left == this->NIL) 
		cout << "N";
	else 
		cout << x->left->key;

	cout << "  r->key=";
	if( x->right == this->NIL) 
		cout << "N";
	else 
		cout << x->right->key;

	cout << "  p->key=";
	if( x->parent == this->NIL) 
		cout << "N";
	else 
		cout << x->parent->key;

	cout << "  color=" << x->color << endl;
}

template <class T>
void RedBlackTree<T>::printInOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printInOrder_node(node->left);
		this->printInfo(node);
		this->printInOrder_node(node->right);
	}
}

template <class T>
void RedBlackTree<T>::printInOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void RedBlackTree<T>::printPreOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printInfo(node);
		this->printPreOrder_node(node->left);
		this->printPreOrder_node(node->right);
	}
}

template <class T>
void RedBlackTree<T>::printPreOrder(){
	this->printPreOrder_node(this->root);
}



template <class T>
void RedBlackTree<T>::printPosOrder_node(Node<T> *&node){
	if(node != this->NIL){
		this->printPosOrder_node(node->left);
		this->printPosOrder_node(node->right);
		this->printInfo(node);
	}
}

template <class T>
void RedBlackTree<T>::printPosOrder(){
	this->printPosOrder_node(this->root);
}



template <class T>
void RedBlackTree<T>::printInLevel(){
	int h = this->height();
	for(int i=1; i<=h; i++)
		this->printInLevel_node(this->root, i);
}


template <class T>
void RedBlackTree<T>::printInLevel_node(Node<T> *&node, int level){
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
	RedBlackTree<int> *bt = new RedBlackTree<int>();

	int x = 0;
	int vet[9] = {11, 2, 14, 1, 7, 15, 5, 8, 4};

	for(int i=0; i<9; i++){
		x = vet[i];
		bt->insert(x);
	}

	cout << endl;
	cout << "Level:" << endl; 
	bt->printInLevel();
	cout << endl;
	

	bt->remove(5);

	cout << endl;
	cout << "Level:" << endl; 
	bt->printInLevel();
	cout << endl;


	cout << "Node 11:" << endl;
	Node<int> *n1 = bt->search(11);
	cout << n1->key << " " << n1->color << endl;

	delete bt;

	return 0;
}