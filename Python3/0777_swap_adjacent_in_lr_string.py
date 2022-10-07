# https://leetcode.cn/problems/swap-adjacent-in-lr-string/

class Solution:
    def canTransform(self, start, end):
        """
        Inputs:
            start: str
            end: str
        Outputs:
            res: bool
        """

        res = False
        n = len(start)
        if n != len(end):
            return res

        i, j = 0, 0
        while (i < n) and (j < n):
            while i < n and start[i] == "X":
                i = i + 1
            while j < n and end[j] == "X":
                j = j + 1
            if i == n or j == n:
                break

            if start[i] != end[j]:
                return res
            if start[i] == "L" and i < j:
                return res
            if start[i] == "R" and i > j:
                return res

            i = i + 1
            j = j + 1
        
        if i == n:
            for k in range(j, n):
                if end[k] != "X":
                    return res
        else:
            for k in range(i, n):
                if start[k] != "X":
                    return res
        return True
