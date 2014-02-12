#include <stdio.h>

int main(){

    float imc, kg, alt;

    printf("Digite seu peso(kg) e sua altura(m): ");
    scanf("%f %f", &kg, &alt);

    imc = kg/(alt*alt);

    if(imc < 18.5)
        printf("IMC = %f : Abaixo do peso ideal", imc);
    else if(imc >= 18.5 && imc < 25)
        printf("IMC = %f : Peso ideal", imc);
    else if(imc >= 25 && imc < 30)
        printf("IMC = %f : Acima do peso ideal", imc);
    else
        printf("IMC = %f : Obesidade", imc);


    return 0;
}
