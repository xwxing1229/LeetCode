# https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

class Solution:
    def filterRestaurants(self, restaurants, veganFriendly, maxPrice, maxDistance):
        """
        Inputs:
            restaurants: list[list[int]]
            veganFriendly, maxPrice, maxDistance: int
        Outputs:
            res: int
        """
        filtered = []
        for r in restaurants:
            if r[2] >= veganFriendly and r[3] <= maxPrice and r[4] <= maxDistance:
                filtered.append([r[0], r[1]])
        filtered.sort(key=lambda x: (-x[1], -x[0]))
        res = [r[0] for r in filtered]
        return res