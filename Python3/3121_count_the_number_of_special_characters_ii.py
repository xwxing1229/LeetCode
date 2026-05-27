# https://leetcode.cn/problems/count-the-number-of-special-characters-ii/

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        res = 0
        lowers = [0 for _ in range(26)]
        uppers = [0 for _ in range(26)]
        invalid = [0 for _ in range(26)]
        for ch in word:
            if invalid[ord(ch.lower()) - ord("a")]:
                continue
            if ch.islower():
                idx = ord(ch) - ord("a")
                if uppers[idx]:
                    res -= lowers[idx]
                    invalid[idx] = 1
                lowers[idx] = 1
            else:
                idx = ord(ch) - ord("A")
                if not uppers[idx]:
                    res += lowers[idx]
                uppers[idx] = 1
        return res