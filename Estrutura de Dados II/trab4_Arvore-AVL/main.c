/******************************************
*
* TRABALHO 4 DE ESTRUTURAS DE DADOS II
* Arvores AVL
* Marcos Vinicius Treviso - 121150107
*
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include "trab4.c"


int main(){
    
    raiz novo;
    cria_arvore(&novo);


    /* ARVORE PARA ROTACAO SIMPLES (NESSE \/ CASO, SE REBALANCEADA APOS TODAS INSERCOES)

              42                         15
            /   \                      /   \
           15   88                    6    42
         /   \        ====>          /    /  \
        6    27                     4    27  88
       /
      4

    */
    insere(&novo, 42, &novo);
    insere(&novo, 15, &novo);
    insere(&novo, 88, &novo);
    insere(&novo, 6, &novo);
    insere(&novo, 27, &novo);
    insere(&novo, 4, &novo);



    /* ARVORE PARA ROTACAO DUPLA (NESSE \/ CASO, SE REBALANCEADA APOS TODAS INSERCOES)
    
               8                     6
             /   \                 /   \
            4    10               4     8
          /  \       ====>      /  \     \
         2    6                2    5     10
             /
            5
    
    insere(&novo, 8, &novo);
    insere(&novo, 4, &novo);
    insere(&novo, 10, &novo);
    insere(&novo, 2, &novo);
    insere(&novo, 6, &novo);
    insere(&novo, 5, &novo);
    */


    /* ARVORE SUGERIDA PELO SITE:
    http://www.site.uottawa.ca/~stan/csi2514/applets/avl/BT.html

    insere(&novo, 50, &novo);
    insere(&novo, 30, &novo);
    insere(&novo, 70, &novo);
    insere(&novo, 20, &novo);
    insere(&novo, 40, &novo);
    insere(&novo, 60, &novo);
    insere(&novo, 80, &novo);
    insere(&novo, 35, &novo);
    insere(&novo, 65, &novo);
    insere(&novo, 75, &novo);
    insere(&novo, 85, &novo);
    insere(&novo, 90, &novo);

    */

    printf("\n\nEM NIVEL BALANCEADA:\n");
    em_nivel(&novo);

    remove_no(&novo, 15, &novo);
    printf("\n\nEM NIVEL BALANCEADA SIMPLES APOS REMOVER %d:\n", 15);
    em_nivel(&novo);

    printf("\n");
    
    destroi_arvore(&novo);
    return 0;
}