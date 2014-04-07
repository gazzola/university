from tkinter import *
app = Tk()
app.title("Escolha a musica")
app.geometry('300x100+200+100')

import pygame.mixer
sounds = pygame.mixer
sounds.init()

fails = IntVar()
fails.set(0)

nices = IntVar()
nices.set(0)


def esperta_tocar(canal):
	while canal.get_busy():
		pass

def ap_fail():

	s0 = sounds.Sound("error.wav")
	esperta_tocar(s0.play())

	s0 = sounds.Sound("boom.wav")
	esperta_tocar(s0.play())

	s0 = sounds.Sound("punch.wav")
	esperta_tocar(s0.play())

	fails.set(fails.get()+1)


def ap_nice():

	s1 = sounds.Sound("eletronic.wav")
	esperta_tocar(s1.play())

	s2 = sounds.Sound("meitcher.wav")
	esperta_tocar(s2.play())

	nices.set(nices.get()+1)




lab0 = Label(app, text='Aperte os bototes!', height=3)
lab0.pack()

lab1 = Label(app, textvariable = fails)
lab1.pack(side = 'left')

lab2 = Label(app, textvariable = nices)
lab2.pack(side = 'right')



b1 = Button(app, text="Fail!", width=10, command = ap_fail)
b1.pack(side = "left", padx = 10, pady = 10)

b2 = Button(app, text="Nice!", width=10, command = ap_nice)
b2.pack(side = "right", padx = 10, pady = 10)


app.mainloop()