/*
* Referencias:
* http://crbonilha.com/pt/um-pouco-sobre-segment-trees/
* http://letuskode.blogspot.com.br/2013/01/segtrees.html
* http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
* http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/
*
* Complexidade:
* Inserir: 		O(logn)
* Buscar: 		O(logn)
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
		int h, l, r; //height, left index, right index

		T key; //sum

		Node(T x){
			this->left = NULL;
			this->right = NULL;
			this->parent = NULL;
			this->key = x; 
		};

		virtual ~Node(){};
};


template <class T>
class SegmentTree{

	private:

		int ammount, lastAmmount;
		int h;	// height of the tree
		Node<T> *root;
		
		void destroy_node(Node<T> *&node);
		Node<T> *build_node(vector<T> &v, int l, int r);
		T update_node(Node<T> *&node, int i, T v);
		T search_node(Node<T> *&node, int l, int r);

		void printInOrder_node(Node<T> *&node);
		void printPreOrder_node(Node<T> *&node);
		void printPosOrder_node(Node<T> *&node);
		void printInLevel_node(Node<T> *&node, int level);
		
		int calculeHeight(Node<T> *&node);
		

	public:

		SegmentTree();
		virtual ~SegmentTree();
		void destroy();
		
		void build(vector<T> &v, int l, int r);
		void update(int i, T v);
		T search(int l, int r);
		
		bool empty();
		int height();

		void printInOrder();
		void printPreOrder();
		void printPosOrder();
		void printInLevel();
};


template <class T>
SegmentTree<T>::SegmentTree(){
	this->root = NULL;
	this->ammount = 0;
	this->lastAmmount = 0;
	this->h = 0;
}

template <class T>
SegmentTree<T>::~SegmentTree(){
	this->destroy();
}


template <class T>
void SegmentTree<T>::destroy_node(Node<T> *&node){
	if(node != NULL){
		this->destroy_node(node->left);
		this->destroy_node(node->right);
		delete node;
	}
}

template <class T>
void SegmentTree<T>::destroy(){
	this->destroy_node(this->root);
}


template <class T>
Node<T> *SegmentTree<T>::build_node(vector<T> &v, int l, int r){
	
	Node<T> *cur = new Node<T>(0);
	cur->l = l;
	cur->r = r;

	// range(l, r) == 0 entao o no eh uma folha
	if(l == r){
		cur->left = cur->right = NULL;
		cur->key = v[l];
	}
	else{

		int m = (l+r)/2;
		cur->left = this->build_node(v, l, m);
		cur->right = this->build_node(v, m+1, r);

		//if is a sum tree
		cur->key = cur->left->key + cur->right->key;

		//if is a min tree
		//cur->key = min(cur->left->key, cur->right->key);
	}

	this->ammount++;
	return cur;
}


template <class T>
void SegmentTree<T>::build(vector<T> &v, int l, int r){
	this->root = this->build_node(v, l, r);
}





template <class T>
T SegmentTree<T>::update_node(Node<T> *&node, int i, T v){
	// completamente fora do intervalo
	if(i < node->l or i > node->r)
		return node->key;
	else if(i <= node->l and i >= node->r){
		node->key = v;
		return node->key;
	}
	
	//if is a sum tree
	node->key = this->update_node(node->left, i, v)+this->update_node(node->right, i, v);
	
	//if is a min tree
	//node->key = min(this->update_node(node->left, i, v), this->update_node(node->right, i, v));
	
	return node->key;
}


template <class T>
void SegmentTree<T>::update(int i, T v){
	this->update_node(this->root, i, v);
}




template <class T>
T SegmentTree<T>::search_node(Node<T> *&node, int l, int r){
	// completamente fora do intervalo
	if(r < node->l or l > node->r)
		return 0;
	else if(l <= node->l and r >= node->r)
		return node->key;
	
	return this->search_node(node->left, l, r)+this->search_node(node->right, l, r);
}


template <class T>
T SegmentTree<T>::search(int l, int r){
	return this->search_node(this->root, l, r);
}



template <class T>
bool SegmentTree<T>::empty(){
	return (this->root == NULL);
}

template <class T>
int SegmentTree<T>::height(){
	
	if(this->lastAmmount == this->ammount)
		return this->h;

	this->h = this->calculeHeight(this->root);
	this->lastAmmount = this->ammount;
	return this->h;
}


template <class T>
int SegmentTree<T>::calculeHeight(Node<T> *&node){
	if(node == NULL)
		return 0;

	int l_h = this->calculeHeight(node->left);
	int r_h = this->calculeHeight(node->right);

	if(l_h > r_h)
		return l_h+1;

	return r_h+1;
}


template <class T>
void SegmentTree<T>::printInOrder_node(Node<T> *&node){
	if(node != NULL){
		this->printInOrder_node(node->left);
		cout << " " << node->key;
		this->printInOrder_node(node->right);
	}
}

template <class T>
void SegmentTree<T>::printInOrder(){
	this->printInOrder_node(this->root);
}



template <class T>
void SegmentTree<T>::printPreOrder_node(Node<T> *&node){
	if(node != NULL){
		cout << " " << node->key;
		this->printPreOrder_node(node->left);
		this->printPreOrder_node(node->right);
	}
}

template <class T>
void SegmentTree<T>::printPreOrder(){
	this->printPreOrder_node(this->root);
}



template <class T>
void SegmentTree<T>::printPosOrder_node(Node<T> *&node){
	if(node != NULL){
		this->printPosOrder_node(node->left);
		this->printPosOrder_node(node->right);
		cout << " " << node->key;
	}
}

template <class T>
void SegmentTree<T>::printPosOrder(){
	this->printPosOrder_node(this->root);
}



template <class T>
void SegmentTree<T>::printInLevel(){
	int h = this->height();
	for(int i=1; i<=h; i++)
		this->printInLevel_node(this->root, i);
}


template <class T>
void SegmentTree<T>::printInLevel_node(Node<T> *&node, int level){
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

	SegmentTree<int> *st = new SegmentTree<int>();

	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	v.push_back(3);

	st->build(v, 0, 5);

	cout << st->search(0, 5) << endl;
	
	st->update(5, -1);
	cout << st->search(0, 5) << endl;

	
	cout << endl;
	cout << "Levl:"; st->printInLevel();
	cout << endl;

	delete st;

	return 0;
}