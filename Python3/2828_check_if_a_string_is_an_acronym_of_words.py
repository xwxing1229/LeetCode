# https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words/

class Solution:
    def isAcronym(self, words, s):
        """
        Inputs:
            words: list[int]
            s: str
        Outputs:
            res: bool
        """
        if len(words) != len(s):
            return False
        for i, word in enumerate(words):
            if word[0] != s[i]:
                return False
        return True