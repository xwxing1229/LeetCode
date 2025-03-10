# https://leetcode.cn/problems/the-number-of-beautiful-subsets/

from collections import defaultdict

class Solution:
    def beautifulSubsets(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """    
        def dfs(idx):
            if idx == n:
                nonlocal res
                res += 1
                return
            dfs(idx+1)
            num = nums[idx]
            if cnts[num-k] == 0:
                cnts[num] += 1
                dfs(idx+1)
                cnts[num] -= 1
        
        res, n = -1, len(nums)
        nums.sort()
        cnts = defaultdict(int)
        dfs(0)
        return res