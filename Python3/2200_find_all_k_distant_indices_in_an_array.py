# https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/

class Solution:
    def findKDistantIndices(self, nums, key, k):
        """
        Inputs:
            nums: list[int]
            key, k: int
        Outputs:
            list[int]
        """
        res = []
        n = len(nums)
        cnt = 0
        for i in range(min(n, k+1)):
            if nums[i] == key:
                cnt += 1
        if cnt > 0:
            res.append(0)
        for i in range(1, n):
            if i + k < n:
                cnt += (nums[i+k] == key)
            if i - k - 1 >= 0:
                cnt -= (nums[i-k-1] == key)
            if cnt > 0:
                res.append(i)
        return res
    
    
nums = [3,4,9,1,3,9,5]
key = 1
k = 2
print(Solution().findKDistantIndices(nums, key, k))