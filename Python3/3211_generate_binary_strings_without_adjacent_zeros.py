# https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/

class Solution:
    def validStrings(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[str]
        """
        self.res = []
        self.n = n
        self.dfs(0, "")
        return self.res

    def dfs(self, idx, cur):
        if idx == self.n:
            self.res.append(cur)
            return
        
        if cur == "" or cur[-1] == "1":
            self.dfs(idx+1, cur+"0")
            self.dfs(idx+1, cur+"1")
        else:
            self.dfs(idx+1, cur+"1")