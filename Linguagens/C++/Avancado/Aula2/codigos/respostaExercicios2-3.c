/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicios2-3.c - Resposta ao segundo e ao terceiro exercícios da segunda aula
 */


int mystrlen(char *s) {
	int i;

	for (i = 0; s[i]; i++);

	return i;
}

void mystrcpy(char * dest, char *ori) {
	int i;

	for (i = 0; ori[i]; i++) {
		dest[i] = ori[i];
	}

	dest[i] = '\0'; // importante!!!
}

void mystrcat(char * dest, char *ori) {
	int i, j = 0;

	// Uma maneira inteligente de fazer:
	for (i = mystrlen(dest); ori[j]; i++) {
		dest[i] = ori[j];
		j++;
	}

	dest[i] = '\0'; // importante!!!

	// Uma maneira mais SUPER inteligente de fazer:
	// mystrcpy(dest + mystrlen(dest), ori);
}

int mystrchar(char *str, char c) {
	int i;

	for (i = 0; str[i]; i++) {
		if (str[i] == c) {
			return i;
		}
	}

	return i;
}

int main (int argc, char *argv[]) {
	char *s = "UFPE";
	char dest[10];
	int a = 10, b = 15;
	int (*f) (char *, char);

	printf("%d\n", mystrlen("EU"));
	printf("%d\n", mystrlen("ELE"));
	printf("%d\n", mystrlen("ELES"));

	mystrcpy(dest, s);
	printf("%s\n", dest);
	mystrcpy(dest, "CIn");
	printf("%s\n", dest);
	mystrcat(dest, "-UFPE");
	printf("%s\n", dest);


	printf("%d \n", mystrchar(dest, 'U'));

	f = mystrchar;
	printf("%d \n", (*f) (dest, 'C'));
}
