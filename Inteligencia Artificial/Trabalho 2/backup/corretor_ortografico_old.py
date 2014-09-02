"""
Fazer um corretor ortografico usando o Algoritmo de Viterbi.

Inteligencia Artificial
Universidade Federal do Pampa

------------------------------------

Marcos Treviso (121150107)
marcosvtreviso@gmail.com

Version of python: 3
For run use: python3 corretor_ortografico.py <arquivo_texto>
"""

import sys, os, re
from gerador_probabilidades import gerador_probabilidades


class corretor_ortografico:

	modelo = []

	alfabeto = []
	
	prob_letras = {}
	prob_bigramas = {}
	
	palavra_correta = ""
	palavra_errada = ""
	
	erro = ["", ""]
	erros = []



	def __init__(self, prob_letras, prob_bigramas, palavra_errada, palavra_correta):
		
		self.prob_letras = prob_letras #a priori
		self.prob_bigramas = prob_bigramas #considerando a anterior
		
		self.palavra_errada = palavra_errada
		self.palavra_correta = palavra_correta

		self.alfabeto = [("%c" % i) for i in range(97, 123)] #ascii 97-a 123-z

		self.criar_modelo()
	


	def criar_modelo(self):

		#dado que a probabildiade inicial eh <0.5, 0.5>
		prob_ini = 0.5
		tabela = {}

		tam = len(self.alfabeto)
		palavra = " "+self.palavra_errada

		for char in palavra:
			for i in range(tam):
				for j in range(tam):

					tupla = (i, j)
					tabela[tupla] = [char, 0, 0, 0, prob_ini]

			tabela["final"] = [prob_ini, prob_ini]
			self.modelo.append(tabela)


	def criar_modelo(self):

		tt = (True, True)
		ft = (False, True)
		tf = (True, False)
		ff = (False, False)

		#dado que a probabildiade inicial eh <0.5, 0.5>
		tabela = {}
		tabela[tt] = [0, 0, 0, 0.5]
		tabela[ft] = [0, 0, 0, 0.5]
		tabela[tf] = [0, 0, 0, 0.5]
		tabela[ff] = [0, 0, 0, 0.5]
		tabela["final"] = [0.5, 0.5]
		self.modelo.append(tabela)

		for i in range(len(self.palavra)):

			tabela = {}
			tabela[tt] = [0, 0, 0, 0]
			tabela[ft] = [0, 0, 0, 0]
			tabela[tf] = [0, 0, 0, 0]
			tabela[ff] = [0, 0, 0, 0]
			tabela["final"] = [0, 0]
			self.modelo.append(tabela)



	def esta_no_texto(self, palavra, texto):
		return re.compile(r'\b({0})\b'.format(palavra), flags=re.IGNORECASE).search(texto) is not None


	def prob_priori(self, letra, evidencia):

		if evidencia:
			if letra in self.prob_letras:
				return self.prob_letras[letra]
			return 0
		else:
			if letra in self.prob_letras:
				return 1-self.prob_letras[letra]
			return 0


	def verifica_erro(self, dado, letra, inv):

		novo = dado+letra
		if novo in self.prob_bigramas:
			melhor = self.prob_bigramas[novo]
		else:
			melhor = (inv) and 1 or 0


		for seq, qtd in self.prob_bigramas.items():
			if seq[0] == dado:
				
				if inv:
					if qtd < melhor:
						
						mletra = seq[1]

						np = self.nova_palavra(dado+mletra)
						texto = self.pb.get_texto()

						#if self.esta_no_texto(np, texto):
						self.erro = [dado, mletra]
						if (dado, mletra, qtd) not in self.erros:
							self.erros.append((dado, mletra, qtd))

				else:
					if qtd > melhor:
						
						mletra = seq[1]

						np = self.nova_palavra(dado+mletra)
						texto = self.pb.get_texto()

						#if self.esta_no_texto(np, texto):
						self.erro = [dado, mletra]
						if (dado, mletra, qtd) not in self.erros:
							self.erros.append((dado, mletra, qtd))



	def prob_dada(self, letra, dado, evidencia):

		tt = (True, True)
		ft = (False, True)
		tf = (True, False)
		ff = (False, False)
		novo = dado+letra


		if evidencia == tt:
			self.verifica_erro(dado, letra, False)
			if novo in self.prob_bigramas:
				return self.prob_bigramas[novo]
			return 0
		
		elif evidencia == ft:
			return self.prob_priori(dado, False)

		elif evidencia == tf:
			self.verifica_erro(dado, letra, True)
			if novo in self.prob_bigramas:
				return 1-self.prob_bigramas[novo]
			return 0
		else:
			return 1-self.prob_priori(dado, False)



	def normal(self, n1, n2):
		soma = n1+n2
		n1 = n1/soma
		n2 = n2/soma
		return [n1, n2]



	def set_modelo(self, dia, ev, k1, k2, k3):

		self.modelo[dia][ev][0] = k1
		self.modelo[dia][ev][1] = k2
		self.modelo[dia][ev][2] = k3
		self.modelo[dia][ev][3] = k1*k2*k3


	def viterbi(self):

		tt = (True, True)
		ft = (False, True)
		tf = (True, False)
		ff = (False, False)
		tam = len(self.palavra)

		for dia in range(tam):

			i = dia
			dia += 1
			ant = i-1

			if i == 0:
				ant = i


			# tt
			primeiro = self.modelo[i]["final"][0]
			segundo = self.prob_dada(self.palavra[i], self.palavra[ant], tt)
			terceiro =  self.prob_priori(self.palavra[i], True)
			self.set_modelo(dia, tt, primeiro, segundo, terceiro)


			# ft
			primeiro = self.modelo[i]["final"][1]
			segundo = self.prob_dada(self.palavra[i], self.palavra[ant], ft)
			terceiro =  self.prob_priori(self.palavra[i], True)
			self.set_modelo(dia, ft, primeiro, segundo, terceiro)


			# tf
			primeiro = self.modelo[i]["final"][0]
			segundo = self.prob_dada(self.palavra[i], self.palavra[ant], tf)
			terceiro =  self.prob_priori(self.palavra[i], False)
			self.set_modelo(dia, tf, primeiro, segundo, terceiro)


			# ff
			primeiro = self.modelo[i]["final"][1]
			segundo = self.prob_dada(self.palavra[i], self.palavra[ant], ff)
			terceiro =  self.prob_priori(self.palavra[i], False)
			self.set_modelo(dia, ff, primeiro, segundo, terceiro)

			
			t1 = self.modelo[dia][tt][3]
			t2 = self.modelo[dia][ft][3]
			t3 = self.modelo[dia][tf][3]
			t4 = self.modelo[dia][ff][3]
			self.modelo[dia]["final"] = [max(t1, t2), max(t3, t4)] #normal



		self.print_modelo()
		self.achar_todos_erros()



	def print_modelo(self):

		tt = (True, True)
		ft = (False, True)
		tf = (True, False)
		ff = (False, False)
		chaves = [tt, ft, tf, ff]

		for dia in range(len(self.palavra)):

			dia += 1
			print("Dia %d:" % (dia))
			print(78*"-")

			tupla = (dia, dia+1, dia+1, dia, dia+1, dia, dia+1, dia+1)
			print("|  x%d -> x%d  |  e%d  |  P(x%d)  |  P(x%d|x%d)  |  P(e%d|x%d)  |  result  |  final  |" % tupla)
			print(78*"-")

			for ch in chaves:
				primeiro = self.modelo[dia][ch][0]
				segundo = self.modelo[dia][ch][1]
				terceiro = self.modelo[dia][ch][2]
				result = self.modelo[dia][ch][3]
				final = self.modelo[dia]["final"][0]

				if ch[1]:
					final = self.modelo[dia]["final"][1]

				s1 = "F"
				s2 = "F"
				if ch[0]:
					s1 = "V"
				if ch[1]:
					s2 = "V"

				tupla = (s1, s2, self.palavra[dia-1], primeiro, segundo, terceiro, result, final)
				print("|   %s ->  %s  |   %s  |  %5.3f  |  %8.3f  |  %8.3f  |  %6.3f  |  %5.3f  |" % tupla)

			print("\n\n")




	def parar(self):
		sys.stdin.read(1)



	def nova_palavra(self, erro):

		p = list(self.palavra)
		i = p.index(erro[0])
		p[i+1] = erro[1]
		return ''.join(p)



	def achar_erro_principal(self):
		erro = ''.join(self.erro)
		if erro != "":
			p = self.nova_palavra(erro)
			print("Trocar %s por %s!" % (self.palavra, p))
		else:
			print("Nao precisa trocar nada!")



	def achar_todos_erros(self):

		if len(self.erros) > 0:
			i = 0
			soma = 0
			for x,y,z in self.erros:
				soma += z

			for erro in sorted(self.erros, key=lambda x:x[2], reverse=True):
				p = self.nova_palavra(erro[0]+erro[1])
				
				if p == self.palavra:
					print("Nao precisa trocar nada!")
					break

				i += 1
				print("%d: Trocar `%s` por `%s`! [%.3f%%]" % (i, self.palavra, p, erro[2]/soma*100))
		else:
			print("Nao precisa trocar nada!")


		



def main(arquivo_texto, pelavra_errada, palavra_correta):

	
	gp = gerador_probabilidades(arquivo_texto, False)
	pl = gp.calc_prob_letras()
	pb = gp.calc_prob_bigramas()

	#palavra = input("Digite uma palavra para ser testada: ")
	co = corretor_ortografico(pl, pb, palavra_errada, palavra_correta)
	co.viterbi()



if name == 'main':
	if len(sys.argv) != 4:
		print('Use: {} <arquivo_texto> <palavra_errada> <palavra_correta>'.format(os.path.basename(sys.argv[0])))
		exit()
	main(sys.argv[1], sys.argv[2], sys.argv[3])