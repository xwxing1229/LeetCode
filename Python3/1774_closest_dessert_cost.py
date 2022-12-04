# https://leetcode.cn/problems/closest-dessert-cost/

class Solution:
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        Inputs:
            baseCosts: list[int]
            toppingCosts: list[int]
            target: int
        Outputs:
            res: int
        """
        self.res = baseCosts[0]
        for b in baseCosts:
            self.dfs(toppingCosts, target, 0, b)
        return self.res

    def dfs(self, toppingCosts, target, idx, cur):
        diff_res, diff_cur = abs(self.res - target), abs(cur - target)
        if diff_res > diff_cur:
            self.res = cur
        elif diff_res == diff_cur and self.res > cur:
            self.res = cur
        elif diff_res < diff_cur and cur > target:
            return

        if idx == len(toppingCosts):
            return

        self.dfs(toppingCosts, target, idx+1, cur)
        self.dfs(toppingCosts, target, idx+1, cur+toppingCosts[idx])
        self.dfs(toppingCosts, target, idx+1, cur+toppingCosts[idx]*2)