/************************************************
TRABALHO DE MAT. DISCRETA
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int fatorial(int n);
void menu();
void menu_combinacao(char tipo[5]);
void menu_permutacao(char tipo[5]);
void menu_pombo();
void imprimir_combinacao(char tipo[5], int qtd_elem, int grupo, int result);
void imprimir_permutacao(char tipo[5], int qtd_elem, int grupo, int result);
void imprimir_pombo(int qtd_elem, int grupo, int result);


int fatorial(int n){
    if(n > 1){ 
        return n*fatorial(n-1);
    }
	else{
        return 1;
    }
}

int fatorialIt(int n){
	if(n < 2)
		return 1;
	else{
		int m = n;
		while(n--)
			m *= n;
		return m;
	}
}

void menu(){    // funcao menu: eh chamada para exibir o primeiro menu e de acordo com o numero digitado, seleciona a opcao correpondente

int whl = 1, val;
system("cls");

    printf("****************************\n****** MENU CONTAGENS ******\n\n");
    printf("1 -> Combinacao de n elementos em grupos de k elementos sem repeticao\n");
    printf("2 -> Combinacao de n elementos em grupos de k elementos com repeticao\n");
    printf("3 -> Permutacao de n elementos\n");
    printf("4 -> Permutacao de n elementos em grupos de k elementos sem repeticao\n");
    printf("5 -> Permutacao de n elementos em grupos de k elementos com repeticao\n");
    printf("6 -> Principio da casa do pombo\n");

    while(whl){

        scanf("%d", &val);
        fflush(stdin);

        if(val > 6 || val < 1){
            printf("\nDigite uma das opcoes acima!\n");

        }
        else{

            if(val == 1){
                menu_combinacao("nrep");
            }
            else if(val == 2){
                menu_combinacao("crep");
            }
            else if(val == 3){
                menu_permutacao("norm");
            }
            else if(val == 4){
                menu_permutacao("nrep");
            }
            else if(val == 5){
                menu_permutacao("crep");
            }
            else if(val == 6){
                menu_pombo();
            }

            whl = 0;
        }
    }

}

void menu_combinacao(char tipo[5]){     // funcao menu_combinacao: Reponsavel pelo sub-menu de combinacao com repeticao e sem repeticao, atraves dela eh calculada os respectivos valores para as combinacoes

    system("cls");
    printf("****************************\n****** MENU CONTAGENS ******\n\n");

    if(strcmp(tipo, "nrep") == 0){ // sem repeticao

        printf("\n**** Combinacao de n elementos em grupos de k elementos sem repeticao ***\n");

        int qtd_elem;
        printf("\nDigite a quantidade de elementos que voce deseja combinar: ");
        fflush(stdin);
        scanf("%d", &qtd_elem);

        int grupo;
        printf("Digite o numero de elementos que voce deseja em cada grupo: ");
        fflush(stdin);
        scanf("%d", &grupo);

        int result;
        result = fatorial(qtd_elem) / (fatorial(grupo) * fatorial(qtd_elem-grupo));         //realiza o calculo de acordo com a formula
        printf("\n\nFORMULA USADA: C(n, r) = n! / ( r!(n-r)! )\nRESULTADO: %d", result);    //imprime a formula e o resultado

        int opcao, bot=1;
        printf("\n\n****************************\n**** ESCOLHA UMA OPCAO *****\n\n");
        printf("1 -> Repetir\n2 -> Imprimir Subconjuntos\n9 -> Voltar\n0 -> Sair\n");


        while(bot){
            scanf("%d", &opcao);
            fflush(stdin);

            if(opcao == 1){
                bot=0;
                menu_combinacao("nrep");
            }
            else if(opcao == 2){
                bot=0;
                imprimir_combinacao("nrep", qtd_elem, grupo, result);
            }
            else if(opcao == 9){
                bot=0;
                menu();
            }
             else if(opcao == 0){
                bot=0;
                exit(0);
            }
            else{
                bot=1;
                printf("\nDigite uma das opcoes acima: ");
            }
        }

    }
    else{ // com repeticao

        printf("\n**** Combinacao de n elementos em grupos de k elementos com repeticao ***\n");

        int qtd_elem;
        printf("\nDigite a quantidade de elementos que voce deseja combinar: ");
        fflush(stdin);
        scanf("%d", &qtd_elem);

        int grupo;
        printf("Digite o numero de elementos que voce deseja em cada grupo: ");
        fflush(stdin);
        scanf("%d", &grupo);

        int result;
        result = fatorial(qtd_elem+grupo-1) / (fatorial(grupo) * fatorial(qtd_elem+grupo-1-grupo));         //realiza o calculo de acordo com a formula
        printf("\n\nFORMULA USADA: C(n+r-1, r) = (n+r-1)! / ( r!((n+r-1)-r)! )\nRESULTADO: %d", result);    //imprime a formula e o resultado

        int opcao, bot=1;
        printf("\n\n****************************\n**** ESCOLHA UMA OPCAO *****\n\n");
        printf("1 -> Repetir\n2 -> Imprimir Subconjuntos\n9 -> Voltar\n0 -> Sair\n");


        while(bot){
            scanf("%d", &opcao);
            fflush(stdin);

            if(opcao == 1){
                bot=0;
                menu_combinacao("crep");
            }
            else if(opcao == 2){
                bot=0;
                imprimir_combinacao("crep", qtd_elem, grupo, result);
            }
            else if(opcao == 9){
                bot=0;
                menu();
            }
             else if(opcao == 0){
                bot=0;
                exit(0);
            }
            else{
                bot=1;
                printf("\nDigite uma das opcoes acima: ");
            }
        }

    }


}

void menu_permutacao(char tipo[5]){     // funcao menu_permutacao: Reponsavel pelo sub-menu de permutacao com repeticao, sem repeticao e normal, atraves dela eh calculada os respectivos valores para as permutacoes

    system("cls");
    printf("****************************\n****** MENU CONTAGENS ******\n\n");


    if(strcmp(tipo, "nrep") == 0){ // sem repeticao

        printf("\n**** Permutacao de n elementos em grupos de k elementos sem repeticao ***\n");

        int qtd_elem;
        printf("\nDigite a quantidade de elementos que voce deseja permutar: ");
        fflush(stdin);
        scanf("%d", &qtd_elem);

        int grupo;
        printf("Digite o numero de elementos que voce deseja em cada grupo: ");
        fflush(stdin);
        scanf("%d", &grupo);

        int result;
        result = fatorial(qtd_elem) / (fatorial(qtd_elem-grupo));                       //realiza o calculo de acordo com a formula
        printf("\n\nFORMULA USADA: P(n, r) = n! / (n-r)! \nRESULTADO: %d", result);     //imprime a formula e o resultado

        int opcao, bot=1;
        printf("\n\n****************************\n**** ESCOLHA UMA OPCAO *****\n\n");
        printf("1 -> Repetir\n2 -> Imprimir Subconjuntos\n9 -> Voltar\n0 -> Sair\n");


        while(bot){
            scanf("%d", &opcao);
            fflush(stdin);

            if(opcao == 1){
                bot=0;
                menu_permutacao("nrep");
            }
            else if(opcao == 2){
                bot=0;
                imprimir_permutacao("nrep", qtd_elem, grupo, result);
            }
            else if(opcao == 9){
                bot=0;
                menu();
            }
             else if(opcao == 0){
                bot=0;
                exit(0);
            }
            else{
                bot=1;
                printf("\nDigite uma das opcoes acima: ");
            }
        }

    }
    else if(strcmp(tipo, "crep") == 0){ // com repeticao

        printf("\n**** Permutacao de n elementos em grupos de k elementos com repeticao ***\n");

        int qtd_elem;
        printf("\nDigite a quantidade de elementos que voce deseja permutar: ");
        fflush(stdin);
        scanf("%d", &qtd_elem);

        int grupo;
        printf("Digite o numero de elementos que sao equivalentes: ");
        fflush(stdin);
        scanf("%d", &grupo);

        int result;
        result = fatorial(qtd_elem) / fatorial(grupo);      //realiza o calculo de acordo com a formula
        printf("\n\nFORMULA USADA: P(n; n1,n2,...,nr) = n! / (n1,n2,...,nr)! )\nRESULTADO: %d", result);    //imprime a formula e o resultado

        int opcao, bot=1;
        printf("\n\n****************************\n**** ESCOLHA UMA OPCAO *****\n\n");
        printf("1 -> Repetir\n2 -> Imprimir Subconjuntos\n9 -> Voltar\n0 -> Sair\n");


        while(bot){
            scanf("%d", &opcao);
            fflush(stdin);

            if(opcao == 1){
                bot=0;
                menu_permutacao("crep");
            }
            else if(opcao == 2){
                bot=0;
                imprimir_permutacao("crep", qtd_elem, grupo, result);
            }
            else if(opcao == 9){
                bot=0;
                menu();
            }
             else if(opcao == 0){
                bot=0;
                exit(0);
            }
            else{
                bot=1;
                printf("\nDigite uma das opcoes acima: ");
            }
        }

    }
    else{

        printf("\n**** Permutacao de n elementos ***\n");

        int qtd_elem;
        printf("\nDigite a quantidade de elementos que voce deseja permutar: ");
        fflush(stdin);
        scanf("%d", &qtd_elem);

        int result;
        result = fatorial(qtd_elem);        //realiza o calculo de acordo com a formula
        printf("\n\nFORMULA USADA: P(n) = n! )\nRESULTADO: %d", result);    //imprime a formula e o resultado

        int opcao, bot=1;
        printf("\n\n****************************\n**** ESCOLHA UMA OPCAO *****\n\n");
        printf("1 -> Repetir\n2 -> Imprimir Subconjuntos\n9 -> Voltar\n0 -> Sair\n");


        while(bot){
            scanf("%d", &opcao);
            fflush(stdin);

            if(opcao == 1){
                bot=0;
                menu_permutacao("norm");
            }
            else if(opcao == 2){
                bot=0;
                imprimir_permutacao("norm", qtd_elem, 1, result);
            }
            else if(opcao == 9){
                bot=0;
                menu();
            }
             else if(opcao == 0){
                bot=0;
                exit(0);
            }
            else{
                bot=1;
                printf("\nDigite uma das opcoes acima: ");
            }
        }

    }

}


void menu_pombo(){    // funcao menu_pombo: Reponsavel pelo sub-menu do principio da casa do pombo, atraves dela eh calculada os respectivos valores para o principio da casa do pombo

    system("cls");
    printf("****************************\n****** MENU CONTAGENS ******\n\n");

        printf("\n**** Principio da casa do pombo ***\n");

        int qtd_elem;
        printf("\nDigite a quantidade de elementos que voce deseja alocar: ");
        fflush(stdin);
        scanf("%d", &qtd_elem);

        int grupo;
        printf("Digite a quantidade de lugares para alocar-se: ");
        fflush(stdin);
        scanf("%d", &grupo);

        int result;
        result = ((qtd_elem-1)/grupo)+1;       //realiza o calculo de acordo com a formula
        printf("\n\nFORMULA USADA:  [_n-1/r_]+1 \nRESULTADO: %d", result);  //imprime a formula e o resultado

        int opcao, bot=1;
        printf("\n\n****************************\n**** ESCOLHA UMA OPCAO *****\n\n");
        printf("1 -> Repetir\n2 -> Imprimir Subconjuntos\n9 -> Voltar\n0 -> Sair\n");


        while(bot){
            scanf("%d", &opcao);
            fflush(stdin);

            if(opcao == 1){
                bot=0;
                menu_pombo();
            }
            else if(opcao == 2){
                bot=0;
                imprimir_pombo(qtd_elem, grupo, result);
            }
            else if(opcao == 9){
                bot=0;
                menu();
            }
             else if(opcao == 0){
                bot=0;
                exit(0);
            }
            else{
                bot=1;
                printf("\nDigite uma das opcoes acima: ");
            }
        }

}


/*

Foi testado varios metodos para fazer a impressao dos subconjuntos, porem nenhum deles deu certo.

Fiquei dias tentando e o maximo que conseguir foi imprimir conjuntos forcados: sabendo que seria C(5,3), faria o codigo funcionar nesse tipo de parametros,
mas para deixar dinamizado, houve varios problemas e entao resolvi deixar sem essa parte, pois estava gerando muitos erros de execucao.

Deixei o escopo que comecei para fazer as impressoes dos subconjuntos de combinacao.

*/


void imprimir_combinacao(char tipo[5], int qtd_elem, int grupo, int result){

   /*printf("\n\nIMPRESSAO DOS SUBCONJUNTOS:\n");

    if(strcmp(tipo, "nrep") == 0){

        int i, j, k, x, count=0, *myvet;
        char alfab[27] = "abcdefghijklmnopqrstuvxwyz";
        printf("\nDesculpe! A impressao dos subconjuntos nao ficou concluida a tempo.\n");


        for(i=0; i<result; i++){ //para cada resultado (subconjunto)
            for(j=0; j<grupo; j++){ // crio j elementos tal que j eh menor q o numero de elementos que o subconjunto possui
                // code
            }
        }
    


    else{
        printf("\nA impressao dos subconjuntos nao ficou concluida a tempo...");
    }*/

}

void imprimir_permutacao(char tipo[5], int qtd_elem, int grupo, int result){
   // printf("\n\nIMPRESSAO DOS SUBCONJUNTOS:\n");
    //printf("\nDesculpe! A impressao dos subconjuntos nao ficou concluida a tempo.\n");
}

void imprimir_pombo(int qtd_elem, int grupo, int result){
    //printf("\n\nIMPRESSAO DOS SUBCONJUNTOS:\n");
    //printf("\nDesculpe! A impressao dos subconjuntos nao ficou concluida a tempo.\n");
}



int main(){
    menu();
    return 0;
}
