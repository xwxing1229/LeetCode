# https://leetcode.cn/problems/maximum-sum-circular-subarray/
import heapq
class Solution:
    def maxSubarraySumCircular(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        n = len(nums)
        cumsum = [0 for _ in range(2*n)]
        for i in range(2*n-1):
            cumsum[i+1] = cumsum[i] + nums[i%n]
        # Make a priority queue pq that save indices and that satisfies
        # cumsum[pq[0]] <= cumsum[pq[k]] for any k in pq.
        pq = []
        for i in range(n):
            heapq.heappush(pq, (cumsum[i], i))
        res = cumsum[n] - cumsum[pq[0][1]]
        for i in range(n, 2*n-1):
            heapq.heappush(pq, (cumsum[i], i))
            while pq[0][1] < i+1-n:
                heapq.heappop(pq)
            res = max(res, cumsum[i+1] - cumsum[pq[0][1]])
        return res

sol = Solution()
nums = [1, -2, 3, -2]
print(sol.maxSubarraySumCircular(nums))