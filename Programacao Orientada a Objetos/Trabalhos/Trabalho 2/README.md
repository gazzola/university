# TRABALHO 1 - PROGRAMACAO ORIENTADA A OBJETOS
# MARCOS TREVISO - 121150107

# ARQUIVO PARA EXECUTAR: LoginWindow
# .class NA PASTA bin/
# DIAGRAMA DE CLASSES NA PASTA diagrama/ (xmi|png)

# USER: mark | jose
# PASS: mark | jose
# EM CASO DE DUVIDAS, ABRIR ARQUIVO LoginWindow.java
# NO METODO main ESTA VISIVEL AS ACOES TOMADAS.



INICIAR APLICACAO:
$ cd bin/
$ java LoginWindow


COMPILAR APLICACAO:
javac -d pasta *.java 		#no diretorio chamado pasta
javac *.java 				#no diretorio atual


USANDO MAKEFILE: 			#EM LINUX
make 						#compilar tudo
make run 					#rodar
make clean 					#limpar


USANDO MAKEFILE: 			#EM WINDOWS
cd C:/MinGW/mingw32-make	#mudar pasta e usar passos anteriores
nmake -f makefile			#no cmd do visual studio
