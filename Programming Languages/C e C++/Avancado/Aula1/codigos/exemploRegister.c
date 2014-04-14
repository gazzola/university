/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploRegister.c - Mostra um exemplo de como utilizar a palavra reservada register
 *                     na declaração de variáveis.
 */

int main() {
	register int i; // i pode não ser alocada em um registrador

	for (i = 0; i < 10; i = i + 1) {
		// código
	}

	return 0;
}
