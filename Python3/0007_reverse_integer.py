# https://leetcode-cn.com/problems/reverse-integer/

class Solution:
    def reverse(self, x:int) -> int:
        if x > 0:
            bound = (1<<31) - 1
        else:
            bound = 1<<31
        
        res = 0
        y = abs(x)
        while y != 0:
            res = res * 10 + y % 10
            if res > bound:
                res = 0
                break
            else:
                y = y // 10
        
        if x < 0:
            res = -res
        return res
