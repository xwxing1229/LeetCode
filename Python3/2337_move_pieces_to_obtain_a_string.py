# https://leetcode.cn/problems/move-pieces-to-obtain-a-string/

class Solution:
    def canChange(self, start, target):
        """
        Inputs:
            start, target: str
        Outputs:
            res: bool
        """
        i, n = 0, len(start)
        for j, cur in enumerate(target):
            if cur == "L":
                while i < n and start[i] == "_":
                    i += 1
                if i == n or i < j or start[i] == "R":
                    return False
                i += 1
            elif cur == "R":
                while i < n and start[i] == "_":
                    i += 1
                if i == n or i > j or start[i] == "L":
                    return False
                i += 1
        while i < n:
            if start[i] != "_":
                return False
            i += 1
        return True