# https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/

class Solution:
    def minimumRemoval(self, beans):
        """
        Inputs:
            beans: list[int]
        Outputs:
            res: int
        """
        res = sum(beans)
        beans.sort()
        n = len(beans)
        cumsum = [0 for _ in range(n+1)]
        for i, bean in enumerate(beans):
            cumsum[i+1] = cumsum[i] + bean
        for i, bean in enumerate(beans):
            left = cumsum[i]
            right = cumsum[n] - cumsum[i] - bean * (n-i)
            res = min(res, left+right)
        return res