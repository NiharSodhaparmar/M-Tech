import requests

team = "Barcelona"
year = "2011"

totalGoals = 0

response = requests.get("https://jsonmock.hackerrank.com/api/football_matches?year=" + year + "&team1=" + team + "&page=1").json()
totalPages = response['total_pages']

for page in range(1,totalPages + 1):
    response = requests.get("https://jsonmock.hackerrank.com/api/football_matches?year=" + year + "&team1=" + team + "&page=" + str(page)).json()
    perPageTotalData = response['total']
    for j in range(0,perPageTotalData):
        totalGoals += int(response['data'][j]['team1goals'])


response = requests.get("https://jsonmock.hackerrank.com/api/football_matches?year=" + year + "&team2=" + team + "&page=1").json()
totalPages = response['total_pages']

for page in range(1,totalPages + 1):
    response = requests.get("https://jsonmock.hackerrank.com/api/football_matches?year=" + year + "&team2=" + team + "&page=" + str(page)).json()
    perPageTotalData = response['total']
    for j in range(0,perPageTotalData):
        totalGoals += int(response['data'][j]['team2goals'])

print(totalGoals)