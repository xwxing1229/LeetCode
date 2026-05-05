# https://leetcode.cn/problems/minimum-changes-to-make-alternating-binary-string/

class Solution:
    def minOperations(self, s: str) -> int:
        def StartFrom(tar: str) -> int:
            res = 0
            for ch in s:
                res += (ch != tar)
                tar = str(1 - int(tar))
            return res
        
        return min(StartFrom("0"), StartFrom("1"))