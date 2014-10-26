/*
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
* porem eh melhor pois faz menos rotacoes
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
		Node<T> *remove_node(Node<T> *&node, T x);
		Node<T> *search_node(Node<T> *&node, T x);
		void printInfo(Node<T> *&x);
		void printInOrder_node(Node<T> *&node);
		void printPreOrder_node(Node<T> *&node);
		void printPosOrder_node(Node<T> *&node);
		void printInLevel_node(Node<T> *&node, int level);
		int calculeHeight(Node<T> *&node);
		void rotateLeft(Node<T> *&x);
		void rotateRight(Node<T> *&y);
		void insert_node(Node<T> *&z);
		void insertFixUp(Node<T> *&x);

		

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
	this->lastAmmount = -1;
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
	delete this->root;
}



template <class T>
void RedBlackTree<T>::destroy_node(Node<T> *&node){
	if(node != NULL){
		this->destroy(node->left);
		this->destroy(node->right);
		delete node;
	}
}

template <class T>
void RedBlackTree<T>::destroy(){
	this->destroy_node(this->root);
}


template <class T>
void RedBlackTree<T>::rotateLeft(Node<T> *&x){
	
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
void RedBlackTree<T>::rotateRight(Node<T> *&y){
	
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
void RedBlackTree<T>::insertFixUp(Node<T> *&z){
	

	Node<T> *y;

	while(z != this->root and z->parent->color == RED){
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
}




template <class T>
Node<T> *RedBlackTree<T>::remove_node(Node<T> *&node, T x){
	if(node == NULL)
		return NULL;
	
	if(node->key == x){
		Node<T> *aux = node;
		node = NULL;
		return aux;
	}

	Node<T> *esq = this->remove_node(node->left, x);
	if(esq != NULL)
		return esq;

	Node<T> *dir = this->remove_node(node->right, x);
	if(dir != NULL)
		return dir;

	return NULL;
}

template <class T>
void RedBlackTree<T>::remove(T x){
	this->remove_node(this->root, x);
}



template <class T>
Node<T> *RedBlackTree<T>::search_node(Node<T> *&node, T x){
	if(node == NULL)
		return NULL;
	
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
		//cout << " " << node->key;
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
		cout << " " << node->key;
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
		cout << " " << node->key;
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
		this->printInfo(node); //cout << node->key << " ";
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
		cout << x << " ";
		bt->insert(x);
	}

	cout << endl;
	cout << "Level:" << endl; 
	bt->printInLevel();
	cout << endl;
	/*
	
	cout << endl << "Search ("<< x <<"):" << endl;
	Node<int> *n1 = bt->search(x);
	if(n1->parent == NULL)
		cout << n1->key << endl;
	else
		cout << n1->parent->key << " -> " << x << endl;
	

	cout << endl << "Remove ("<< x <<"):" << endl;
	bt->remove(x);
	bt->printInLevel();

	cout << endl;*/

	delete bt;

	return 0;
}