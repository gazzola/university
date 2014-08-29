"""
UNIPAMPA - Máquina de Turing na unha
Linguagens Formais - Fabio N. Kepler

Matheus S. Serpa - 121151631
matheusserpa@gmail.com
"""

import sys
import os

def le_strings(arquivo):
    f = open(arquivo,'r')
    strings = []

    for str in f:
        strings.append(str.strip()) # Limpa eventuais espacos em branco no comeco e no fim
    f.close()

    return strings


def le_mturing(arquivo):
    f = open(arquivo, 'r')
    mturing = {}

    mturing["nome"] = f.readline().strip()
    mturing["transicao"] = {}
    estados = f.readline().replace('(','').replace(')','').replace(' ','').strip().split(',')

    for estado in estados:
    	mturing["transicao"][estado] = {}


    mturing["inicial"] = f.readline().replace('(','').replace(')','').replace(' ','').strip()
    mturing["final"] = f.readline().replace('(','').replace(')','').replace(' ','').strip().split(',')

    for str in f:
    	estado, leitura_fita, proximo_estado, escrita_fita, direcao_fita = str.replace('(','').replace(')','').replace('=', ',').replace(' ','').strip().split(',')

    	mturing["transicao"][estado][leitura_fita] = {}
    	mturing["transicao"][estado][leitura_fita]["proximo_estado"] = proximo_estado
    	mturing["transicao"][estado][leitura_fita]["escrita_fita"] = escrita_fita
    	if(direcao_fita == 'D'):
    		mturing["transicao"][estado][leitura_fita]["direcao_fita"] = +1
    	elif(direcao_fita == 'E'):
    		mturing["transicao"][estado][leitura_fita]["direcao_fita"] = -1
    	else:
    		mturing["transicao"][estado][leitura_fita]["direcao_fita"] = 0

    f.close()

    return mturing

def executa_mturing(mturing, string):
	fita = list(string)
	fita.append('B')

	q = mturing["inicial"]
	pos = 0

	while True:
		# Gambs - Inicio
		if(pos == len(fita) and q in mturing["final"]):
			situacao = 'Aceita'
			break
		elif(pos == len(fita) and q not in mturing["final"]):
			situacao = 'Rejeita'
			break
		elif((fita[0] == 'B' and len(fita) == 1) or (pos != -1 and fita[pos] == 'B' and not 'B' in mturing["transicao"][q])):
			if(q in mturing["final"]):
				situacao = 'Aceita'
			else:
				situacao = 'Rejeita'
			break

		if q not in mturing["transicao"] or (pos != -1 and fita[pos] not in mturing["transicao"][q]):
			situacao = 'Rejeita'
			break
		# Gambs - Fim

		if(pos == -1):
			q = mturing["transicao"][q]["<"]["proximo_estado"]
			pos = 0
		else:
			pos_anterior = pos
			q_anterior = q

			q = mturing["transicao"][q][fita[pos_anterior]]["proximo_estado"]
			pos = pos_anterior + mturing["transicao"][q_anterior][fita[pos_anterior]]["direcao_fita"]

			if(mturing["transicao"][q_anterior][fita[pos_anterior]]["escrita_fita"] == 'B' and pos_anterior != (len(fita) - 1)):
				del(fita[pos_anterior])
			else:
				fita[pos_anterior] = mturing["transicao"][q_anterior][fita[pos_anterior]]["escrita_fita"]
		
		

	del(fita[-1])

	return [''.join(fita), situacao]

def main(arquivo_mturing, arquivo_strings):
    mturing = le_mturing(arquivo_mturing)
    strings = le_strings(arquivo_strings)

    print("Máquina de Turing:", mturing["nome"], "\n")

    for string in strings:
    	print('String: ', string)
    	print('Saída: ', executa_mturing(mturing, string), '\n')
    	
        


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print('Use: python3 {} ARQUIVO_MAQUINA_TURING ARQUIVO_STRINGS'.format(os.path.basename(sys.argv[0])))
        exit()
    main(sys.argv[1], sys.argv[2])
