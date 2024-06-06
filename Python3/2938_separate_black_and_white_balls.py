# https://leetcode.cn/problems/separate-black-and-white-balls/

class Solution:
    def minimumSteps(self, s: str) -> int:
        i, j, n = 0, -1, len(s)
        string = [ch for ch in s]
        res = 0
        while i < n and j < n:
            while i < n and string[i] == "0":
                i += 1
            if j < 0:
                j = i + 1
            while j < n and string[j] == "1":
                j += 1
            if j < n:
                res += j - i
                string[i] = "0"
                string[j] = "1"
            i += 1
            j += 1
        return res