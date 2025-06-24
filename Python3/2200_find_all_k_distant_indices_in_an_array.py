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
        for j, num in enumerate(nums):
            if num == key:
                for i in range(max(0,j-k), min(n, j+k+1)):
                    if len(res) == 0 or i > res[-1]:
                        res.append(i)
        return res
    
    
nums = [3,4,9,1,3,9,5]
key = 1
k = 2
print(Solution().findKDistantIndices(nums, key, k))