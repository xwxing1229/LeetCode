# https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

class Solution:
    def minOperations(self, nums, x):
        """
        Inputs:
            nums: list[int]
            x: int
        Outputs:
            res: int
        """
        res = -1
        n = len(nums)
        lsum = [0 for i in range(n+1)]
        for i in range(1, n+1):
            lsum[i] = lsum[i-1] + nums[i-1]
        if lsum[n] < x:
            return res
        
        rsum = 0
        left = n
        for r in range(n-1, -2, -1):
            while left > 0 and lsum[left] + rsum > x:
                left -= 1
            if lsum[left] + rsum == x:
                tmp = left + n - r - 1
                if res < 0 or res > tmp:
                    res = tmp
            
            if r >= 0:
                rsum += nums[r]
        return res