/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploClienteUDP.cpp - Exemplo de um simples cliente UDP sobre a API do windows
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

	socketCliente = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (socketCliente == INVALID_SOCKET) {
		printf("Erro na chadama da funcao socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 0;
	}

	
	// se conecta ao servidor
	sockaddr_in servidor;
	int tamamnhoEndereco = sizeof(servidor);

	servidor.sin_family = AF_INET;
	servidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	servidor.sin_port = htons(27015);

	sendto(socketCliente, "Fulano", 6, 0, (sockaddr *) &servidor, tamamnhoEndereco);

	char bufferEntrada[101];
	int bytes = recvfrom(socketCliente, bufferEntrada, 100, 0, (sockaddr *) &servidor, &tamamnhoEndereco);
	bufferEntrada[bytes] = '\0';
	printf("%s\n", bufferEntrada);

	return 0;
}
