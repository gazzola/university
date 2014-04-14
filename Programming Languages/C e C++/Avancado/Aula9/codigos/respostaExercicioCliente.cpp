/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * respostaExercicioCliente.cpp - Resposta ao único exercício da nona aula
 */

#include <cstdio>
#include <cstdlib>
#include <winsock.h>

int main() {
	char *nomeArquivo = "Projeto.rar";
	
	WSADATA wsInformacao;

	int iResult = WSAStartup(MAKEWORD(2,2), &wsInformacao);
	if (iResult != NO_ERROR) {
		printf("Erro na chadama da funcao WSAStartup()\n");
	}

	SOCKET socketCliente;

	socketCliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (socketCliente == INVALID_SOCKET) {
		printf("Erro na chadama da funcao socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 0;
	}

	sockaddr_in cliente;

	cliente.sin_family = AF_INET;
	cliente.sin_addr.s_addr = inet_addr("127.0.0.1");
	cliente.sin_port = htons(27015);

	if (connect(socketCliente, (SOCKADDR*) &cliente, sizeof(cliente)) == SOCKET_ERROR) {
        printf("Erro na chadama da funcao connect().\n");
        WSACleanup();
        return 0;
    }

	send(socketCliente, nomeArquivo, strlen(nomeArquivo), 0);

	char bufferEntrada[1024];
	int bytes;
	int total = 0;
	
	bytes = recv(socketCliente, bufferEntrada, 1, 0);
	
	if (bufferEntrada[0] == '&') {
		printf("Arquivo inexistente\n");
		return 0;
	}

	FILE *arq = fopen(nomeArquivo, "wb");
	while ((bytes = recv(socketCliente, bufferEntrada, 1024, 0))) {
		fwrite(bufferEntrada, sizeof(char), bytes, arq);
		total = total + bytes;
	}

	printf("Total de bytes recebidos: %d\n", total);

	fclose(arq);
	strcpy(bufferEntrada, "start ");
	strcat(bufferEntrada, nomeArquivo);

	system(bufferEntrada);

	return 0;
}
