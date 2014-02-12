/*
* Ordenar 3 valores com 3 ponteiros
*/

#include <stdio.h>

void ordena3(int *maior, int *medio, int *menor){

    int men, mai, med;

    if(*maior < *menor && *maior < *medio){
        men = *maior;
        if(*medio>*menor){
            mai = *medio;
            med = *menor;
        }else{
            mai = *menor;
            med = *medio;
        }
    }
    else if(*medio < *menor && *medio < *maior){
        men = *medio;
        if(*maior>*menor){
            mai = *maior;
            med = *menor;
        }else{
            mai = *menor;
            med = *maior;
        }
    }
    else{
        men = *menor;
        if(*maior>*medio){
            mai = *maior;
            med = *medio;
        }else{
            mai = *medio;
            med = *maior;
        }
    }

    printf("Menor:%d\nMedio:%d\nMaior:%d\n", men, med, mai);

}


int main(){
    
    int a, b, c;
    printf("Digite 3 valores quaisquer para serem ordenados: ");
    scanf("%d %d %d", &a, &b, &c);

    ordena3(&a, &b, &c);

    return 0;

}
