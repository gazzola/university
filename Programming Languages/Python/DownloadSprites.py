#fuck the copyright, share with who you want
import urllib.request, re, os

class DownloadSprites:

	__directory = ''
	__sprites = []


	def setDirectoryPath(self, path):
		self.__directory = path


	def createDirectory(self, directory):
		newpath = r''+directory+'' 
		if not os.path.exists(newpath): 
			os.makedirs(newpath)


	def saveImage(self, extension):
		last = ''
		count = 0
		for cod, name, cat, part in self.__sprites:

			if(cat != last):
				self.createDirectory(self.__directory+'/'+cat)
				last = cat

			f = open(self.__directory+'/'+cat+'/'+name+'.'+extension, 'wb')
			
			url = 'http://www.spriters-resource.com/resources/sheets/'
			figura = urllib.request.urlopen(url+part+'/'+cod+'.'+extension).read()
			f.write(figura)
			f.close()
			print(name + '.'+extension+' impresso na categoria '+ cat)
			count += 1

		print("%d imagens baixadas" %count)


	def catchSprites(self, category, game):
		res = urllib.request.urlopen('http://www.spriters-resource.com/'+category+'/'+game)
		txt = res.read().decode('utf8')

		url = 'href="/'+category+'/'+game+'/sheet/'
		for m in re.finditer(url, txt):

			inicio = m.start()+len(url)
			fim = m.end()+5
			url_imagem = self.searchComplete(txt, '/', inicio)


			nome = txt[fim:fim+90]
			nomeonde = nome.find('alt="')+5+fim
			nome_completo = self.searchComplete(txt, '"', nomeonde)


			cat = txt[m.start()-95:m.start()]
			catonde = cat.find('<div class="section">')
			if(catonde != -1):
				nome_cat_completo = self.searchComplete(txt, '<', catonde+21+m.start()-95)


			partonde = nomeonde-(20+len(url_imagem))
			part = self.searchComplete(txt, '"', partonde)
			part = part.split('/')[1]


			self.__sprites.append((url_imagem, nome_completo, nome_cat_completo, part))


	def searchComplete(self, text, search, initPos):
		temp = ''
		count = initPos
		while(text[count] != search):
			temp += text[count]
			count += 1
		return temp


	def getSprites(self):
		return self.__sprites



#http://www.spriters-resource.com/snes/crystalbeans/
category = 'snes'
game = 'crystalbeans'
directory = 'zsprites_'+game

ds = DownloadSprites()
ds.setDirectoryPath(directory)
ds.createDirectory(directory)
ds.catchSprites(category, game)
ds.saveImage('gif')

print(ds.getSprites())