# https://leetcode.cn/problems/words-within-two-edits-of-dictionary/

class Solution:
    def twoEditWords(self, queries: list[str], dictionary: list[str]) -> list[str]:
        def CheckValid(query: str, word: str) -> bool:
            cnt = 0
            for i, ch in enumerate(query):
                cnt += (ch != word[i])
            return cnt <= 2
        
        res = []
        for q in queries:
            for word in dictionary:
                if CheckValid(q, word):
                    res.append(q)
                    break
        return res