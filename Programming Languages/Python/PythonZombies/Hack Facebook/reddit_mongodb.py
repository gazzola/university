import urllib.request, json, pymongo

conn = pymongo.Connection('mongodb://localhost:80', safe=True)

db = conn.reddit
stories = db.stories

url = 'http://www.reddit.com/r/Python/.json'
reddit_page = urllib.request.urlopen(url)

parsed = json.loads(reddit_page.read().decode('utf-8'))

for item in parsed['data']['children']:
	print(item['data'])
	stories.insert(item['data'])