#include <stdio.h>
#include <string.h>


int bigger(int a, int b){
	return (a > b) ? a : b;
}

int smaller(int a, int b){
	return (a < b) ? a : b;
}

int isEven(int *a){
	return !((*a) & 1);
}


int main(){
	
	char currentStr[10], lastStr[10]="", totalStr[3000]="";
	int minLenght, maxLenght=0, count=0;

	printf("Digite duas string quaisquer [parar = 2 str iguais]:\n");
	scanf("%s", currentStr);
	strcat(totalStr, currentStr);
	minLenght = strlen(currentStr);
	
	while(strcmp(currentStr, lastStr) != 0){
		
		strcpy(lastStr, currentStr);
		scanf("%s", currentStr);
		strcat(totalStr, currentStr);
	
		minLenght = smaller(strlen(currentStr), minLenght);
		maxLenght = bigger(strlen(currentStr), maxLenght);

		if(isEven(&count))
			printf("----------------------\n");

		count++;
	}

	printf("\n----------------------\n");
	printf("STRCAT: %s\n", totalStr);
	printf("MINLEN: %d\n", minLenght);
	printf("MAXLEN: %d\n", maxLenght);

	return 0;
}