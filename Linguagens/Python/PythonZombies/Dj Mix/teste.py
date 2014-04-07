import pygame.mixer
sounds = pygame.mixer
sounds.init()

def esperta_tocar(canal):
	while canal.get_busy():
		pass


s0 = sounds.Sound("boom.wav")
esperta_tocar(s0.play())

s0 = sounds.Sound("connected.wav")
esperta_tocar(s0.play())

s0 = sounds.Sound("error.wav")
esperta_tocar(s0.play())

s0 = sounds.Sound("punch.wav")
esperta_tocar(s0.play())

s1 = sounds.Sound("eletronic.wav")
esperta_tocar(s1.play())

s2 = sounds.Sound("meitcher.wav")
esperta_tocar(s2.play())