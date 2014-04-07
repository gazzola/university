#MODEL
def salvar_dados():
	
	try:
		global opcoes

		fileD = open("encomendas", "r")
		
		fileD.write("Destino: ")
		fileD.write("%s\n" % destino.get())
		fileD.write("Descricao: ")
		fileD.write("%s" % descricao.get())
		fileD.write("Endereco: ")
		fileD.write("%s\n\n" % endereco.get("1.0", END))
		destino.set(opcoes[0])
		descricao.delete(0, END)
		endereco.delete("1.0", END)
	except Exception as excecao:
		app.title('ERRO: %s' %excecao)


def ler_destinos(arquivo):
	destinos = []
	f = open(arquivo)
	for linha in f:
		destinos.append(linha.rstrip())
	return destinos


#CONTROLLER = TKINTER
from tkinter import *
app = Tk()
app.title('HEAD-EX LOGISTICA E TRANSPORTES')

Label(app, text='Destino:').pack()
destino = StringVar()


opcoes = ler_destinos('cidades')
destino.set(opcoes[0])
OptionMenu(app, destino, *opcoes).pack()


Label(app, text='Descricao: ').pack()
descricao = Entry(app)
descricao.pack()

Label(app, text='Endereco: ').pack()
endereco = Text(app)
endereco.pack()

Button(app, text='Salvar', command=salvar_dados).pack()
app.mainloop()