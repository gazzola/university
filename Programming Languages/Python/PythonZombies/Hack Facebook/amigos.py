import urllib.request
import json


url = 'https://graph.facebook.com/marcos.treviso/'
resp = urllib.request.urlopen(url)
data = json.loads(resp.read().decode('utf8'))


for key in data:
	print(data[key])