import urllib.request
import json


url = 'http://www.spriters-resource.com/resources/sheets/56/'
resp = urllib.request.urlopen(url)
data = json.loads(resp.read().decode('utf8'))


for key in data:
	print(data[key])