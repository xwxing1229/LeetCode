# https://leetcode.cn/problems/ways-to-make-a-fair-array/

class Solution:
    def waysToMakeFair(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        if n == 1:
            return 1
        elif n == 2:
            return 0

        cumsum = [nums[0] for _ in range(n)]
        cumsum[1] = nums[1]
        for i in range(2, n):
            cumsum[i] = cumsum[i-2] + nums[i]
        
        if n % 2 == 0:
            oddsum = cumsum[n-1]
            evensum = cumsum[n-2]
        else:
            oddsum = cumsum[n-2]
            evensum = cumsum[n-1]
            
        res = 0
        if evensum - nums[0] == oddsum:
            res += 1
        if oddsum - nums[1] + nums[0] == evensum - nums[0]:
            res += 1
        for i in range(2, n):
            if i % 2 == 0:
                oddsum_new = cumsum[i-1] + evensum - cumsum[i]
                evensum_new = cumsum[i-2] + oddsum - cumsum[i-1]
            else:
                oddsum_new = cumsum[i-2] + evensum - cumsum[i-1]
                evensum_new = cumsum[i-1] + oddsum - cumsum[i]
            if oddsum_new == evensum_new:
                res += 1
        return res