# https://leetcode.cn/problems/ones-and-zeroes/

class Solution:
    def findMaxForm(self, strs, m, n):
        """
        Inputs:
            strs: list[str]
            m: int
            n: int
        Outputs:
            res: int
        """
        cnt0 = [s.count("0") for s in strs]
        record = [[[-1 for _ in range(n+1)] for _ in range(m+1)] for _ in range(len(strs))]

        # dfs(i, j, k): maximum size of subset of strs[0: k+1] that satisfies
        #               number of 0 <= i and number of 1 <= j
        #               0 <= k < len(strs)
        def dfs(i, j, k):
            if k < 0:
                return 0
            if record[k][i][j] >= 0:
                return record[k][i][j]
            res = dfs(i, j, k-1) # subset does not contain strs[k]
            cnt1 = len(strs[k]) - cnt0[k]
            if cnt0[k] <= i and cnt1 <= j:
                res = max(res, dfs(i-cnt0[k], j-cnt1, k-1)+1) # subset contains strs[k]
            record[k][i][j] = res
            return res
        return dfs(m, n, len(strs)-1)