# https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/

class Solution:
    def numSmallerByFrequency(self, queries, words):
        """
        Inputs:
            queries, words: list[str]
        Outputs:
            res: list[int]
        """
        f_words = defaultdict(int)
        for word in words:
            f_words[self.f(word)] += 1
        
        res = [0 for i in range(len(queries))]
        for i, q in enumerate(queries):
            f_q = self.f(q)
            for k, v in f_words.items():
                if f_q < k:
                    res[i] += v
        return res
    
    def f(self, s):
        cnt = [0 for i in range(26)]
        for ch in s:
            cnt[ord(ch) - ord("a")] += 1
        for c in cnt:
            if c > 0:
                return c