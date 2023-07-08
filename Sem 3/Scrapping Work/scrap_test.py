import requests
import bs4
post_url = 'https://www.instagram.com/p/Cp2Sq-lv8yG/'

req = requests.get(post_url)

print("REQ---------------------------")
print(req.text)