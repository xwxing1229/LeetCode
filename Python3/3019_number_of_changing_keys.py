# https://leetcode.cn/problems/number-of-changing-keys/

class Solution:
    def countKeyChanges(self, s: str) -> int:
        res = 0
        pre = s[0].lower()
        for i in range(1, len(s)):
            cur = s[i].lower()
            if cur != pre:
                res += 1
            pre = cur
        return res
