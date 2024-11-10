# https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/

class Solution:
    def resultsArray(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: list[int]
        """
        if k == 1:
            return nums
        
        n, cnt = len(nums), 1
        for i in range(n-2, n-k, -1):
            if nums[i] + 1 == nums[i+1]:
                cnt += 1
            else:
                cnt = 1

        res = [-1 for _ in range(n-k+1)]
        for i in range(n-k, -1, -1):
            if nums[i] + 1 == nums[i+1]:
                cnt += 1
            else:
                cnt = 1
            
            if cnt >= k:
                res[i] = nums[i+k-1]
        return res