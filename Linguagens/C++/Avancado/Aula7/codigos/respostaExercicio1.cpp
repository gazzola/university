/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicio1.cpp - Resposta ao primeiro exercício da aula sete.
 */


#include <iostream>
#include <string>

using namespace std;

template <class T>
class Vetor {

public:

    T *elementos;
    int proximo;
    int tamanho;
    
public:

    Vetor(int tamanho);

    void inserir(const T &elemento);
    
    int getIndice(const T &elemento);
    
    bool contem(const T &elemento) {
        return this->getIndice(elemento) != -1;
    }
    
    void remover(const T &elemento);
    
    int getTamanho() { return this->tamanho; };

    ~Vetor() {
        delete [] this->elementos;
    }
    
    T &operator [] (int indice);

};

template <class T>
Vetor<T>::Vetor(int tamanho) {
    this->elementos = new T[tamanho];
    this->tamanho = tamanho;
    this->proximo = 0;
}

template <class T>
void Vetor<T>::inserir(const T &elemento) {
    if (this->proximo < this->tamanho) {
        this->elementos[this->proximo] = elemento;
        this->proximo++;
    }
}


template <class T>
int Vetor<T>::getIndice(const T &elemento) {
    for (int i = 0; i < this->tamanho; i++) {
        if (this->elementos[i] == elemento) {
                return i;
        }
    }

    return -1;
}

template <class T>
void Vetor<T>::remover(const T &elemento) {
    int indice = this->getIndice(elemento);

    if (indice != -1) {
        for (int i = indice; i + 1 < this->tamanho; i++) {
                this->elementos[i] = this->elementos[i+1];
        }
    }
}

template <class T>
T &Vetor<T>::operator[](int indice) {
  return this->elementos[indice];
}

int main() {
    Vetor<string> v(10);

    v.inserir("EU");

    cout << "v cotem EU ? " << v.contem("EU") << endl;
    cout << "v indice de EU ? " << v.getIndice("EU") << endl;

    cout << "v cotem TU ? " << v.contem("TU") << endl;
    cout << "v indice de TU ? " << v.getIndice("TU") << endl;

    v.inserir("TU");

    cout << "v cotem TU ? " << v.contem("TU") << endl;
    cout << "v indice de TU ? " << v.getIndice("TU") << endl;

    v.remover("EU");

    cout << "v cotem EU ? " << v.contem("EU") << endl;
    cout << "v indice de EU ? " << v.getIndice("EU") << endl;

    cout << "v cotem TU ? " << v.contem("TU") << endl;
    cout << "v indice de TU ? " << v.getIndice("TU") << endl;

    v[0] = "EU";
    v.inserir("TU");
    v.inserir("ELE");
    v.inserir("NOS");
    v.inserir("VOS");
    v.inserir("ELES");
    cout << "Elementos: ";
    for (int i = 0; i < v.getTamanho(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}
