class Televisao(object):

	ligada, canal

	def __init__(self):
		self.ligada = False
		self.canal = 2	
	
	def mudaCanalBaixo(self):
		self.canal -= 1

	def mudaCanalCima(self):
		self.canal += 1