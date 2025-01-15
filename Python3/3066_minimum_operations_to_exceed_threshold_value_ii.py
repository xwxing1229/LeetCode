# https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-ii/

import heapq

class Solution:
    def minOperations(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        res = 0
        heapq.heapify(nums)
        while nums[0] < k:
            num1 = heapq.heappop(nums)
            num2 = heapq.heappop(nums)
            heapq.heappush(nums, 2*num1+num2)
            res += 1
        return res
    
nums = [2,11,10,1,3]
k = 10

nums = [1,1,2,4,9]
k = 20

print(Solution().minOperations(nums, k))