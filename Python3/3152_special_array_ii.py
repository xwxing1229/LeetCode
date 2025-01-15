# https://leetcode.cn/problems/special-array-ii/

class Solution:
    def isArraySpecial(self, nums, queries):
        """
        Inputs:
            nums: list[int]
            queries: list[list[int]]
        Outputs:
            res: list[bool]
        """
        n = len(nums)
        dp = [1 for _ in range(n)]
        pre = nums[0] % 2
        for i in range(1, n):
            cur = nums[i] % 2
            if pre + cur == 1:
                dp[i] = dp[i-1] + 1
            pre = cur

        print(dp)
        
        res = [False for _ in range(len(queries))]
        for i, query in enumerate(queries):
            left, right = query[0], query[1]
            if dp[right] >= right - left + 1:
                res[i] = True
        return res