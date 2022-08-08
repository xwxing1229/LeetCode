# https://leetcode.cn/problems/maximum-product-of-word-lengths/

class Solution:
    def maxProduct(self, words):
        """
        Inputs:
            words: list[str]
        Outputs:
            res: int
        """

        masks = dict()
        for word in words:
            mask = 0
            for i in range(len(word)):
                mask = mask | (1 << (ord(word[i])-ord('a')))

            if masks.get(mask, 0) < len(word):
                masks[mask] = len(word)

        res = 0
        for mask1, len1 in masks.items():
            for mask2, len2 in masks.items():
                if (mask1 & mask2) == 0:
                    res = max(res, len1*len2)
        return res