# https://leetcode.cn/problems/length-of-last-word/

class Solution:
    def lengthOfLastWord(self, s:str) -> int:
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """

        s = " " + s + " "
        res = 0
        tmp = 0
        for i in range(1, len(s)):
            c = s[i]
            if c != " ":
                tmp = tmp + 1
            elif s[i-1] != " ":
                res = tmp
                tmp = 0
        return res