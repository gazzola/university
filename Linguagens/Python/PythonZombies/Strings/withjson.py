import urllib2, json

req = urllib2.Request(url='http://api.icndb.com/jokes/random?limitTo=[nerdy]',
                      data='This data is passed to stdin of the CGI')

f = urllib2.urlopen(req)
data = json.loads(f.read().decode('utf8'))
print data['value']['joke']