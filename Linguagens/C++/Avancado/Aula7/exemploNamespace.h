/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploNamespaces.cpp - Simples exemplo da criação de um namespace
 */

namespace Mat {
    const float PI = 3.14;
    
    int maximo(int a, int b) {
        return (a > b ) ? a : b;
    }
    
    int minimo(int a, int b) {
        return (a < b ) ? a : b;
    }
    
    class NumeroComplexo {
        // ...
    };
    
    class BigInteger {
        // ...
    };
}
