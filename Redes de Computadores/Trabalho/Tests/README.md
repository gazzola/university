INSTRUCOES
===========

Para o consumo de energia:
time ./testar.sh NUM_EXECUCOES

Para testar apenas o tempo de execucao:
./run ARQUIVO_TESTE.cpp PASTA_ARQS_SAIDA




BATERIA
===========
Voltagem: 10.8V
Corrente-h: 5000mAh
Potencia-h: 10.8*5 = 54 watts-hora


estimativa por bateria:
-----------------------
1 -> Tempo de Execucao (s) = Tempo Total/Qtd de execs

2 -> Consumo de bateria por exec = Consumo total da bateria(Ah)/Qtd de execs

3 -> Corrente Media = Energia consumida (Ah) / Tempo de execucao(h)

4 -> Potencia Media = Corrente media * Voltagem da bateria

5 -> Consumo(J) = Potencia media * Tempo de execucao(s)




PROCESSADOR
===========
CLock: 2.20GHz
Voltagem: 1.74 V
Corrent: 40 A


estimativa por processador:
---------------------------
1 -> Tempo de Execucao (s) = num de ciclos/veloc do proc(ciclos/s) 
					ou cronometrar o tempo

2 -> Corrente Media = Energia consumida (Ah) / Tempo de execucao(h)

3 -> Potencia do Proc = Voltagem * Corrente(A) [ou corrente media para mais precisao]

4 -> Consumo(J) = Potencia do proc * Tempo de exec



