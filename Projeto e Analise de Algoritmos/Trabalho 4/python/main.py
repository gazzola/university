import os, sys, time
from musiclist import MusicList

#SET DEFAULT TIMER
if sys.platform == 'win32':
    default_timer = time.clock
else:
    default_timer = time.time



#SET INTERPRETE AND FILENAME
filename = "colecao01.txt"
if(len(sys.argv) >= 2):
	filename = sys.argv[1]



#START CRONO TIME
start_time = default_timer()


#CREATE OBJECT AND EXECUTE METHODS
listam = MusicList("../colecoes/"+filename, 10**3) #in KB
musicas = listam.getMusics()
#listam.showMusics(musicas)

resultado = listam.selectMusics(musicas)
timeguloso = default_timer() - start_time



#GET THE DEPENDENCIES
start_time = default_timer()

qtdElementos = listam.getAmmount()
tamMochila = listam.getMaxSize()
pesos = listam.getWeight()
valores = listam.getRank()


#resultado2 = listam.binaryKnapsack(qtdElementos, pesos, valores, tamMochila)
resultado2 = listam.binaryKnapsackOptimized(qtdElementos, pesos, valores, tamMochila)
timeprodg = default_timer() - start_time - timeguloso



#PRINT RESULT AND EXECUTION TIME
print("RESULTADO ALG. GULOSO:", resultado)
print("TEMPO ALG. GULOSO:"+str(timeguloso),  "s")
print(30*"-")
print("RESULTADO ALG. PROG.D:", resultado2)
print("TEMPO ALG. PROG.D:"+str(timeprodg), "s\n")