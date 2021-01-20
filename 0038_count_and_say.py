# https://leetcode-cn.com/problems/count-and-say/

class Solution:
    def countAndSay(self, n:int) -> str:
        if n == 1:
            return '1'
        
        res = []
        s = self.countAndSay(n-1)
        count = 1
        for i in range(len(s)-1):
            if s[i] == s[i+1]:
                count = count + 1
            else:
                res.append(str(count) + s[i])
                count = 1
        res.append(str(count) + s[-1])
        return res
