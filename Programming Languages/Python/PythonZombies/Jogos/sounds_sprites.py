import pygame, sys, time, random
from pygame.locals import *

#set up pygame
pygame.init()
mainClock = pygame.time.Clock()


#set up the window
WINW = 400
WINH = 400
windowSurface = pygame.display.set_mode((WINW, WINH), 0, 32)
pygame.display.set_caption('Input!')

#set up the colors
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)



#set up the player and food data structure


foodCounter = 0
NEWFOOD= 40
FOODSIZE = 20

player = pygame.Rect(300, 100, 40, 40)
playerImage = pygame.image.load('assets/tux.jpg')
playerStretchedImage = pygame.transform.scale(playerImage, (40, 40))

foodImage = pygame.image.load('assets/perfil_foruns.png')
foodImage = pygame.transform.scale(playerImage, (20, 20))
foods = []

for i in range(20):
	foods.append(pygame.Rect(
		random.randint(0, WINW-FOODSIZE),
		random.randint(0, WINH-FOODSIZE),
		FOODSIZE, FOODSIZE))



#set up music
pickSound = pygame.mixer.Sound('assets/greeting.wav')
pygame.mixer.music.load('assets/eletronic.wav')
pygame.mixer.music.play(-1, 0.0)
musicPlaying = True

#set up movement variables
moveLeft = False
moveRight = False
moveUp = False
moveDown = False


#set the speed
MOVESPEED = 6
counter = 0

while True:
	for event in pygame.event.get():
		if event.type == QUIT:
			pygame.quit()
			sys.quit()
		if event.type == KEYDOWN:
			#change the keyboard variables
			if event.key == K_LEFT or event.key == ord('a'):
				moveRight = False
				moveLeft = True
			if event.key == K_RIGHT or event.key == ord('d'):
				moveRight = True
				moveLeft = False
			if event.key == K_UP or event.key == ord('w'):
				moveDown = False
				moveUp = True
			if event.key == ord('m'):
				if musicPlaying:
					pygame.mixer.music.stop()
				else:
					pygame.mixer.music.play(-1, 0.0)
				music = not musicPlaying
		if event.type == MOUSEBUTTONUP:
			foods.append(pygame.Rect(event.pos[0]-10, event.pos[1]-10, 20, 20))
		
	#draw the black background onto the surface
	windowSurface.fill(BLACK)
	
	#draw the player onto the surface
	pygame.draw.rect(windowSurface, WHITE, player)

	foodCounter += 1
	if foodCounter >= NEWFOOD:
		#add new food
		foodCounter = 0
		foods.append(pygame.Rect(
		random.randint(0, WINW-FOODSIZE),
		random.randint(0, WINH-FOODSIZE),
		FOODSIZE, FOODSIZE))

	#check if the player has intersected with any food squares
	for food in foods[:]:
		if player.colliderect(food):
			foods.remove(food)
			player = pygame.Rect(player.left, player.top, player.right, player.bottom)
			playerStretchedImage = pygame.transform.scale(playerImage, (40, 40))


	#draw the food
	for i in foods:
		windowSurface.blit(foodImage, food)

	#draw the food
	#for i in range(len(foods)):
	#	pygame.draw.rect(windowSurface, GREEN, foods[i])

	#draw the window onto the screen
	pygame.display.update()
	mainClock.tick(40)