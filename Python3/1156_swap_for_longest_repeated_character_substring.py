# https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/

class Solution:
    def maxRepOpt1(self, text):
        """
        Inputs:
            text: str
        Outputs:
            res: int
        """
        cnts = Counter(text)
        n = len(text)
        i = 0
        res = 0
        while i < n:
            ch = text[i]
            j = i + 1
            while j < n and text[j] == ch:
                j += 1
            k = j + 1
            while k < n and text[k] == ch:
                k += 1
            res = max(res, min(k-i, cnts[ch]))

            i = j
        return res