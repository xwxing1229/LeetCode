# https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/

class Solution:
    def getLucky(self, s, k):
        """
        Inputs:
            s: str
            k: int
        Outputs:
            res: int
        """
        convert = [0 for i in range(len(s)+1)]
        for i in range(len(s)):
            convert[i] = ord(s[i]) - ord("a") + 1

        res = 0
        n = len(convert)
        for _ in range(k):
            res = 0
            for i in range(n):
                num = convert[i]
                while num:
                    res += (num % 10)
                    num //= 10
            n = 0
            tmp = res
            while tmp:
                convert[n] = tmp % 10
                tmp //= 10
                n += 1
        return res