# run: $INTERPRETER main.py $FILENAME $ALGORITHM_TYPE
# $INTERPRETER = {python, python3, pypy}
# $FILENAME = {colecao01.txt} in ../colecoes/
# $ALGORITHM_TYPE = {guloso, pdinamica}

import os, sys, time
from musiclist import MusicList

#SET DEFAULT TIMER
if sys.platform == 'win32':
    default_timer = time.clock
else:
    default_timer = time.time



#SET FILENAME AND TYPE OF ALGORITHM
filename = "colecao01.txt"
algtype = "guloso"
if(len(sys.argv) >= 2):
	filename = sys.argv[1]
	algtype = sys.argv[2]



#START CRONO TIME
start_time = default_timer()


#CREATE OBJECT
listam = MusicList("../colecoes/"+filename, 10**3) #in KB


if(algtype == "guloso"):

	#EXECUTE METHODS
	musicas = listam.getMusics()
	#listam.showMusics(musicas)
	resultado = listam.selectMusics(musicas)

else:

	#GET THE DEPENDENCIES
	qtdElementos = listam.getAmmount()
	tamMochila = listam.getMaxSize()
	pesos = listam.getWeight()
	valores = listam.getRank()

	#resultado = listam.binaryKnapsack(qtdElementos, pesos, valores, tamMochila)
	resultado = listam.binaryKnapsackOptimized(qtdElementos, pesos, valores, tamMochila)



tempo = default_timer() - start_time



#PRINT RESULT AND EXECUTION TIME
print("ALGORITMO:", algtype)
print("RESULTADO:", resultado)
print("TEMPO ALG:", str(tempo)+"s")
print(50*"-")