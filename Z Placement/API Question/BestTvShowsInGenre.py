import requests
from operator import itemgetter

genre = "Action"
maxRating = 0
maxRatingMovies = []

response = requests.get("https://jsonmock.hackerrank.com/api/tvseries?page=1").json()

totalPages = response['total_pages']

for i in range(1, totalPages + 1):
    response = requests.get("https://jsonmock.hackerrank.com/api/tvseries?page=" + str(i)).json()
    perPageTotal = response['per_page']
    for j in range(0, perPageTotal):
        genreList = response["data"][j]["genre"].split(", ")
        if(genre in genreList):
            movie = response["data"][j]
            if(movie["imdb_rating"] == maxRating):
                maxRatingMovies.append(movie['name'])
            elif(movie["imdb_rating"] > maxRating):
                maxRatingMovies = []
                maxRating = movie["imdb_rating"]
                maxRatingMovies.append(movie['name'])

newList = maxRatingMovies.sort()
print(maxRatingMovies)
print(newList)

