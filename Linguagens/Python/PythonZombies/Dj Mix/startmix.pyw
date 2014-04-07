from tkinter import *
from sound_panel import *
import pygame.mixer, os

app = Tk()
app.title("MIX OOP")

mixer = pygame.mixer
mixer.init()

dirList = os.listdir(".")
for fname in dirList:
	if fname.endswith(".wav"):
		SoundPanel(app, mixer, fname).pack()

def shutdown():
	mixer.stop()
	app.destroy()

app.protocol('WM_DELETE_WINDOW', shutdown)
app.mainloop()