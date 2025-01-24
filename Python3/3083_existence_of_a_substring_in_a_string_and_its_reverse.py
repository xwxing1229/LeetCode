# https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse/

class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        revs = set()
        for i in range(len(s)-1):
            sub = s[i:i+2]
            revs.add(sub[::-1])
            if sub in revs:
                return True
        return False