#include <stdio.h>
#include <stdlib.h>


int main(){

	int ammount=0, i;
	float *values;
	char **names, l;


	//open file
	FILE *f = fopen("alnotas", "r");
	
	if(f == NULL){
		printf("Erro ao abrir o arquivo");
		return 1;
	}


	//get the ammount of content
	fscanf(f, "%d", &ammount);
	

	//allocate names and values
	names = (char**) malloc (ammount * sizeof(char*));
	values = (float*) malloc (ammount * sizeof(float));


	//get the values
	for(i=0; i<ammount; i++){
		names[i] = (char*) malloc (25 * sizeof(char));
		fscanf(f, "%c", &l); //skip \n
		fscanf(f, "%[^\n]", names[i]);
		fscanf(f, "%f", &values[i]);
	}


	//close the file
	fclose(f);


	//show the result in tabulate form
	for(i=0; i<ammount; i++){
		printf("%-20s %.2f\n", names[i], values[i]);
		free(names[i]);
	}


	//free memory
	free(names);
	free(values);

	return 0;
}