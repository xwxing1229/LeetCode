# https://leetcode.cn/problems/non-decreasing-subsequences/

class Solution:
    def findSubsequences(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """
        self.res = []
        self.nums = nums
        s = set()
        for i, num in enumerate(nums):
            if num not in s:
                s.add(num)
                self.dfs(i+1, [num])
        return self.res
    
    def dfs(self, idx, tmp):
        s = set()
        for i in range(idx, len(self.nums)):
            num = self.nums[i]
            if num in s or num < tmp[-1]:
                continue
            
            s.add(num)
            cur = tmp + [num]
            self.res.append(cur)
            self.dfs(i+1, cur)