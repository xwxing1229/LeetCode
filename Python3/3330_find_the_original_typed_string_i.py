
# https://leetcode.cn/problems/find-the-original-typed-string-i/

class Solution:
    def possibleStringCount(self, word: str) -> int:
        res = 1
        word += " "
        start = 0
        for i, ch in enumerate(word):
            if ch != word[start]:
                if i - start > 1:
                    res += i - start - 1
                start = i
        return res