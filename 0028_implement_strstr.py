# https://leetcode-cn.com/problems/implement-strstr/

class Solution:
    def strStr(self, haystack:str, needle:str) -> int:
        len_haystack = len(haystack)
        len_needle = len(needle)
        if len_needle == 0:
            return 0
           
        if len_haystack < len_needle:
            return -1
        
        res = -1
        for i in range(len_haystack-len_needle+1):
            if haystack[i:i+len_needle] == needle:
                res = i
                break
        return res
