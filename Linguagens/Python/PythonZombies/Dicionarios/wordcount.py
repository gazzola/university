arq = open('marcosfile')

texto = arq.read().lower().split()


dic = {}
for p in texto:
    if p not in dic:
        dic[p] = 1
    else:
        dic[p] += 1

print ('Marcos aparece %s vezes' %dic['marcos'])
arq.close()
