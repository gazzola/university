#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct habitante{
    char nome[100];
    int idade;
    char sexo;
    float salario;
    int filhos;
};

void le_habitantes(int n, struct habitante *h){
    int i;
    for(i = 0; i<n; i++){
        printf("\nInforme o nome do %d habitante: ", i+1);
        scanf("%s", h[i].nome);

        printf("\nInforme a idade: ");
        scanf("%d", &h[i].idade);

        printf("\nInforme o sexo: ");
        scanf("%c", &h[i].sexo);

        printf("\nInforme o salario: ");
        scanf("%f", &h[i].salario);

        printf("\nInforme o numero de filhos: ");
        scanf("%d", &h[i].filhos);
    }
}


float calcula_media_salarios(int n, struct habitante *h){
    int i, soma=0;
    float media;
    for(i = 0; i<n; i++){
        soma+= h[i].salario;
    }
    media = soma/n;
    return media;
}


float calcula_media_filhos(int n, struct habitante *h){
    int i, soma=0;
    float media;
    for(i = 0; i<n; i++){
        soma+= h[i].filhos;
    }
    media = soma/n;
    return media;
}


void imprime_salario_inferior(int n, struct habitante *h, float media){
    int i;
    printf("\n\nLista dos habitante com salario inferior a media (%.2f):\n", media);
    for(i = 0; i<n; i++){
        if(h[i].salario < media)
        printf("Nome: %s Salario: %.2f\n", h[i].nome,
        h[i].salario);
    }
}


void imprime_filhos_superior(int n, struct habitante *h, float media){
    int i;
    printf("\n\nLista dos habitante com numero de filhos superior a media (%.2f):\n", media);
    for(i = 0; i<n; i++){
        if(h[i].filhos > media)
        printf("Nome: %s Numero de filhos: %d\n", h[i].nome,
        h[i].filhos);
    }
}


int main(){

    float media_salarios, media_filhos;
    struct habitante *h;
    int n;

    printf("informe o numero de habitantes: ");
    fflush(stdin);
    scanf("%d", &n);

    h = (struct habitante *)malloc(n * sizeof(struct habitante));
    le_habitantes(n, h);

    media_salarios = calcula_media_salarios(n, h);
    media_filhos = calcula_media_filhos(n, h);

    imprime_salario_inferior(n, h, media_salarios);
    imprime_filhos_superior(n, h, media_filhos);
    

    return 0;

}
