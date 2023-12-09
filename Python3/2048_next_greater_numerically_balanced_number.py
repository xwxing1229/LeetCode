# https://leetcode.cn/problems/next-greater-numerically-balanced-number/

class Solution:
    def nextBeautifulNumber(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        res = n + 1
        while not self.isBalance(res):
            res += 1
        return res

    def isBalance(self, num):
        cnt = defaultdict(int)
        while num > 0:
            cnt[num % 10] += 1
            num //= 10
        for k, v in cnt.items():
            if k != v:
                return False
        return True