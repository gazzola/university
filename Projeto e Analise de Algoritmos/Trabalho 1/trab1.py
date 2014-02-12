import os, sys, time
from listademusicas import ListaDeMusicas

#SET DEFAULT TIMER
if sys.platform == 'win32':
    default_timer = time.clock
else:
    default_timer = time.time

start_time = default_timer()



#CREATE OBJECT AND EXECUTE METHODS
listam = ListaDeMusicas(sys.argv[1])

musicas = listam.getMusicas()
#listam.exibeMusicas(musicas)
resultado = listam.selecionaMusicas(musicas)



#PRINT RESULT AND EXECUTION TIME
print "RESULTADO:", resultado
print default_timer() - start_time, "s"