# https://leetcode.cn/problems/count-integers-with-even-digit-sum/

class Solution:
    def countEven(self, num):
        """
        Inputs:
            num: int
        Outputs:
            res: int
        """
        res = 0
        for i in range(1, num+1):
            s, n = 0, i
            while n:
                s += n % 10
                n //= 10
            if s % 2 == 0:
                res += 1
        return res
sol = Solution()
print(sol.countEven(30))