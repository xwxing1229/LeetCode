# https://leetcode.cn/problems/count-the-number-of-consistent-strings/

class Solution:
    def countConsistentStrings(self, allowed, words):
        """
        Inputs:
            allowed: str
            words: list[str]
        Outputs:
            res: int
        """
        res = len(words)
        table = [0 for _ in range(26)]
        for ch in allowed:
            table[ord(ch) - ord("a")] = 1
        for word in words:
            for ch in word:
                if table[ord(ch) - ord("a")] != 1:
                    res -= 1
                    break
        return res
