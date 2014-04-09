/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploClienteTCP.cpp - Exemplo de um simples servidor TCP sobre a API do windows
 */

#include <cstring>
#include <cstdio>
#include <winsock.h>

int main() {
	WSADATA wsInformacao;

	// inicializa Winsock
	int iResult = WSAStartup(MAKEWORD(2,2), &wsInformacao);
	if (iResult != NO_ERROR) {
		printf("Erro na chamada da funcao WSAStartup().\n");
	}

	// cria o servidor
	SOCKET socketServidor;
	
	socketServidor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (socketServidor == INVALID_SOCKET) {
		printf("Erro na chamada da funcao socket(): %ld.\n", WSAGetLastError());
		WSACleanup();
		return 0;
	}


	// asocia a uma porta o servidor
	sockaddr_in service;

	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27015);

	if (bind(socketServidor, (SOCKADDR*) &service, sizeof(service)) == SOCKET_ERROR ) {
		printf("Erro na chamada da funcao bind().\n");
		closesocket(socketServidor);
	    return 0;
	}

	// configura a fila de conexões
	if (listen(socketServidor, 1) == SOCKET_ERROR) {
		printf("Erro na chamada da funcao listen().\n");
	}


	SOCKET socketCliente;

	printf("Aguardando conexoes...\n");
	while (1) {	
		socketCliente = SOCKET_ERROR;
		if ((socketCliente = accept(socketServidor, NULL, NULL)) == SOCKET_ERROR) {
			continue;		
		}


		printf("Cliente Conectado.\n");

		char bufferEntrada[101];
		int bytes = recv(socketCliente, bufferEntrada, 100, 0);
		bufferEntrada[bytes] = '\0';
		printf("Dados Recebidos: %s\n", bufferEntrada);

		char bufferSaida[101];
		sprintf(bufferSaida, "Ola %s!", bufferEntrada);

		send(socketCliente, bufferSaida, strlen(bufferSaida), 0);

		closesocket(socketCliente);
	}

	return 0;
}
