# https://leetcode.cn/problems/count-symmetric-integers/

class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        def isSym(num):
            s = str(num)
            n = len(s)
            if n % 2:
                return False
            s1, s2, half = 0, 0, n//2
            for i in range(half):
                s1 += int(s[i])
                s2 += int(s[i+half])
            return s1 == s2
        
        res = 0
        for num in range(low, high+1):
            res += isSym(num)
        return res