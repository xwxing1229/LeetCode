# https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/

class Solution:
    def halveArray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        pq = []
        for num in nums:
            heapq.heappush(pq, -num)
        res = 0
        half, s = sum(nums)/2, 0
        while s < half:
            cur = -heapq.heappop(pq) / 2
            s += cur
            heapq.heappush(pq, -cur)
            res += 1
        return res