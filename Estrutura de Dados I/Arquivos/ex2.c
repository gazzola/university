#include <stdio.h>

int main(int argc, char *argv[]){

FILE *myarquivo, *mycopia;
char texto;

    if(argc < 2){
        printf("Por favor, informe o nome de arquivo que deseja ler como parametro do programa.");
        return 1;
    }
    if(argc < 3){
        printf("Por favor, informe o nome de arquivo onde deseja realizar a copia como parametro do programa.");
        return 1;
    }

    myarquivo = fopen(argv[1], "r");
    mycopia = fopen(argv[2], "w");

    if(myarquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    else if(mycopia == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    else{
        while(!feof(myarquivo)){
            fscanf(myarquivo, "%c", &texto);
            fprintf(mycopia, "%c", texto);
        }
    }

    fclose(myarquivo);

    return 0;
}
