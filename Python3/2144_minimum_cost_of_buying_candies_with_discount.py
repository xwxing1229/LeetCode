# https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/

class Solution:
    def minimumCost(self, cost: list[int]) -> int:
        res = 0
        cost.sort(reverse=True)
        for i, c in enumerate(cost):
            res += c * (i % 3 != 2)
        return res