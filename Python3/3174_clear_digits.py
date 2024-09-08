# https://leetcode.cn/problems/clear-digits/

class Solution:
    def clearDigits(self, s: str) -> str:
        n = len(s)
        deleted = [0 for _ in range(n)]
        for i, ch in enumerate(s):
            if ch.isdigit():
                deleted[i] = 1
                for j in range(i-1, -1, -1):
                    if s[j].isalpha() and deleted[j] == 0:
                        deleted[j] = 1
                        break
        return "".join([s[i] for i in range(n) if deleted[i]==0])