# https://leetcode.cn/problems/minimum-operations-to-make-a-special-number/

class Solution:
    def minimumOperations(self, num: str) -> int:
        possible = ["00", "25", "50", "75"]
        n = len(num)
        res = n
        for s in possible:
            i = n-1
            while i >= 0 and num[i] != s[1]:
                i -= 1
            i -= 1
            while i >= 0 and num[i] != s[0]:
                i -= 1
            if i >= 0:
                res = min(res, n-i-2)
        
        for val in num:
            if val == "0":
                res = min(res, n-1)
                
        return res