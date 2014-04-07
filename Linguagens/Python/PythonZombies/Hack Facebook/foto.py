import urllib2, json

user = 'marcos.treviso'
url = 'https://graph.facebook.com/'+user+'/picture?type=large'
figura = urllib2.urlopen(url).read()

arquivo = user + '.jpg'
f = open (arquivo, 'wb')
f.write(figura)
f.close()

print (arquivo, 'gravado no seu diretorio...')
