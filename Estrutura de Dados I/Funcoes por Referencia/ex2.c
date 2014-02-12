#include <stdio.h>
#include <string.h>

void inverteString(char *str){
    int i, tamstr, x=0;
    char newstr[25];

    tamstr = strlen(str);
    printf("tam:%d\n", tamstr);

    for(i=tamstr-1; i>=0; i--){
        newstr[x] = str[i];
        x++;
    }
    newstr[x] = '\0';

    printf("%s\n", newstr);

}

int main(){

    char mystr[25];
    printf("Digite uma palavra qualquer: ");
    scanf("%s", mystr);

    inverteString(mystr);

    return 0;
}
