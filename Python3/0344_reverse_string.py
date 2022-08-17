# https://leetcode.cn/problems/reverse-string/

class Solution:
    def reverseString(self, s):
        """
        Do not return anything, modify s in-place instead.
        """
        """
        Inputs:
            s: list[str]
        Outputs:
            None
        """
        n = len(s)
        for i in range(n//2):
            tmp = s[i]
            s[i] = s[n-1-i]
            s[n-1-i] = tmp