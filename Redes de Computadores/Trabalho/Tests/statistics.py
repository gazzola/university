# num de execucoes
N = 50

# tempo de execucao
pasta = "MAC"
tipo = "mac"
algs = ("AES", "Blowfish", "RC5", "Skipjack", "TEA")

# bateria
V = 10.8
CORRENTE = 5


def print_data(alg, execs):

	print alg
	print "==============\n\n"

	j = 1
	for d in execs:

		print "\n\nEXECUCAO #"+str(j)
		print "--------\n"

		j+=1

		i = 1
		for t in d:
			print "ENTRADA "+str(i)+":"
			i += 1
			for k, l in t.items():
				print(k+": %.8f" % l)
			print ""



tempos_algs = {}


def calcule_statistics(alg, execs):

	dados = []
	#dados.append({"ECB":0.0, "CBC":0.0, "CFB":0.0, "OFB":0.0, "CTR":0.0})
	#dados.append({"ECB":0.0, "CBC":0.0, "CFB":0.0, "OFB":0.0, "CTR":0.0})
	dados.append({"EAX":0.0, "GCM":0.0, "CCM":0.0})
	dados.append({"EAX":0.0, "GCM":0.0, "CCM":0.0})


	s = [0, 0]
	for d in execs:

		i = 0
		for t in d:
			for k, l in t.items():
				dados[i][k] += l
				s[i] += l
			i += 1

	print "\n========================================"
	print alg
	print "========================================\n"

	print("TOTAL(s): %.8f   (%.8f, %.8f)" % (sum(s), s[0], s[1]))
	print("MEDIA(s): %.8f" % (sum(s)/N))
	tempos_algs[alg] = sum(s)

	for i in range(2):
		print "\nENTRADA "+str(i+1)+":\n--------------"
		for k, l in dados[i].items():
			print(k+": %.8f" % (1000*l/N))

	print ""

	return s


print "TEMPOS DE EXECUCAO:\n\n"

t_total = [0, 0]
for alg in algs:

	tempos = []
	execs = []
	
	dados = []
	#dados.append({"ECB":0.0, "CBC":0.0, "CFB":0.0, "OFB":0.0, "CTR":0.0})
	#dados.append({"ECB":0.0, "CBC":0.0, "CFB":0.0, "OFB":0.0, "CTR":0.0})
	dados.append({"EAX":0.0, "GCM":0.0, "CCM":0.0})
	dados.append({"EAX":0.0, "GCM":0.0, "CCM":0.0})

	tempos = open(pasta+"/"+alg+".out", "r")
	entrada = 0
	algoritmo = "ECB"

	for s in tempos:
		
		s = s.strip()
		if s.find("ENTRADA 1") != -1:
			execs.append(dados)
			entrada = 0
		elif s.find("ENTRADA 2") != -1:
			entrada = 1
		elif s.find("Algorithm:") != -1:
			algoritmo = s.split("/")[1]
		elif s.find("Time:") != -1:
			t = float(s.split(": ")[1])
			dados[entrada][algoritmo] = t

	b = calcule_statistics(alg, execs)
	t_total[0] += b[0]
	t_total[1] += b[1]
	#print_data(alg, execs)


print sum(t_total), t_total
TEMPO_EXECUCAO = sum(t_total)	





# MANUAL

def s_to_h(t):
	return t/3600.0


def m_to_h(t):
	return (t/60.0)

def m_to_s(t):
	return (t*60.0)


def tempo_por_execucoes(tempo):
	return tempo/N


def to_amperes(w):
	return w/V


def corrente_media(e_consumida, tempo):
	return e_consumida/tempo


def potencia_media(c_media):
	return c_media * V


def consumo(p_media, tempo):
	return p_media*tempo




print "\n\nCONSUMO DE ENERGIA:\n"
c = 24155-23350 #Wh
tx = 1.27976


for alg, t in tempos_algs.items():

	cor = corrente_media(to_amperes(c), m_to_h(tx))
	pm = potencia_media(cor)
	print alg+":", consumo(pm, t/N)

