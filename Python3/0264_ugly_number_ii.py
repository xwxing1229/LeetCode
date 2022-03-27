# https://leetcode-cn.com/problems/ugly-number-ii/

class Solution:
    def nthUglyNumber(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        
        # Dynamic programming.
        dp = [0 for i in range(n)]
        dp[0] = 1
        
        # Three pointers.
        p2 = 0
        p3 = 0
        p5 = 0
        for i in range(1,n):
            n2 = dp[p2] * 2
            n3 = dp[p3] * 3
            n5 = dp[p5] * 5
            dp[i] = min(n2, n3, n5)
            
            if dp[i] == n2:
                p2 = p2 + 1
            if dp[i] == n3:
                p3 = p3 + 1
            if dp[i] == n5:
                p5 = p5 + 1
        
        return dp[n-1]