# https://leetcode.cn/problems/check-distances-between-same-letters/

class Solution:
    def checkDistances(self, s, distance):
        """
        Inputs:
            s: str
            distance: list[int]
        Outputs:
            res: bool
        """
        res = True
        first_appear = [-1 for _ in range(26)]
        for i, ch in enumerate(s):
            idx = ord(ch) - ord("a")
            if first_appear[idx] < 0:
                first_appear[idx] = i
            else:
                if i - first_appear[idx] - 1 != distance[idx]:
                    res = False
                    break
        return res