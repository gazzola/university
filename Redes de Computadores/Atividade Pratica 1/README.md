# Atividade Prática 1 - Redes de Computadores

* Etapa 1: O servidor aceita conexões de dois ou mais clientes. Nesta etapa, o servidor
processa apenas uma tarefa por vez, não havendo paralelismo na execução de tarefas.
Execute ao menos dois clientes, lendo através do teclado a mensagem a ser enviada.
No servidor, exiba as mensagens enviadas pelos clientes. Ex.: “Cliente 1: msg 1”,
“Cliente 2: msg 1”, etc.

* Etapa 2: O servidor pode manipular tarefas oriundas de vários clientes
simultaneamente, ou seja, em paralelo. Execute ao menos dois clientes, usando
mensagens pré-definidas e enviando-as ao servidor intermitentemente. Tais mensagens
devem seguir o padrão Cliente <n. do cliente>: msg <n. da mensagem>. Incremente o
número da mensagem a cada mensagem enviada. No servidor, exiba as mensagens
enviadas pelos clientes à medida que elas forem chegando. Exiba a data e a hora de
chegada dessas mensagens.

* Etapa 3: Calcule e apresente, no servidor, o atraso fim a fim para cada mensagem
enviada ao servidor.


## Integrantes:

* Marcos Vinícius Treviso (121150107)
* Matheus Beniz Bieger (131100019)


## Execução:
	
Rodar servidor primeiro.
```bash
java Server <porta>
```

Rodar clientes.
```bash
java Client <porta>
```