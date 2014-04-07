/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exenploMath.c - Mostra como utilizar as principais funções do header math.h
 *
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    float x, y;
    
    printf("abs(-10) = %d\n", abs(-10));
    printf("abs(8) = %d\n\n", abs(8));
    
    printf("2.0 ^ 5.0 = %.2lf\n", pow(2, 5));
    printf("4.63 ^ 2.1 = %.2lf\n\n", pow(4.63, 2.1));
    
    printf("sqrt(9.0) = %.2lf\n", sqrt(9.0));
    printf("sqrt(0.5) = %.2lf\n\n", sqrt(0.5));
    
    printf("sin(PI) = %.2lf\n", sin(PI));
    printf("sin(2*PI) = %.2lf\n\n", sin(2*PI));
    
    printf("cos(PI) = %.2lf\n", cos(PI));
    printf("cos(2*PI) = %.2lf\n\n", cos(2*PI));
    
    printf("tan(PI) = %.2f\n", tan(PI));
    printf("tan(PI/4) = %.2f\n", tan(PI/4));
   
    getchar();   
     
    return 0;
}
