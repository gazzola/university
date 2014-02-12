#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *myarquivo;
    char texto; int result=0;

    if(argc < 2){
        printf("Por favor, informe o nome de arquivo que deseja ler como parametro do programa.");
        return 1;
    }

    myarquivo = fopen(argv[1], "r");

    if(myarquivo == NULL){
        printf("Nenhum arquivo encontrado. ");
        return 1;
    }
    else{
        while(!feof(myarquivo)){

            fscanf(myarquivo, "%d", &texto);

            if(texto != ' '){
                result += texto;
            }
            else{

            }

        }

        printf("Valor total: %d", result);
    }

    fclose(myarquivo);

    return 0;
}
