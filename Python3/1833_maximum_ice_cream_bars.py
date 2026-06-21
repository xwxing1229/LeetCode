# https://leetcode.cn/problems/maximum-ice-cream-bars/

from collections import defaultdict

class Solution:
    def maxIceCream(self, costs: list[int], coins: int) -> int:
        count = defaultdict(int)
        for cost in costs:
            count[cost] += 1
        
        res = 0
        for cost in range(1, max(costs)+1):
            tmp = coins // cost
            if tmp == 0:
                break
            n = min(count[cost], tmp)
            res += n
            coins -= n * cost
        return res