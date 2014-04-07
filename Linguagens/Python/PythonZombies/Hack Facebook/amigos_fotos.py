import urllib.request, json, os


def create_directory(directory):
	newpath = r''+directory+'' 
	if not os.path.exists(newpath): 
		os.makedirs(newpath)


def grava_imagem(directory, amigo):
  size = '/picture?width=200&height=200'
  url = 'https://graph.facebook.com/'+ amigo['id'] + size
  figura = urllib.request.urlopen(url).read()
  f = open(directory + amigo['name'] + '.jpg', 'wb')
  f.write(figura)
  f.close()
  print (amigo['name'] + '.jpg impresso')


#get the token https://developers.facebook.com/tools/explorer
url = 'https://graph.facebook.com/me/friends?access_token=CAACEdEose0cBAHHMD3ZA2WhUbHZBVKxFEGeO3zOHVDHLs4dm8UrsZApNLpKo37YZADwvN7znU3rPNiKewfrTFYXiFZBw7Pt7CwesummPZCyqbnSBZAZAiVoajwVuKzJQQ37lGTDBBholfVZAP85VtdNIdvSTZBmmvEBgW4wmeenuCH42vDQdqK88wXvCGtq4wsRHYZD'
resp = urllib.request.urlopen(url).read()
dados = json.loads(resp.decode('utf-8'))


directory = 'mosaico/'
create_directory(directory)


for amigo in dados['data']:
	grava_imagem(directory, amigo)