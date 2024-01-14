# https://leetcode.cn/problems/remove-stones-to-minimize-the-total/

class Solution:
    def minStoneSum(self, piles, k):
        """
        Inputs:
            piles: list[int]
            k: int
        Outputs:
            res: int
        """
        pq = []
        for pile in piles:
            heapq.heappush(pq, -pile)
        
        for _ in range(k):
            pile = -heapq.heappop(pq)
            heapq.heappush(pq, -((pile+1)//2))
        return -sum(pq)