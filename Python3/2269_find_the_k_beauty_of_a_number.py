# https://leetcode.cn/problems/find-the-k-beauty-of-a-number/

class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        res = 0
        s = str(num)
        for i in range(len(s)-k+1):
            sub = int(s[i: i+k])
            if sub == 0 or num % sub != 0:
                continue
            res += 1
        return res