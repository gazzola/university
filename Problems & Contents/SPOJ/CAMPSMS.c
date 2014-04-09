#include <stdio.h>
#include <string.h>

int mesmaTecla(char tecla, char ult_tecla){

    if((tecla == 'a' || tecla == 'b' || tecla == 'c' || tecla == '2') && (ult_tecla == 'a' || ult_tecla == 'b' || ult_tecla == 'c' || ult_tecla == '2'))
        return 1;
    else if((tecla == 'd' || tecla == 'e' || tecla == 'f' || tecla == '3') && (ult_tecla == 'd' || ult_tecla == 'e' || ult_tecla == 'f' || ult_tecla == '3'))
        return 1;
    else if((tecla == 'g' || tecla == 'h' || tecla == 'i' || tecla == '4') && (ult_tecla == 'g' || ult_tecla == 'h' || ult_tecla == 'i' || ult_tecla == '4'))
        return 1;
    else if((tecla == 'j' || tecla == 'k' || tecla == 'l' || tecla == '5') && (ult_tecla == 'j' || ult_tecla == 'k' || ult_tecla == 'l' || ult_tecla == '5'))
        return 1;
    else if((tecla == 'm' || tecla == 'n' || tecla == 'o' || tecla == '6') && (ult_tecla == 'm' || ult_tecla == 'o' || ult_tecla == 'p' || ult_tecla == '6'))
        return 1;
    else if((tecla == 'p' || tecla == 'q' || tecla == 'r' || tecla == 's' || tecla == '7') && (ult_tecla == 'p' || ult_tecla == 'q' || ult_tecla == 'r' || ult_tecla == 's' || ult_tecla == '7'))
        return 1;
    else if((tecla == 't' || tecla == 'u' || tecla == 'v' || tecla == '8') && (ult_tecla == 't' || ult_tecla == 'u' || ult_tecla == 'v' || ult_tecla == '8'))
        return 1;
    else if((tecla == 'w' || tecla == 'x' || tecla == 'y' || tecla == 'z' || tecla == '9') && (ult_tecla == 'w' || ult_tecla == 'x' || ult_tecla == 'y' || ult_tecla == 'z' || ult_tecla == '9'))
        return 1;

    return 0;

}


int main(){

char str[141], ult;
char abc[5] = "abc2";
char def[5] = "def3";
char ghi[5] = "ghi4";
char jkl[5] = "jkl5";
char mno[5] = "mno6";
char pqrs[6] = "pqrs7";
char tuv[5] = "tuv8";
char xwyz[6] = "xwyz9";

float tempo = 0.20;
int len, i;

while(scanf("%s", str) != EOF){
    len = strlen(str);

    for(i=0; i<len; i++){
        if(i!=0){

            if(mesmaTecla(str[i], ult)){

                int k, x;
                for(k=0; k<5; k++){
                    if(str[i] == abc[k] || str[i] == def[k] || str[i] == ghi[k] || str[i] == jkl[k] || str[i] == mno[k] || str[i] == pqrs[k] || str[i] == tuv[k] || str[i] == xwyz[k]){
                        x=k+1;
                        break;
                    }
                    if(str[i] == pqrs[5] || str[i] == xwyz[5]){
                        x=5;
                        break;
                    }
                }

                tempo = tempo+(x*0.20);

            }
            else{
                tempo = tempo+0.20;
            }


        }
        ult=str[i];
    }

    printf("%.2f\n", tempo);

}

return 0;
}
