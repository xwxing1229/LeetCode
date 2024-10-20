# https://leetcode.cn/problems/maximum-height-of-a-triangle/

class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        return max(self.check(red, blue), self.check(blue, red))
    
    def check(self, first, second):
        tmp1 = int(sqrt(first))
        tmp2 = int((sqrt(4*second+1) - 1) / 2)
        res = tmp1 + tmp2
        if tmp1 < tmp2:
            res = tmp1 + tmp1
        elif tmp1 > tmp2 and tmp1 - tmp2 > 1:
            res = tmp2 + tmp2 + 1
        return res