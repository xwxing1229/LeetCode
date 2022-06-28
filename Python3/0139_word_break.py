# https://leetcode.cn/problems/word-break/

class Solution:
    def wordBreak(self, s, wordDict):
        """
        Inputs:
            s: str
            wordDict: list[str]
        Outputs:
            res: bool
        """

        self.res = False
        self.memory = []
        self.backtrack(s, wordDict, 0)
        return self.res

    def backtrack(self, s, wordDict, idx):
        if idx == len(s):
            self.res = True
            return

        for word in wordDict:
            if self.res:
                return

            length = len(word)
            substr = s[0: idx+length]
            if (s[idx: idx+length] == word) and (substr not in self.memory):
                self.memory.append(substr)
                self.backtrack(s, wordDict, idx+length)
