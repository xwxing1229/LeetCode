# https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution:
    def subtractProductAndSum(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        prod, s = 1, 0
        while n > 0:
            num = n % 10
            prod *= num
            s += num
            n //= 10
        return prod - s