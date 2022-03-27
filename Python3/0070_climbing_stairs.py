# https://leetcode-cn.com/problems/climbing-stairs/

# Let f(n) denote number of ways to climb to the nth stair
# with n = 0,1,....
# Then we have f(n) = f(n-1) + f(n-2).
# Specifically, f(0) = f(1) = 1.

class Solution:
    def climbStairs(self, n:int) -> int:
        res = [1,1]
        for i in range(2,n+1):
            res.append(res[i-1]+res[i-2])
        return res[n]