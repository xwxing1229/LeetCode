# https://leetcode-cn.com/problems/maximum-length-of-pair-chain/
class Solution:
    def findLongestChain(self, pairs):
        """
        Inputs:
            nums: list[list[int]]
        Outputs:
            res: int
        """

        pairs.sort()
        n = len(pairs)

        dp = [1 for i in range(n)]
        for i in range(1,n):
            tmp = [0]
            for j in range(i):
                if pairs[j][1] < pairs[i][0]:
                    tmp.append(dp[j])
            dp[i] = max(tmp) + 1

        return max(dp)
