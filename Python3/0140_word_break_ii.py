# https://leetcode.cn/problems/word-break-ii/

class Solution:
    def wordBreak(self, s, wordDict):
        """
        Inputs:
            s: str
            wordDict: list[str]
        Outputs:
            res: list[str]
        """

        self.res = []
        self.backtrack(s, wordDict, [], 0)
        return self.res

    def backtrack(self, s, wordDict, sentence, idx):
        if idx == len(s):
            self.res.append(" ".join(sentence))
            return

        for length in range(1, len(s)+1-idx):
            sub = s[idx: idx+length]
            if sub in wordDict:
                self.backtrack(s, wordDict, sentence+[sub], idx+length)
