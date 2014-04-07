import urllib.request, json

def search(texto):
	url = 'https://graph.facebook.com/search?q='+texto
	tail = '&type=post&access_token=CAACEdEose0cBAOkZBJNxwiyjpL08BaHhAKAVgTicLab9eurnkRRoFeG1fXK3uYpG6yQZAefbdc3qc1H26xaqwY2lwX5wDDOVJLFFXcipiCX26BfQ6y9Rn1AEoz5cEL334OAPZBJrYkv0ric76JVkrYnI5xqa6Al5xgMcrWLJAUkUlbYwjhk2vfvj87jYqQZD'
	resp = urllib.request.urlopen(url+tail).read()
	data = json.loads(resp.decode('utf-8'))
	return data['data']


texto = 'sherlock'
for resp in search(texto):
	if 'message' in resp:
		print(resp['from']['name']+': '+resp['message']+'\n')
