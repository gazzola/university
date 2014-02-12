COMPILADOR=gcc
FILENAME=CIPO

compilar:
	${COMPILADOR} -o ${FILENAME} ${FILENAME}.c
executar: ${FILENAME}
	./${FILENAME} < FILENAME.txt
apagar:
	rm ${FILENAME}
	clear