/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploClienteTCP.cpp - Exemplo de um simples cliente TCP sobre a API do windows
 */

#include <cstdio>
#include <winsock.h>

int main() {
	
	WSADATA wsInformacao;

	// inicializa Winsock
	int iResult = WSAStartup(MAKEWORD(2,2), &wsInformacao);
	if (iResult != NO_ERROR) {
		printf("Erro na chadama da funcao WSAStartup()\n");
	}

	// cria socket que irá se conectar ao servidor
	SOCKET socketCliente;

	socketCliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (socketCliente == INVALID_SOCKET) {
		printf("Erro na chadama da funcao socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 0;
	}

	
	// se conecta ao servidor
	sockaddr_in cliente;

	cliente.sin_family = AF_INET;
	cliente.sin_addr.s_addr = inet_addr("127.0.0.1");
	cliente.sin_port = htons(27015);

	if (connect(socketCliente, (SOCKADDR*) &cliente, sizeof(cliente)) == SOCKET_ERROR) {
        printf("Erro na chadama da funcao connect().\n");
        WSACleanup();
        return 0;
    }

	send(socketCliente, "Fulano", 6, 0);

	char bufferEntrada[101];
	int bytes = recv(socketCliente, bufferEntrada, 100, 0);
	bufferEntrada[bytes] = '\0';
	printf("Resposta: %s\n", bufferEntrada);

	return 0;
}
