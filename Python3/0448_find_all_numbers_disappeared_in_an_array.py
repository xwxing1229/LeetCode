# https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/

class Solution:
    def findDisappearedNumbers(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        n = len(nums)
        cnt = [0 for _ in range(n)]
        for num in nums:
            cnt[num-1] = 1
        
        res = []
        for i in range(n):
            if cnt[i] == 0:
                res.append(i+1)
        return res