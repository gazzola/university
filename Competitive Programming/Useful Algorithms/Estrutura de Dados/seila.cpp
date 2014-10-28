#include <iostream>

using namespace std;


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
class RBTree{

    private:

        int ammount;
        Node<T> *root;

        void destroy_node(Node<T> *&node);      
        void rotateLeft(Node<T> *&x);
        void rotateRight(Node<T> *&y);
        void insertFixUp(Node<T> *&x);
        void printInfo(Node<T> *&x);

    public:

        Node<T> *NIL;
        RBTree();
        virtual ~RBTree();
        void destroy();

        void insert(T x);

};


template <class T>
RBTree<T>::RBTree(){

    this->ammount = 0;

    this->NIL = new Node<T>(-1);
    this->NIL->color = BLACK;
    this->NIL->left = this->NIL->right = this->NIL->parent = this->NIL;


    this->root = this->NIL;
    this->root->color = BLACK;
    this->root->left = this->root->right = this->root->parent = this->NIL;
}


template <class T>
RBTree<T>::~RBTree(){
    this->destroy();
}


template <class T>
void RBTree<T>::destroy_node(Node<T> *&node){
    if(node != this->NIL){
        this->destroy_node(node->left);
        this->destroy_node(node->right);
        delete node;
    }
}

template <class T>
void RBTree<T>::destroy(){
    this->destroy_node(this->root);
}


template <class T>
void RBTree<T>::rotateLeft(Node<T> *&x){

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
void RBTree<T>::rotateRight(Node<T> *&y){

	
    Node<T> *x = y->left;
    y->left = x->right;
    Node<T> *temp = y;

    if(x->right != this->NIL)
        x->right->parent = y;

    cout << "x:"; this->printInfo(x);
    cout << "y:"; this->printInfo(y);
    cout << endl;

    x->parent = temp->parent;
    y = temp;

    cout << "x:"; this->printInfo(x);
    cout << "y:"; this->printInfo(y);


    cout << endl;

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
void RBTree<T>::insertFixUp(Node<T> *&z){


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


                z->parent->color = RED;
                z->parent->parent->color = BLACK;
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
void RBTree<T>::insert(T val){

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
void RBTree<T>::printInfo(Node<T> *&x){
    cout << "  key=";
    cout << x->key;

    cout << "  l->key=";
    if(x->left == this->NIL) 
        cout << "N";
    else 
        cout << x->left->key;

    cout << "  r->key=";
    if(x->right == this->NIL) 
        cout << "N";
    else 
        cout << x->right->key;

    cout << "  p->key=";
    if(x->parent == this->NIL) 
        cout << "N";
    else 
        cout << x->parent->key;

    cout << "  color=" << x->color << endl;
}



int main(){

    srand(time(NULL));
    RBTree<int> *bt = new RBTree<int>();

    int x = 0;
    int vet[9] = {11, 2, 14, 1, 7, 15, 5, 8, 4};

    for(int i=0; i<9; i++){
        x = vet[i];
        bt->insert(x);
    }

    delete bt;

    return 0;
}