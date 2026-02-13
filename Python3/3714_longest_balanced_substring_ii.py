# https://leetcode.cn/problems/longest-balanced-substring-ii/

class Solution:
    def longestBalanced(self, s: str) -> int:
        # The substring contains characters of one type.
        res = self.longestBalancedOneChar(s)
        
        # The substring contains characters of two type.
        res = max(res, self.longestBalancedTwoChars(s, "a", "b"))
        res = max(res, self.longestBalancedTwoChars(s, "a", "c"))
        res = max(res, self.longestBalancedTwoChars(s, "b", "c"))

        # The substring contains characters of three type.
        res = max(res, self.longestBalancedThreeChars(s))
        
        return res
    
    def longestBalancedOneChar(self, s: str):
        res = 0
        n, left = len(s), 0
        while left < n:
            right = left
            while right < n and s[right] == s[left]:
                right += 1
            res = max(res, right-left)
            left = right
        return res
    
    def longestBalancedTwoChars(self, s: str, ch1: str, ch2: str):
        res = 0
        n, i = len(s), 0
        while i < n:
            diff = 0
            record = {diff: i-1}
            while i < n and (s[i] == ch1 or s[i] == ch2):
                diff += 1 if s[i] == ch1 else -1
                if diff in record:
                    res = max(res, i - record[diff])
                else:
                    record[diff] = i
                i += 1
            i += 1
        return res
    
    def longestBalancedThreeChars(self, s: str):
        res = 0
        record = {(0, 0): -1}
        cnt = {"a": 0, "b": 0, "c": 0}
        for i, ch in enumerate(s):
            cnt[ch] += 1
            diff = (cnt["a"]-cnt["b"], cnt["a"]-cnt["c"])
            if diff in record:
                res = max(res, i - record[diff])
            else:
                record[diff] = i
        return res