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

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>


using namespace std;
const int MAX = 8;

template <class T>
class Node{

	public:
		Node *left;
		Node *right;
		Node *parent;
		int h;
		T key;

		Node(T x){
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->key = x; 
		};

		virtual ~Node(){};
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
	this->destroy();
}


template <class T>
void BinTree<T>::destroy_node(Node<T> *&node){
	if(node != NULL){
		this->destroy_node(node->left);
		this->destroy_node(node->right);
		delete node;
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
		node->h = parent->h+1;
	}
	else if(x <= node->key)
		this->insert_node(node->left, node, x);
	else
		this->insert_node(node->right, node, x);
}


template <class T>
void BinTree<T>::insert(T x){
	if(this->root == NULL){
		this->root = new Node<T>(x);
		this->root->h = 1;
		this->ammount++;
	}
	else
		this->insert_node(this->root, this->root, x);
}



template <class T>
Node<T> *BinTree<T>::remove_node(Node<T> *&node, T x){
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
void BinTree<T>::remove(T x){
	this->remove_node(this->root, x);
}



template <class T>
Node<T> *BinTree<T>::search_node(Node<T> *&node, T x){
	if(node == NULL)
		return NULL;
	
	if(node->key == x)
		return node;
	
	if(node->key > x)
		return this->search_node(node->left, x);
	
	return this->search_node(node->right, x);
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

	this->h = this->calculeHeight(this->root);
	this->lastAmmount = this->ammount;
	return this->h;
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
		cout << " " << node->key;
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
		cout << " " << node->key;
		this->printPreOrder_node(node->left);
		this->printPreOrder_node(node->right);
	}
}

template <class T>
void BinTree<T>::printPreOrder(){
	this->printPreOrder_node(this->root);
}



template <class T>
void BinTree<T>::printPosOrder_node(Node<T> *&node){
	if(node != NULL){
		this->printPosOrder_node(node->left);
		this->printPosOrder_node(node->right);
		cout << " " << node->key;
	}
}

template <class T>
void BinTree<T>::printPosOrder(){
	this->printPosOrder_node(this->root);
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
		cout << " " << node->key;
	else if(level > 1){
		this->printInLevel_node(node->left, level-1);
		this->printInLevel_node(node->right, level-1);
	}
}



int main(){

	srand(time(NULL));

	int x;

	BinTree<int> *bt = new BinTree<int>();
	for(int i=0; i<MAX; i++){
		cin >> x;
		x = rand()%MAX;
		cout << x << " ";
		bt->insert(x);
	}


	cout << endl;
	
	cout << "Pre.:"; bt->printPreOrder();
	cout << endl;
	cout << "In..:"; bt->printInOrder();
	cout << endl;
	cout << "Pos.:"; bt->printPosOrder();
	cout << endl;
	cout << "Levl:"; bt->printInLevel();
	cout << endl;

	cout << endl;

	delete bt;


	return 0;
}