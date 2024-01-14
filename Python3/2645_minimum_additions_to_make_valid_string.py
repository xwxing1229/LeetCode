# https://leetcode.cn/problems/minimum-additions-to-make-valid-string/

class Solution:
    def addMinimum(self, word):
        """
        Inputs:
            word: str
        Outputs:
            res: int
        """
        res = 0
        i, n = 0, len(word)
        while i < n:
            cur = word[i]
            if cur == "a":
                i += 1
                if i < n and word[i] == "b":
                    i += 1
                    if i < n and word[i] == "c":
                        i += 1
                    else:
                        res += 1
                elif i < n and word[i] == "c":
                    res += 1
                    i += 1
                else:
                    res += 2
            elif cur == "b":
                i += 1
                if i < n and word[i] == "c":
                    res += 1
                    i += 1
                else:
                    res += 2
            else:
                res += 2
                i += 1
        return res