# https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        n = len(nums)
        res = n + 1
        presum = [0 for _ in range(n+1)]
        for i, num in enumerate(nums):
            presum[i+1] = presum[i] + num
            if presum[i+1] == x:
                res = min(res, i+1)
        
        sufsum = 0
        left = n
        for right in range(n-1, -1, -1):
            sufsum += nums[right]
            while left >= 0 and sufsum + presum[left] > x:
                left -= 1
            if left >= 0 and sufsum + presum[left] == x:
                res = min(res, left + n - right)
        return res if res <= n else -1