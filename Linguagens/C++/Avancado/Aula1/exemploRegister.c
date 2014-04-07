/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Inform�tica - CIn
 * Centro Integrado de Tecnologia da Informa��o - CITi
 * Centro de Estudos e Sistemas Avan�ados do Recife - CESAR
 * Curso de C/C++ Avan�ado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploRegister.c - Mostra um exemplo de como utilizar a palavra reservada register
 *                     na declara��o de vari�veis.
 */

int main() {
	register int i; // i pode n�o ser alocada em um registrador

	for (i = 0; i < 10; i = i + 1) {
		// c�digo
	}

	return 0;
}
