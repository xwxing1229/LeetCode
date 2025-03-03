# https://leetcode.cn/problems/palindrome-partitioning/

class Solution:
    def partition(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: list[list[str]]
        """

        def dfs(cur, idx):
            if idx == n:
                res.append(cur.copy())
                return
            for i in range(idx, n):
                valid = True
                left, right = idx, i
                while left < right:
                    if s[left] == s[right]:
                        left += 1
                        right -= 1
                    else:
                        valid = False
                        break
                if valid:
                    cur.append(s[idx:i+1])
                    dfs(cur, i+1)
                    cur.pop()

        res = []
        n = len(s)
        dfs([], 0)
        return res