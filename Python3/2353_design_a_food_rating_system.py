# https://leetcode.cn/problems/design-a-food-rating-system/

from collections import defaultdict
from sortedcontainers import SortedList

class FoodRatings:

    def __init__(self, foods, cuisines, ratings):
        """
        Inputs:
            foods, cuisines, ratings: list[str]
        Outputs:
            None
        """
        self.foods = dict()
        self.cuisines = defaultdict(SortedList)
        for i, food in enumerate(foods):
            self.foods[food] = (cuisines[i], ratings[i])
            self.cuisines[cuisines[i]].add((-ratings[i], food))

    def changeRating(self, food: str, newRating: int) -> None:
        cuisine, rating = self.foods[food]
        self.foods[food] = (cuisine, newRating)
        self.cuisines[cuisine].remove((-rating, food))
        self.cuisines[cuisine].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.cuisines[cuisine][0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)