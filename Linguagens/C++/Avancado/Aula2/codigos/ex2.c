#include <stdio.h>


int mystrlen(char *c){
	int count=0;

	while(c[count] != '\0')
		count++;

	return count;
}

void mystrcpy(char *dest, char *orig){
	
	int count=0, size=mystrlen(orig);

	while(count < size){
		orig[count] = dest[count];
		count++;
	}

	orig[count] = '\0';
}

void mystrcat(char * dest, char *ori) {
	int i, j = 0;

	for(i=mystrlen(dest); ori[j]; i++){
		dest[i] = ori[j];
		j++;
	}

	dest[i] = '\0';

	// mystrcpy(dest + mystrlen(dest), ori);
}

int mystrchar(char *str, char c) {
	int i;

	for(i=0; str[i]; i++)
		if(str[i] == c)
			return i;

	return i;
}



int main(){
	
	printf("%d\n", mystrlen("JESUS"));

	return 0;
}