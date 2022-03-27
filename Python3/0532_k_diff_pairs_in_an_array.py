# https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/

class Solution:
    def findPairs(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        
        nums.sort()
        n = len(nums)
        res = 0
        for i in range(n-1):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            for j in range(i+1,n):
                if nums[j] - nums[i] == k:
                    res = res + 1
                    break
        return res