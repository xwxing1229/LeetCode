#  https://leetcode.cn/problems/maximum-number-of-alloys/

class Solution:
    def maxNumberOfAlloys(self, n, k, budget, composition, stock, cost):
        """
        Inputs:
            n, k, budget: int
            composition: list[list[int]]
            stock, cost: list[int]
        Outputs:
            res: int
        """
        res = 0
        left, right = 0, min(stock) + budget
        while left <= right:
            mid = (left + right) // 2
            valid = False
            for i in range(k):
                spend = 0
                for j in range(n):
                    spend += max(composition[i][j]*mid-stock[j], 0) * cost[j]
                if spend <= budget:
                    valid = True
                    break
            if valid:
                left = mid + 1
                res = mid
            else:
                right = mid - 1
        return res