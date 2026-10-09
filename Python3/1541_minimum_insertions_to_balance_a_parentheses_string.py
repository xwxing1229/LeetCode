# https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/

class Solution:
    def minInsertions(self, s: str) -> int:
        res = 0
        cnt = 0
        n, i = len(s), 0
        while i < n:
            if s[i] == "(":
                cnt += 2
                i += 1
                continue

            cnt -= 2
            if i + 1 < n and s[i+1] == ")":
                i += 2
            else:
                res += 1 # insert a ")"
                i += 1
            if cnt < 0:
                res += 1 # insert a "("
                cnt = 0
        res += cnt
        return res