# https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/

class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        table = {chr(ord("a")+i): chr(ord("a")+i+1) for i in range(26)}
        
        res, tmp = 0, 1
        for i in range(1, len(s)):
            if table[s[i-1]] == s[i]:
                tmp += 1
            else:
                res = max(res, tmp)
                tmp = 1
        res = max(res, tmp)
        return res