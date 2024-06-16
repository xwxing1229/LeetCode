# https://leetcode.cn/problems/distribute-candies-to-people/

class Solution:
    def distributeCandies(self, candies, num_people):
        """
        Inputs:
            candies, num_people: int
        Outputs:
            res: list[int]
        """
        res = [0 for _ in range(num_people)]
        candy, idx = 1, 0
        while candies > 0:
            candy = min(candy, candies)
            res[idx] += candy
            candies -= candy

            candy += 1
            idx = (idx + 1) % num_people
        return res