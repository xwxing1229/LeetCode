# https://leetcode.cn/problems/maximum-number-of-balls-in-a-box/

class Solution:
    def countBalls(self, lowLimit, highLimit):
        """
        Inputs:
            lowLimit: int
            highLimit: int
        Outputs:
            res: int
        """
        cnt = collections.defaultdict(int)
        for i in range(lowLimit, highLimit+1):
            s, num = 0, i
            while i:
                s += (num % 10)
                num //= 10
            cnt[s] += 1

        res = 0
        for k, v in cnt.items():
            if v > res:
                res = v
        return res