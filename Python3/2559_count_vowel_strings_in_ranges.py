# https://leetcode.cn/problems/count-vowel-strings-in-ranges/

class Solution:
    def vowelStrings(self, words, queries):
        """
        Inputs:
            words: list[str]
            queries: list[list[int]]
        Outputs:
            res: list[int]
        """
        n = len(words)
        vowels = {"a", "e", "i", "o", "u"}
        valid = [0 for i in range(n+1)]
        for i, word in enumerate(words):
            if word[0] in vowels and word[-1] in vowels:
                valid[i+1] = valid[i] + 1
            else:
                valid[i+1] = valid[i]
        
        res = [0 for k in range(len(queries))]
        for k, query in enumerate(queries):
            res[k] = valid[query[1]+1] - valid[query[0]]

        return res