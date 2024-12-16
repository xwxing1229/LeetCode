# https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i/

class Solution:
    def getFinalState(self, nums, k, multiplier):
        """
        Inputs:
            nums: list[int]
            k: int
            multiplier: int
        Outputs:
            res: list[int]
        """
        import heapq

        pq = [(num, i) for i, num in enumerate(nums)]
        heapq.heapify(pq)
        for _ in range(k):
            num, i = heapq.heappop(pq)
            heapq.heappush(pq, (num*multiplier, i))
        res = [0 for _ in range(len(nums))]
        while len(pq) != 0:
            num, i = heapq.heappop(pq)
            res[i] = num
        return res