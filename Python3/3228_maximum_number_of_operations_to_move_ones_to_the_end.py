# https://leetcode.cn/problems/maximum-number-of-operations-to-move-ones-to-the-end/

class Solution:
    def maxOperations(self, s: str) -> int:
        res = 0
        move = 0
        for i in range(len(s)-2, -1, -1):
            if s[i] == "1":
                if s[i+1] == "0":
                    move += 1
                res += move
        return res
