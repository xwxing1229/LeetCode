# https://leetcode-cn.com/problems/decode-ways/

class Solution:
    def numDecodings(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        
        if s[0] == '0':
            return 0
        
        n = len(s)
        dp = [1 for _ in range(n+1)]

        for i in range(1,n):
            # 4 conditions.
            tmp = int(s[i-1:i+1])
            if s[i] == '0':
                if tmp > 20 ot tmp == 0:
                    return 0
                else:
                    dp[i] = dp[i-2]
            else:
                if tmp > 26 or tmp < 10:
                    dp[i] = dp[i-1]
                else:
                    dp[i] = dp[i-1] + dp[i-2]
        return dp[-2]