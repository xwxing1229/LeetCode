# https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/

class Solution:
    def vowelStrings(self, words, left, right):
        """
        Inputs:
            words: list[str]
            left, right: int
        Outputs:
            res: int
        """
        res = 0
        vowels = {"a", "e", "i", "o", "u"}
        for i in range(left, right+1):
            if words[i][0] in vowels and words[i][-1] in vowels:
                res += 1
        return res