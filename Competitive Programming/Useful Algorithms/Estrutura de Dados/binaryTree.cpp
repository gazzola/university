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
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "../utils.h"

using namespace std;
const int MAX = 8;

template <class T>
class Node{

	public:
		Node *left;
		Node *right;
		Node *parent;
		T key;

		Node(T x){
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->key = x; 
		};

		virtual ~Node(){
			delete this->left;
			delete this->right;
			delete this->parent;
		};
};


template <class T>
class BinTree{

	private:

		int ammount;
		int h;
		int lastAmmount;
		Node<T> *root;
		
		void destroy_node(Node<T> *&node);
		void insert_node(Node<T> *&node, Node<T> *&parent, T x);
		Node<T> *remove_node(Node<T> *&node, T x);
		Node<T> *search_node(Node<T> *&node, T x);
		void printInOrder_node(Node<T> *&node);
		void printPreOrder_node(Node<T> *&node);
		void printPosOrder_node(Node<T> *&node);
		void printInLevel_node(Node<T> *&node, int level);
		int calculeHeight(Node<T> *&node);
		

	public:

		BinTree();
		virtual ~BinTree();
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
BinTree<T>::BinTree(){
	this->root = NULL;
	this->ammount = 0;
	this->lastAmmount = 0;
	this->h = 0;
}

template <class T>
BinTree<T>::~BinTree(){
	delete this->root;
}



template <class T>
void BinTree<T>::destroy_node(Node<T> *&node){
	if(*node != NULL){
		this->destroy(node->left);
		this->destroy(node->right);
		delete left;
	}
}

template <class T>
void BinTree<T>::destroy(){
	this->destroy_node(this->root);
}



template <class T>
void BinTree<T>::insert_node(Node<T> *&node, Node<T> *&parent, T x){
	
	if(node == NULL){
		node = new Node<T>(x);
		node->parent = parent;
		this->ammount++;
	}
	else if(x < node->key){
		this->insert_node(node->left, node, x);
	}
	else{
		this->insert_node(node->right, node, x);
	}
}


template <class T>
void BinTree<T>::insert(T x){
	if(this->root == NULL){
		this->root = new Node<T>(x);
		this->ammount++;
	}
	else
		this->insert_node(this->root, this->root, x);
}



template <class T>
Node<T> *BinTree<T>::remove_node(Node<T> *&node, T x){
	if(node == NULL)
		return NULL;
	else if(node->key == x){
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
void BinTree<T>::remove(T x){
	this->remove_node(this->root, x);
}



template <class T>
Node<T> *BinTree<T>::search_node(Node<T> *&node, T x){
	if(node == NULL)
		return NULL;
	else if(node->key == x)
		return node;
	else if(node->key > x)
		return this->search_node(node->left, x);
	else
		return this->search_node(node->right, x);

	return NULL;
}

template <class T>
Node<T> *BinTree<T>::search(T x){
	return this->search_node(this->root, x);
}


template <class T>
bool BinTree<T>::empty(){
	return (this->root == NULL);
}

template <class T>
int BinTree<T>::height(){
	if(this->lastAmmount == this->ammount)
		return this->h;
	int h = this->calculeHeight(this->root);
	this->h = h;
	this->lastAmmount = this->ammount;
	return h;
}


template <class T>
int BinTree<T>::calculeHeight(Node<T> *&node){
	if(node == NULL)
		return 0;

	int l_h = this->calculeHeight(node->left);
	int r_h = this->calculeHeight(node->right);

	if(l_h > r_h)
		return l_h+1;

	return r_h+1;
}



template <class T>
void BinTree<T>::printInOrder_node(Node<T> *&node){
	if(node != NULL){
		this->printInOrder_node(node->left);
		cout << node->key << " ";
		this->printInOrder_node(node->right);
	}
}

template <class T>
void BinTree<T>::printInOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void BinTree<T>::printPreOrder_node(Node<T> *&node){
	if(node != NULL){
		cout << node->key << " ";
		this->printInOrder_node(node->left);
		this->printInOrder_node(node->right);
	}
}

template <class T>
void BinTree<T>::printPreOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void BinTree<T>::printPosOrder_node(Node<T> *&node){
	if(node != NULL){
		this->printInOrder_node(node->left);
		this->printInOrder_node(node->right);
		cout << node->key << " ";
	}
}

template <class T>
void BinTree<T>::printPosOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void BinTree<T>::printInLevel(){
	int h = this->height();
	for(int i=1; i<=h; i++)
		this->printInLevel_node(this->root, i);
}


template <class T>
void BinTree<T>::printInLevel_node(Node<T> *&node, int level){
	if(node == NULL)
		return;
	
	if(level == 1)
		cout << node->key << " ";
	else if(level > 1){
		this->printInLevel_node(node->left, level-1);
		this->printInLevel_node(node->right, level-1);
	}
}



int main(){

	srand(time(NULL));
	BinTree<int> *bt = new BinTree<int>();

	int x = 0;
	for(int i=0; i<MAX; i++){
		x = rand()%MAX;
		cout << x << " ";
		bt->insert(x);
	}

	cout << endl;
	bt->printInLevel();
	cout << endl;
	
	cout << endl << "Search ("<< x <<"):" << endl;
	Node<int> *n1 = bt->search(x);
	if(n1->parent == NULL)
		cout << n1->key << endl;
	else
		cout << n1->parent->key << " -> " << x << endl;
	

	cout << endl << "Remove ("<< x <<"):" << endl;
	bt->remove(x);
	bt->printInLevel();

	cout << endl;



	return 0;
}