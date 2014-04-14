import urllib2, json
from pprint import pprint

url = 'https://graph.facebook.com/fmasanori'
resp = urllib2.urlopen(url).read()
data = json.loads(resp.decode('utf8'))
pprint(data)
