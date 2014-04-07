class Cliente:

	def __init__(self, nome, telefone):
		self.nome = nome
		self.telefone = telefone

	def __str__(self):
		return 'nome: %s\ntelefone: %s\n' %(self.nome, self.telefone)


class Conta:

	def __init__(self, clientes, numero, saldo):
		self.saldo = 0
		self.clientes = clientes
		self.numero = numero
		self.operacoes = []
		self.deposito(saldo)

	def resumo(self):
		print('CC Numero: %s Saldo: %10.2f' %(self.numero, self.saldo))

	def saque(self, valor):
		if(self.saldo >= valor):
			self.saldo -= valor
			self.operacoes.append(['Saque', valor])

	def deposito(self, valor):
		self.saldo += valor
		self.operacoes.append(['Deposito', valor])

	def extrato(self):
		print('Extrato CC Num %s' %(self.numero))
		for op in self.operacoes:
			print('%10s %10.2f' %(op[0], op[1]))
		print('%10s %10.2f' %('Saldo=', self.saldo))
		print()


class ContaEspecial(Conta):

	def __init__(self, clientes, numero, saldo, limite=0):
		Conta.__init__(self, clientes, numero, saldo)
		self.limite = limite

	def saque(self, valor):
		if self.saldo + self.limite >= valor:
			self.saldo -= valor
			self.operacoes.append(['Saque', valor])
