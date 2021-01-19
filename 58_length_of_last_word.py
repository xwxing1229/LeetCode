# https://leetcode-cn.com/problems/length-of-last-word/

class Solution:
    def lengthOfLastWord(self, s:str) -> int:
        idx = len(s) - 1
        while idx > 0:
            if s[idx] != ' ':
                break
            else:
                idx = idx - 1
        
        for i in range(idx, -1, -1):
            if s[i] == ' ':
                res = idx - i
                break
            if i == 0:
                res = idx + 1
        return res