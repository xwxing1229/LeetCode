# https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/

class Solution:
    def greatestLetter(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        res, tmp = "", ""
        lower, upper = [0 for _ in range(26)], [0 for _ in range(26)]
        for ch in s:
            if ch.islower():
                if upper[ord(ch) - ord("a")] and ch.upper() > tmp:
                    tmp = ch.upper()
                else:
                    lower[ord(ch) - ord("a")] = 1
            else:
                if lower[ord(ch) - ord("A")] and ch > tmp:
                    tmp = ch
                else:
                    upper[ord(ch) - ord("A")] = 1
        if tmp != "":
            res += tmp
        return res