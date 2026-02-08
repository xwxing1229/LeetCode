# https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

class Solution:
    def minimumDeletions(self, s: str) -> int:
        # Make all "a"s on the left side and all "b"s on the right side.
        tmp = 0
        for ch in s:
            tmp += (ch == "a")
        
        res = tmp
        for ch in s:
            if ch == "b":
                tmp += 1
            else:
                tmp -= 1
            res = min(res, tmp)
        return res