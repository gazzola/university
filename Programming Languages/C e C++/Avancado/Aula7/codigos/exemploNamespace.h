/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploNamespaces.cpp - Simples exemplo da cria��o de um namespace
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
