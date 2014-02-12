#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *myarquivo;
    char texto;
    char nome[50], telefone[50];

    if(argc < 2){
        printf("Por favor, informe o nome de arquivo que deseja ler como parametro do programa.");
        return 1;
    }

    myarquivo = fopen(argv[1], "a+");

    if(myarquivo == NULL){
        printf("Nenhum arquivo encontrado. ");
        return 1;
    }
    else{

        do{
            printf("Digite um Nome ou Digite $ para finalizar: ");
            gets(nome);

            if(nome[0] != '$'){
                printf("Digite um Telefone ou Digite $ para finalizar: ");
                gets(telefone);

                if(telefone[0] != '$'){
                    fprintf(myarquivo, "Nome:%s Telefone:%s \n", nome, telefone);
                }
            }

        }while(nome[0] != '$' && telefone[0] != '$');


    }

    fclose(myarquivo);
    printf("\nArquivo %s salvo com sucesso.\n", argv[1]);


    return 0;
}
