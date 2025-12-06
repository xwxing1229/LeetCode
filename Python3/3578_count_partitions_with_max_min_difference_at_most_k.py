# https://leetcode.cn/problems/count-partitions-with-max-min-difference-at-most-k/

import heapq

class Solution:
    def countPartitions(self, nums: list[int], k: int) -> int:
        # dp[i]: number of valid partitions until i (included), dp[0] = 1.
        # dp[i] = dp[left-1] + dp[left] + ... + dp[i-1], where left <= i is the minimum index
        # such that max(nums[left:i+1]) - min(nums[left:i+1]) <= k.
        # As i increases, left either stays the same or increavses.
        mod = 1000000007
        left, n = 0, len(nums)
        dp = [1 for _ in range(n)]
        cumsum = [0 for _ in range(n+1)]
        cumsum[1] = 1
        min_heap, max_heap = [(nums[0],0)], [(-nums[0],0)]
        for i in range(1, n):
            heapq.heappush(min_heap, (nums[i],i))
            heapq.heappush(max_heap, (-nums[i],i))
            while -max_heap[0][0] - min_heap[0][0] > k:
                left += 1
                while min_heap[0][1] < left:
                    heapq.heappop(min_heap)
                while max_heap[0][1] < left:
                    heapq.heappop(max_heap)

            if left == 0:
                dp[i] = cumsum[i] + 1
            else:
                dp[i] = (cumsum[i] - cumsum[left-1] + mod) % mod
            cumsum[i+1] = (cumsum[i] + dp[i]) % mod
            
        return dp[-1]