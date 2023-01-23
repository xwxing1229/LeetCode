# https://leetcode.cn/problems/calculate-amount-paid-in-taxes/

class Solution:
    def calculateTax(self, brackets, income):
        """
        Inputs:
            brackets: list[list[int]]
            income: int
        Outputs:
            res: float
        """
        res, lower = 0, 0
        for upper, rate in brackets:
            res += (min(income, upper) - lower) * rate
            if upper >= income:
                break
            lower = upper
        return res / 100