Trabalho Final - Programacao Orientada a Objetos
======================================================
MARCOS TREVISO - 121150107

ARQUIVO PARA EXECUTAR: LoginWindow<br>
.class NA PASTA bin/<br>
DIAGRAMA DE CLASSES NA PASTA diagrama/ (xmi|png)

USER: mark | jose<br>
PASS: mark | jose<br>
EM CASO DE DUVIDAS, ABRIR ARQUIVO LoginWindow.java<br>
NO METODO main ESTA VISIVEL AS ACOES TOMADAS.



Iniciar Aplicacao:
--------------
$ cd bin/<br>
$ java LoginWindow


Compilar Aplicacao:
--------------
javac -d pasta *.java 		#no diretorio chamado pasta<br>
javac *.java 			      	#no diretorio atual


Usando Makefile em Linux:
--------------
make 					    	      #compilar tudo<br>
make run 			          	#rodar<br>
make clean 		      	    #limpar


Usando Makefile em Windows:
--------------
cd C:/MinGW/mingw32-make	#mudar pasta e usar passos anteriores
<br>
nmake -f makefile			    #no cmd do visual studio


Novas Alteracoes:
--------------
Excecoes criadas: EmptyField | NegativeNumber | SupporterAlreadyRegistered.<br>
output.out eh o arquivo de saida de texto, o arquivo de saida pode ser alterado no arquivo SupporterWindowReport.java<br>
output_object.bin  eh o arquivo de saida de objeto, o arquivo de saida pode ser alterado no arquivo SupporterWindowReport.java<br>
system.log eh o arquivo de log do sistema, mais informacoes em SystemLog.java<br>

Observacao importante: Quando o arquivo output_object.bin esta vazio, ao tentar ler seu conteudo, vai gerar uma excecao do arquivo dizendo que nao encontrou um objeto (IOException), e outra excecao dizendo que o arquivo esta vazio (NullPointerException). No arquivo ReadObjectFile, comentei um possivel solucao para nao mostrar os 'erros', porem como o trabalho sugere que eh para captar todas possiveis excecoes, deixei inalterado.


Padroes utilizados:
--------------
Abstract Facotry
Dependency Injection
Singleton
Registry