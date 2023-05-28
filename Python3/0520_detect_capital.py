# https://leetcode.cn/problems/detect-capital/

class Solution:
    def detectCapitalUse(self, word):
        """
        Inputs:
            word: str
        Outputs:
            res: bool
        """
        n = len(word)
        if n == 1:
            return True
        if word[0].isupper():
            if word[1].isupper():
                for i in range(2, n):
                    if word[i].islower():
                        return False
            else:
                for i in range(2, n):
                    if word[i].isupper():
                        return False
        else:
            for i in range(1, n):
                if word[i].isupper():
                    return False
        return True