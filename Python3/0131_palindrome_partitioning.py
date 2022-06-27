# https://leetcode.cn/problems/palindrome-partitioning/

class Solution:
    def partition(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: list[list[str]]
        """

        self.res = []
        self.backtrack(s, [], 0)
        return self.res

    def backtrack(self, s, tmp, idx):
        if idx == len(s):
            self.res.append(tmp)
            return

        for length in range(1, len(s)-idx+1):
            substr = s[idx: idx+length]
            if self.isValid(substr):
                self.backtrack(s, tmp+[substr], idx+length)


    def isValid(self, substr):
        i = 0
        j = len(substr) - 1
        while i < j:
            if substr[i] == substr[j]:
                i = i + 1
                j = j - 1
            else:
                return False
        return True
