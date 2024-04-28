# https://leetcode.cn/problems/convert-to-base-2/

class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0:
            return "0"
        
        res = ""
        while n != 0:
            mod = n % (-2)
            if mod == -1:
                mod = 1
            n = (n - mod) // (-2)
            res += str(mod)
        res = res[::-1]
        return res