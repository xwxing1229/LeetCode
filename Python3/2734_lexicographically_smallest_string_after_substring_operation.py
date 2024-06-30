# https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/

class Solution:
    def smallestString(self, s: str) -> str:
        i, n = 0, len(s)
        res = [ch for ch in s]
        while i < n and s[i] == "a":
            i += 1
        if i == n:
            res[n-1] = "z"
        else:
            start = i
            i += 1
            while i < n and s[i] != "a":
                i += 1
            for idx in range(start, i):
                res[idx] = chr(ord(s[idx]) -1)
        return "".join(res)