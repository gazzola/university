#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct habitante{

    char nome[50];
    int idade;
    char sexo[15];
    float salario;
    int numfilhos;

};

void LeEstrutura(int tam, struct habitante *vh){
    int i;

    for(i=0; i<tam; i++){
        printf("\n");
        printf("%d HABITANTE: Digite um nome, idade, sexo, salario e numero de filhos: \n", i+1);
        scanf("%s %d %s %f %d", vh[i].nome, &vh[i].idade, vh[i].sexo, &vh[i].salario, &vh[i].numfilhos);
    }

}

void CalcMedia(int tam, struct habitante *vh, float *sal, int *numf){
    int i;
    for(i=0; i<tam; i++){
        *numf = *numf+vh[i].numfilhos;
        *sal = *sal+vh[i].salario;
    }

    *numf = *numf/tam;
    *sal = *sal/tam;

}

void ListaHabitantes(int tam, struct habitante *vh, float *sal, int *numf){
    int j, error=0;

    for(j=0; j<tam; j++){ 
        if(vh[j].salario < *sal && vh[j].numfilhos > *numf ){
            printf("\nnome: %s", vh[j].nome);
            printf("\nidade: %d", vh[j].idade);
            printf("\nsexo: %s", vh[j].sexo);
            printf("\nsalario: %f", vh[j].salario);
            printf("\nnumfilhos: %d\n", vh[j].numfilhos);
        }
        else
            error++;
     }

     if(error == tam)
        printf("Nenhum habitante relacionado.\n");

}

int main(){

    struct habitante *myhabit;

    int n, numf=0;
    float sal=0.0;

    printf("Digite um numero de habitantes: ");
    scanf("%d", &n);

    myhabit = (struct habitante *)malloc(n * sizeof(struct habitante));

    LeEstrutura(n, myhabit);
    CalcMedia(n, myhabit, &sal, &numf);
    ListaHabitantes(n, myhabit, &sal, &numf);

    return 0;
}
