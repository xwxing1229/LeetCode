# https://leetcode.cn/problems/count-good-numbers/

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = int(1e9) + 7
        res = pow(5, (n+1)//2, mod) * pow(4, n//2, mod) % mod
        return res