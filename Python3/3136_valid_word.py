# https://leetcode.cn/problems/valid-word/

class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        special = "@#$"
        vowel = "aeiouAEIOU"
        valid = [False, False]
        for ch in word:
            if ch in special:
                return False
            elif ch.isdigit():
                continue
            elif ch in vowel:
                valid[0] = True
            else:
                valid[1] = True
        return valid[0] & valid[1]