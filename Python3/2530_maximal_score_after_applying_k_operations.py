# https://leetcode.cn/problems/maximal-score-after-applying-k-operations/

class Solution:
    def maxKelements(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: int
        """
        pq = []
        for num in nums:
            heapq.heappush(pq, -num)
        res = 0
        for i in range(k):
            num = heapq.heappop(pq)
            res -= num
            heapq.heappush(pq, -((-num + 2) // 3))
        return res